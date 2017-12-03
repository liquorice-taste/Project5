#ifndef PROJECT5_TRANSFORMCOMPONENT_H_
#define PROJECT5_TRANSFORMCOMPONENT_H_

#include "Components.h"
#include "Vector2D.h"
#include "Define.h"

class TransformComponent :public Component {
 public:
  Vector2D position;
  Vector2D velocity;

  int speed = 5;
  int scale = 1;
  int height = GAME_OBJ_HEIGHT;  //  GAME_OBJ_HEIGHT;
  int width = GAME_OBJ_WIDTH;  //  GAME_OBJ_WIDTH;


  TransformComponent() {
    position.Zero();
  }

  explicit TransformComponent(const float &x, const float &y) {
    position.x = x;
    position.y = y;
  }

  void init() override {
    velocity.Zero();
  }

  void update() override {
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
    velocity.Zero();
  }
};

#endif  //   PROJECT5_TRANSFORMCOMPONENT_H_
