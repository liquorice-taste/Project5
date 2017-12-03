#ifndef PROJECT5_COLLISIONCOMPONENT_H_
#define PROJECT5_COLLISIONCOMPONENT_H_

#include "Components.h"
#include <string>

class CollisionComponent : public Component {
 public:
  TransformComponent* transform;

  SDL_Rect collider_;
  const char* tag_;

  explicit CollisionComponent(const char* t) {
    tag_ = t;
  }

  void init() override {
    if (!entity->hasComponent<TransformComponent>()) {
      entity->addComponent<TransformComponent>();
    }
    transform = &entity->getComponent<TransformComponent>();

    Game::colliderlist.push_back(this);
  }


  void update() override {
    collider_.x = static_cast<int>(transform->position.x);
    collider_.y = static_cast<int>(transform->position.y);
    collider_.h = transform->width * transform->scale;
    collider_.w = transform->height * transform->scale;
  }
};

#endif  //  PROJECT5_COLLISIONCOMPONENT_H_
