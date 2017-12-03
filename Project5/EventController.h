#ifndef PROJECT5_EVENTCONTROLLER_H_
#define PROJECT5_EVENTCONTROLLER_H_

#include "Components.h"
#include "Collision.h"
#include <algorithm>
#include <cmath>
#include <functional>

class EventController : public Component {
 public:
  TransformComponent* transform;
  SpriteComponent* sprite;
  
  EventController() = default;

  void init() override {
    transform = &entity->getComponent<TransformComponent>();
    sprite = &entity->getComponent<SpriteComponent>();
  }

  void update() override {
    
    while (SDL_PollEvent(&Game::Event)) {
      switch (Game::Event.type) {
      case SDL_KEYDOWN:
        OnKeyDown(Game::Event.key.keysym.scancode);
        break;
      case SDL_KEYUP:
        transform->velocity.y = 0;
        transform->velocity.x = 0;
        break;
      case SDL_QUIT:
        Game::running = false;
        break;
      }
    }
  }

  Vector2D y;
  void OnKeyDown(SDL_Scancode code) {
    switch (code) {
    case (SDL_SCANCODE_UP):
      if (!(transform->position.y <= 0)) {
        MovingLogic::moveByGrid(transform->position.x, transform->velocity.x, dif1, dif2);
        if ((dif1 == 0) || (dif2 == 0)) {
          transform->velocity.y = -1;
          y.x = static_cast<int>(static_cast<int>(transform->position.x) / 70);
          y.y = static_cast<int>(static_cast<int>(transform->position.y) / 70);
          Path::SetPathVal(1, y);
          sprite->animation->animationindex = UP;
        }
      }
      break;
    case (SDL_SCANCODE_DOWN):
      if (!(transform->position.y >= GAME_FIELD_HEIGHT)) {
        MovingLogic::moveByGrid(transform->position.x, transform->velocity.x, dif1, dif2);
        if ((dif1 == 0) || (dif2 == 0)) {
          transform->velocity.y = 1;
          y.x = static_cast<int>(static_cast<int>(transform->position.x) / 70);
          y.y = static_cast<int>(static_cast<int>(transform->position.y + 70) / 70);
          Path::SetPathVal(1, y);
          sprite->animation->animationindex = DOWN;
        }
      }
      break;
    case (SDL_SCANCODE_LEFT):
      if (!(transform->position.x <= 5)) {
        MovingLogic::moveByGrid(transform->position.y, transform->velocity.y, dif1, dif2);
        if ((dif1 == 0) || (dif2 == 0)) {
          transform->velocity.x = -1;
          y.x = static_cast<int>(static_cast<int>(transform->position.x) / 70);
          y.y = static_cast<int>(static_cast<int>(transform->position.y) / 70);
          Path::SetPathVal(1, y);
          sprite->animation->animationindex = LEFT;
        }
      }
      break;

    case (SDL_SCANCODE_RIGHT):
      if (!(transform->position.x >= GAME_FIELD_WIDTH)) {
        MovingLogic::moveByGrid(transform->position.y, transform->velocity.y, dif1, dif2);
        if ((dif1 == 0) || (dif2 == 0)) {
          transform->velocity.x = 1;
          y.x = static_cast<int>(static_cast<int>(transform->position.x + 70) / 70);
          y.y = static_cast<int>(static_cast<int>(transform->position.y) / 70);
          Path::SetPathVal(1, y);
          sprite->animation->animationindex = RIGHT;
        }
      }
      break;
    default:
      break;
    }
  }
 private:
  int dif1, dif2;
};

#endif  //  PROJECT5_EVENTCONTROLLER_H_
