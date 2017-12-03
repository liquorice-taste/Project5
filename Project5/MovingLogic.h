#ifndef PROJECT5_MOVINGLOGIC_H_
#define PROJECT5_MOVINGLOGIC_H_

#include <cmath>
#include "Vector2D.h"

class MovingLogic {
 public:
  static void moveByGrid(const float &pos, float &vel, int &one, int &two);
  static Vector2D postocell(Vector2D vec);
};

#endif  //  PROJECT5_MOVINGLOGIC_H_




