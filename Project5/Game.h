#ifndef PROJECT5_GAME_H_
#define PROJECT5_GAME_H_

#include <stdio.h>
#include <map>
#include <typeinfo>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "MovingLogic.h"


class Entity;
class CollisionComponent;

class Game {
 private:
  SDL_Window* Window;
  const int FPS = 60;
  const int FrameDelay = 1000 / 60;
  Uint32 FrameStart;
  int FrameTime;

 public:
  Game();

  bool OnInit();

  void OnLoop();

  void OnRender();

  void OnCleanup();

  bool isrunning() { return running; }

  static Vector2D GetDiggerPos();
  static void initDigger(const float &x, const float &y);
  static Entity* initEnemy(const float &x, const float &y);
  static Entity* initGem(const float &x, const float &y);
  static void Game::callE(int x, int y);
  static void Game::callG(const float &x, const float &y);

  static std::vector<CollisionComponent*> colliderlist;
  static bool running;
  static SDL_Renderer* Renderer;
  static SDL_Event Event;
  int OnExecute();
};

#endif  //  PROJECT5_GAME_H_
