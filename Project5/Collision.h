#ifndef PROJECT5_COLLISION_H_
#define PROJECT5_COLLISION_H_

#include "SDL.h"
#include "Define.h"
#include "Vector2D.h"

class Collision {
 public:
  static bool CollisionCheck(const SDL_Rect& rect1, const SDL_Rect& rect2);
  static void WallCheck(const SDL_Rect& rect, Vector2D &vec);
};

#endif  //  PROJECT5_COLLISION_H_
