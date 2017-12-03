#include "Paths.h"
#include "Define.h"
#include "Game.h"
#include "TextureManager.h"
#include "SDL.h"
#include <fstream>
#include <utility>
#include <vector>
#include <string>

std::vector <std::vector<std::pair<int, char>>> pathmap;
std::vector <std::vector<int>> Apathmap;
SDL_Texture* dirt;
SDL_Texture* diggeddirt;

Path::Path() {
  pathmap = {};
  dirt = TextureManager::LoadTexture("../Images/dirt1.bmp");
  diggeddirt = TextureManager::LoadTexture("../Images/dirt.bmp");
}

/*
//targetpos = Game::GetDiggerPos();
void buildpathmap(Vector2D startpos, Vector2D targetpos) {
  
  targetpos.x = static_cast<int>(static_cast<int>(targetpos.x + 70) / 70);   // converting x & y to cellish coords
  targetpos.x = static_cast<int>(static_cast<int>(targetpos.y + 70) / 70);

  startpos.x = static_cast<int>(static_cast<int>(startpos.x + 70) / 70);   // converting x & y to cellish coords
  startpos.x = static_cast<int>(static_cast<int>(startpos.y + 70) / 70);



}
*/

void Path::SetPathVal(int val, Vector2D num) {
  pathmap.at(num.y).at(num.x).first = val;
}

bool Path::checkCell(Vector2D vec, int x, int y) {
  if (pathmap.at(vec.x + x).at(vec.y + y).first == 1) {
    printf("%f %f", vec.x + x, vec.y + y);
    return true;
  } else { return false; }
}



void Path::loadPaths(const char* file) {
  char i;
  const char* tag = NULL;
  std::string s;
  pathmap.resize(11);
  std::fstream pathf;
  pathf.open(file);
  if (pathf.is_open()) {
    for (int row = 0; row <= 10; row++) {
      pathmap[row].resize(16);
      for (int col = 0; col <= 15; col++) {
        pathf.get(i);
        switch (i) {
        case '0':
          pathmap.at(row).at(col).first = 0;
          break;
        case '1':
          pathmap.at(row).at(col).first = 1;
          break;
        case 'D':
          pathmap.at(row).at(col).first = 1;
          pathmap.at(row).at(col).second = 'D';
          Game::initDigger(static_cast<float>(col*70), static_cast<float>(row*70));
          break;
        case 'E':
          pathmap.at(row).at(col).first = 1;
          pathmap.at(row).at(col).second = 'E';
          //Game::initEnemy(static_cast<float>(col * 70), static_cast<float>(row * 70));
          break;
        case 'G':
          pathmap.at(row).at(col).first = 0;
          pathmap.at(row).at(col).second = 'G';

          Game::initGem(static_cast<float>(col * 70), static_cast<float>(row * 70));
          break;
        default:
          break;
        }
      }
    }
  }
  pathf.close();
}

int Path::choosePath(Vector2D startpos, Vector2D targetpos) {
  int startx = static_cast<int>(static_cast<int>(startpos.x + 70) / 70);
  int starty = static_cast<int>(static_cast<int>(startpos.y + 70) / 70);
  if (pathmap.at(startx - 1).at(starty).first == 1) {
    return 1;
  }
  if (pathmap.at(startx + 1).at(starty).first == 1) {
    return 3;
  }
  if (pathmap.at(startx).at(starty - 1).first == 1) {
    return 2;
  }
  if (pathmap.at(startx).at(starty + 1).first == 1) {
    return 4;
  }
}


SDL_Rect scr, dest;
int u, j = 0;

void Path::DrawMap() {
  for (const auto &row : pathmap) {
    for (const auto &s : row) {
      int i = s.first;
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
