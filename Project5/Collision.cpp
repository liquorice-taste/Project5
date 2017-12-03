#include "Collision.h"
#include <iostream>
// Axis-Aligned Bounding Box

bool Collision::CollisionCheck(const SDL_Rect& rect1, const SDL_Rect& rect2) {
  if ((rect1.x + rect1.w >= rect2.x) && (rect2.x + rect2.w >= rect1.x) && (rect2.y + rect2.h >= rect1.y) && (rect1.y + rect1.h >= rect2.y)) {
    return true;
  }

  return false;
}

void Collision::WallCheck(const SDL_Rect& rect, Vector2D &vec) {
  // if ((rect.x == 0) || (rect.x == GAME_FIELD_WIDTH) || (rect.y == INFO_FIELD_HEIGHT) || (rect.y == GAME_FIELD_HEIGHT))
  if (rect.x == 0) vec.x = 0;
  if (rect.x == GAME_FIELD_WIDTH) vec.x = 0;
  if (rect.y == INFO_FIELD_HEIGHT) vec.y = 0;
  if (rect.y == GAME_FIELD_HEIGHT) vec.y = 0;
  return;
}
