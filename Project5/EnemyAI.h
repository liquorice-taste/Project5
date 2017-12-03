#ifndef PROJECT5_ENEMYAI_H_
#define PROJECT5_ENEMYAI_H_

#include "Components.h"
#include "MovingLogic.h"
#include "Paths.h"

class EnemyAI : public Component {
 private:
  int dif1, dif2;

 public:
  TransformComponent* transform;
  EnemyAI() = default;

  void init() override {
    transform = &entity->getComponent<TransformComponent>();
  }

  Vector2D target;

  void update() override {
    //target = Game::GetDiggerPos();
    
    //if (Path::checkCell(MovingLogic::postocell(transform->position), 1, 0)) 





    /*
    if (transform->position.x < target.x) {


      //printf("%f %f", transform->position.x, transform->position.y);
      //SDL_Delay(100);


      if (Path::checkCell(MovingLogic::postocell(transform->position), 1, 0)) {
      MovingLogic::moveByGrid(transform->position.y, transform->velocity.y, dif1, dif2);
      if ((dif1 == 0) || (dif2 == 0)) {
        
          transform->velocity.x = 1;
          printf("fuck you");
        }
        return;
      }
    }
    if (transform->position.y < target.y) {
      if (Path::checkCell(MovingLogic::postocell(transform->position), 0, 1)) {
      MovingLogic::moveByGrid(transform->position.x, transform->velocity.x, dif1, dif2);
      if ((dif1 == 0) || (dif2 == 0)) {
          transform->velocity.y = 1;
          printf("fuck you");
        }
        return;
      }
    }
    if (transform->position.x > target.x) {
      if (Path::checkCell(MovingLogic::postocell(transform->position), -1 ,0)) {
      MovingLogic::moveByGrid(transform->position.y, transform->velocity.y, dif1, dif2);
      if ((dif1 == 0) || (dif2 == 0)) {
        
          transform->velocity.x = -1;
          printf("fuck you");
        }
        return;
      }
    }
    if (transform->position.y > target.y) {
      if (Path::checkCell(MovingLogic::postocell(transform->position), 0, -1)) {
      MovingLogic::moveByGrid(transform->position.x, transform->velocity.x, dif1, dif2);
      if ((dif1 == 0) || (dif2 == 0)) {
        
          transform->velocity.y = -1;
          printf("fuck you");
        }
        return;
      }
    }
    */
  }

};

#endif  //  PROJECT5_ENEMYAI_H_
