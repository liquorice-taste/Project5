#include "MovingLogic.h"

void MovingLogic::moveByGrid(const float &pos, float &vel, int &one, int &two) {
  one = abs(static_cast<int>(pos) - static_cast<int>(static_cast<int>(pos + 70) / 70) * 70);       // calculatin' difference between object's X1 and closest cell's X
  two = abs(static_cast<int>(pos) + 70 - static_cast<int>(static_cast<int>(pos + 70) / 70) * 70);  // calculatin' difference between object's X2 and closest cell's X
  if ((one == 0) || (two == 0)) return;
  if ((one < two) || (one == two)) vel = 1;
  if (one == two) return;
  if (one > two) vel = -1;
}

Vector2D MovingLogic::postocell(Vector2D vec) {
  vec.x = static_cast<int>(static_cast<int>(vec.x) / 70);
  vec.y = static_cast<int>(static_cast<int>(vec.y) / 70);
  return vec;
}



