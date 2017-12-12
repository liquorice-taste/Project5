#ifndef PROJECT5_LEVELCOMPONENT_H_
#define PROJECT5_LEVELCOMPONENT_H_

/*
The player scores 25 points for collecting an emerald, 
with a bonus of 250 if eight are collected in immediate
succession. Killing a monster by shooting it or dropping
a gold bag on it scores 250 points; in bonus mode, the player 
scores 200 points for the first monster eaten, 400 for the 
second, and so on, doubling each time. Collecting gold earns 
500 points, and entering bonus mode 1,000. A new life is awarded
at each multiple of 20,000 points.

1lvl == 6 monsters;
2lvl == 7 monsters;
3lvl == 9 monsters;
4lvl == 10 monsters;
*/

#include "Components.h"

class LevelManager : public Component {
private:
  ScoreComponent* score;
  TransformComponent* transform;
public:
  int lvl, enemynum, maxenemy_onscrnum, enemy_onscrnum;
  Uint32 waitenemytime;  //mseconds
  Uint32 time;
  LevelManager() = default;

  void init() override {
    lvl = 1;
    enemynum = lvl + 5;

    if (lvl = 1) {
      maxenemy_onscrnum = 3;
    }
    else if (lvl <= 7) {
      maxenemy_onscrnum = 4;
    }
    else {
      maxenemy_onscrnum = 5;
    }
    time = 0;
    waitenemytime = 200;
    enemy_onscrnum = 0;

    score = &entity->getComponent<ScoreComponent>();
    transform = &entity->getComponent<TransformComponent>();
  }

  std::string s, f;
  std::string getlvlfilename() {
    s = std::to_string(lvl);
    f = "../levels/lvl" + s + ".txt";
      return f; 
  }

  void update() override {
    if ((enemy_onscrnum <= maxenemy_onscrnum) && (enemynum != 0)) {
      time++;
      if (time == waitenemytime) {
        Game::callE(70, 0);
        enemy_onscrnum++;
        time = 0;
      }
    }

    for (auto *cc : Game::colliderlist) {
      if (entity->getComponent<CollisionComponent>().tag_ != cc->tag_) {
        if (Collision::CollisionCheck(entity->getComponent<CollisionComponent>().collider_, cc->collider_)) {
          if (cc->tag_ == "gem") {
            entity->getComponent<ScoreComponent>().score += 25;
            cc->entity->destroy();
            continue;
          }
          if (cc->tag_ == "enemy") {
            //player.getComponent<ScoreComponent>().lives -= 1;
            //cc->entity->destroy();
            diggerdie();
            continue;
          }
        }
      }
    }


  }

  void diggerdie() {
    SDL_Delay(2000);
    transform->position.x = 420;
    transform->position.y = 700;
    score->lives -= 1;
  }

};

#endif  // PROJECT5_LEVELCOMPONENT_H_

