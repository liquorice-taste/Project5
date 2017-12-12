/* "Copyright 2017 <Caroline Gafiullova>" */

#include "Game.h"
#include "Define.h"
#include "Collision.h"
#include "Paths.h"
#include <vector>
#include "Components.h"

/*

//s = std::to_string(col); (from int to string)

WAY TO CHANGE COLOR OF THE SCREEN AT THE BONUS MODE
SDL_SetRenderTarget(r, destiny);
SDL_SetBlendMod(r, SDL_BLENDMODE_NONE);
SDL_RenderCopy(r, source, destiny);
SDL_SetBlendMod(r, SDL_BLENDMODE_BLEND);
for( Each mask as m){ 
SDL_SetColorMod(m, c[i].r, c[i].g, c[i].b);
SDL_RenderCopy(r, source, destiny);
}
*/



/*TODO: 
  ANIMATION CONTROLLER +++
  MAP LOADING FROM FILE +++
  COLLISION (AABB) +++
  ENEMIES LOGIC +++

  Code improvemet::
  Copyable and Movable Types
*/

SDL_Renderer* Game::Renderer = nullptr;
Manager manager;
SDL_Event Game::Event;
bool Game::running;
Path* pathmap = NULL;
std::vector<CollisionComponent*> Game::colliderlist;

auto& player(manager.addEntity());
auto& gem(manager.addEntity());
auto& enemy(manager.addEntity());

enum GroupLabels : std::size_t {
  groupGems,
  groupEnemies
};

auto& enemies(manager.GetGroup(groupEnemies));
auto& gems(manager.GetGroup(groupGems));

Game::Game() {
  Window = NULL;
  Game::Renderer = NULL;
  Game::running = true;
}

int Game::OnExecute() {
  if (!OnInit()) { return 1;
  }  else  {
    while (running)  {
      FrameStart = SDL_GetTicks();

      OnLoop();
      OnRender();

      FrameTime = SDL_GetTicks() - FrameStart;

      if (FrameDelay > FrameTime) {
        SDL_Delay(FrameDelay - FrameTime);
      }
    }
    OnCleanup();
    return 0;
  }
}

bool Game::OnInit() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << "SDL could not be initialized" << SDL_GetError << std::endl;
    return false;
  }  else  {
    Window = SDL_CreateWindow("DIGGER", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GAME_FIELD_WIDTH, SCREEN_HEIGHT, NULL);  // SDL_WINDOW_FULLSCREEN_DESKTOP
    
    if (Window == NULL)	 {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
      return false;
    } else {
      Game::Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
      if (Game::Renderer) {
        SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 0);
      }
    }

    pathmap = new Path();
    player.addComponent<LevelManager>();
    pathmap->loadPaths(player.getComponent<LevelManager>().getlvlfilename());

    Game::initEnemy(140, 0)->addGroup(groupEnemies);
    Game::initGem(0, 70)->addGroup(groupGems);

    //gem.addGroup(groupGems);
    //enemy.addGroup(groupEnemies);
  }
  return true;
}

Vector2D Game::GetDiggerPos() {
  return player.getComponent<TransformComponent>().position;
}

void Game::initDigger(const float &x, const float &y) {
  player.addComponent<TransformComponent>(x, y);
  player.addComponent<SpriteComponent>("../Images/DIGGER.BMP", 6, DOWN);
  player.addComponent<EventController>();
  player.addComponent<CollisionComponent>("digger");
  player.addComponent<ScoreComponent>();
}

void Game::callE(int x, int y) {
  Game::initEnemy(float(x), float(y))->addGroup(groupEnemies);
}

void Game::callG(const float &x, const float &y) {
  Game::initGem(x, y)->addGroup(groupGems);
}


Entity* Game::initEnemy(const float &x, const float &y) {
  auto& enemy(manager.addEntity());
  enemy.addComponent<TransformComponent>(x, y);
  enemy.addComponent<SpriteComponent>("../Images/NOBBIN.BMP", 3, LEFT);
  enemy.addComponent<CollisionComponent>("enemy");
  enemy.addComponent<EnemyAI>();
  //manager.AddToGroup(&enemy, groupEnemies);
  return &enemy;
}

Entity* Game::initGem(const float &x, const float &y) {
  auto& gem(manager.addEntity());
  gem.addComponent<TransformComponent>(x, y);
  gem.addComponent<SpriteComponent>("../Images/VEMERALD.BMP", 1, LEFT);
  gem.addComponent<CollisionComponent>("gem");
  //manager.AddToGroup(&gem, groupGems);
  return &gem;
}

void Game::OnLoop() {
  manager.refresh();
  manager.update();
  
  //for (auto *f : manager.GetGroup(groupEnemies)) {
  //  &f->destroy;
  //}
  //NEED TO FIND ANOTHER WAY OF COPING WITH DELETING ALL ENEMIES
  /*
  for (auto *cc : colliderlist)
  {
    if (player.getComponent<CollisionComponent>().tag_ != cc->tag_)
    {
      if (Collision::CollisionCheck(player.getComponent<CollisionComponent>().collider_, cc->collider_)) {
        if (cc->tag_ == "gem") {
          player.getComponent<ScoreComponent>().score += 25;
          cc->entity->destroy();
          continue;
        }
        if (cc->tag_ == "enemy") {
          player.getComponent<ScoreComponent>().lives -= 1;
          cc->entity->destroy();
          continue;
        }
      }
    }
  }*/
}

void Game::OnRender() {

  SDL_RenderClear(Game::Renderer);
  pathmap->DrawMap();
  player.draw();
  //&player.getComponent<TransformComponent>().velocity.Zero();
  for (auto& g : enemies) {
    g->draw();
  }

  for (auto& g : gems) {
    g->draw();
  }
  SDL_RenderPresent(Game::Renderer);
}

void Game::OnCleanup() {
  SDL_DestroyWindow(Window);
  Window = NULL;

  SDL_DestroyRenderer(Game::Renderer);
  Game::Renderer = NULL;

  IMG_Quit();
  SDL_Quit();
}


int main(int argc, char* argv[]) {
  Game *theDigger = new Game();
  return theDigger->OnExecute();
}
