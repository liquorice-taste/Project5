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

class LevelComponent : public Component {
public:
  int lvl, enemynum, maxenemy_onscrnum, enemy_onscrnum;
  Uint32 waitenemytime;  //mseconds
  Uint32 time;
  LevelComponent() = default;

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
    //time = SDL_GetTicks();
  }

  void update() override {
    if ((enemy_onscrnum < maxenemy_onscrnum) && (enemynum != 0)) {
      time++;
      if (time == waitenemytime) {
        //Game::initEnemy(static_cast<float>(14 * 70), static_cast<float>(0 * 70));
        enemy_onscrnum++;
        time = 0;
      }
    }
  }

};

#endif  // PROJECT5_LEVELCOMPONENT_H_
