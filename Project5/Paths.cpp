#include "Paths.h"
#include "Define.h"
#include "Game.h"
#include "TextureManager.h"
#include "SDL.h"
#include <fstream>
#include <utility>
#include <vector>
#include <array>
#include <string>
#include <algorithm>

std::array <std::array<int, 16>, 11> Path::pathmap;

SDL_Texture* dirt;
SDL_Texture* diggeddirt;

Path::Path() {
  pathmap = {};
  dirt = TextureManager::LoadTexture("../Images/dirt1.bmp");
  diggeddirt = TextureManager::LoadTexture("../Images/dirt.bmp");
}


void Path::SetPathVal(int val, Vector2D num) {
  pathmap[num.y][num.x] = val;
}

void Path::loadPaths(std::string file) {
  char i;
  const char* tag = NULL;
  std::string s;
  std::fstream pathf;
  pathf.open(file);
  if (pathf.is_open()) {
    for (int row = 0; row <= 10; row++) { 
      for (int col = 0; col <= 15; col++) { 
        pathf.get(i);
        switch (i) {
        case '0':
          pathmap[row][col] = 0;
          break;
        case '1':
          pathmap[row][col] = 1;
          break;
        case 'D':
          pathmap[row][col] = 1;
          Game::initDigger(static_cast<float>(col*70), static_cast<float>(row*70));
          break;
        case 'E':
          pathmap[row][col] = 1;
          //Game::callE(static_cast<float>(col * 70), static_cast<float>(row * 70));
          break;
        case 'G':
          pathmap[row][col] = 0;
          Game::callG(static_cast<float>(col * 70), static_cast<float>(row * 70));
          break;
        default:
          break;
        }
      }
    }
  }
  
  pathf.close();
}

SDL_Rect scr, dest;
int u, j = 0;

void Path::DrawMap() {
  for (const auto &row : pathmap) {
    for (const auto &s : row) {
      int i = s;
      switch (i) {
      case 0:
        dest.x = u * GAME_OBJ_WIDTH;
        dest.y = j * GAME_OBJ_HEIGHT + INFO_FIELD_HEIGHT;
        dest.h = dest.w = GAME_OBJ_WIDTH;

        scr.x = scr.y = 0;
        scr.h = scr.w = GAME_OBJ_WIDTH;
        TextureManager::DrawTexture(dirt, scr, dest);
        break;
      case 1:
        dest.x = u * GAME_OBJ_WIDTH;
        dest.y = j * GAME_OBJ_HEIGHT + INFO_FIELD_HEIGHT;
        dest.h = dest.w = GAME_OBJ_WIDTH;

        scr.x = scr.y = 0;
        scr.h = scr.w = GAME_OBJ_WIDTH;
        TextureManager::DrawTexture(diggeddirt, scr, dest);
        break;
      }
      u++;
    }
    j++;
    u = 0;
  }
  u = j = 0;
}

std::vector<Vector2D> path;
std::array<std::array<int, 15>, 10> tmppathmap;
