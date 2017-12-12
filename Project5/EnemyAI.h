/*

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
  
  int timer = 14;
  std::vector<Vector2D>* hui;
  void update() override {
    hui = Path::buildPath(transform->position, Game::GetDiggerPos());
    Path::followPath(hui, transform->velocity, transform->position);
  }
};

#endif  //  PROJECT5_ENEMYAI_H_
*/




#ifndef PROJECT5_ENEMYAI_H_
#define PROJECT5_ENEMYAI_H_

#include "Components.h"
#include "MovingLogic.h"
#include "Paths.h"

class EnemyAI : public Component {
private:
  int dif1, dif2;
  std::vector<Vector2D> path;
  std::array<std::array<int, 16>, 11> tmppathmap;
  int time = 0, const ktimer = 14;
public:
  TransformComponent* transform;
  EnemyAI() = default;


  void init() override {
    transform = &entity->getComponent<TransformComponent>();
  }


  void update() override {
    if (time == 0) {
      buildPath(transform->position, Game::GetDiggerPos());
    }
    time++;
    if (time == ktimer) time = 0;                         //with the help of the time shit we make sure that we load our 
    followPath(transform->velocity, transform->position);    //path only every 14th time so that we don't reload it too much
  }


  std::vector<Vector2D>* buildPath(Vector2D avec, Vector2D bvec) {  // поиск пути из €чейки (ax, ay) в €чейку (bx, by)
    
    const int WALL = -1;         // непроходима€ €чейка
    const int BLANK = -2;         // свободна€ непомеченна€ €чейка

    const int h = 11;
    const int w = 16;

    avec.x = static_cast<int>(static_cast<int>(avec.x) / 70);
    avec.y = static_cast<int>(static_cast<int>(avec.y) / 70);
    bvec.x = static_cast<int>(static_cast<int>(bvec.x) / 70);
    bvec.y = static_cast<int>(static_cast<int>(bvec.y) / 70);

    for (int i = 0; i < Path::pathmap.size(); i++) {
      for (int j = 0; j < Path::pathmap[i].size(); j++) {
        if (Path::pathmap[i][j] == 0) tmppathmap[i][j] = WALL;
        if (Path::pathmap[i][j] == 1) tmppathmap[i][j] = BLANK;
      }
    }

    int dx[4] = { 1, 0, -1, 0 };   // смещени€, соответствующие сосед€м €чейки
    int dy[4] = { 0, 1, 0, -1 };   // справа, снизу, слева и сверху
    int d, x, y, k;
    bool stop;
    int len;

    if (tmppathmap[avec.y][avec.x] == WALL || tmppathmap[bvec.y][bvec.x] == WALL) return NULL;
    // распространение волны

    d = 0;
    tmppathmap[avec.y][avec.x] = 0;           // стартова€ €чейка помечена 0

    do {
      stop = true;               // предполагаем, что все свободные клетки уже помечены
      for (y = 0; y < 10; y++)
        for (x = 0; x < 15; x++)
          if (tmppathmap[y][x] == d) {                   // €чейка (x, y) помечена числом d
            for (k = 0; k < 4; k++) {              // проходим по всем непомеченным сосед€м
              int iy = y + dy[k], ix = x + dx[k];
              if ((iy >= 0) && (iy < h) && (ix >= 0) && (ix < w) && (tmppathmap[iy][ix] == BLANK)) {
                stop = false;              // найдены непомеченные клетки
                tmppathmap[iy][ix] = d + 1;      // распростран€ем волну
              }
            }
          }
      d++;
    } while (!stop && tmppathmap[bvec.y][bvec.x] == BLANK);

    if (tmppathmap[bvec.y][bvec.x] == BLANK) return NULL;  // путь не найден 
                                                           // восстановление пути
    path.clear();

    len = tmppathmap[bvec.y][bvec.x];    // длина кратчайшего пути из (ax, ay) в (bx, by)
    x = bvec.x;
    y = bvec.y;
    d = len;
    path.resize(len + 1);
    while (d >= 0) {  // записываем €чейку (x, y) в путь
      path[d].x = x;
      path[d].y = y;
      d--;
      for (k = 0; k < 4; ++k) {
        int iy = y + dy[k], ix = x + dx[k];
        if ((iy >= 0) && (iy < h) && (ix >= 0) && (ix < w) && (tmppathmap[iy][ix] == d)) {
          x += dx[k];
          y += dy[k];           // переходим в €чейку, котора€ на 1 ближе к старту

          break;
        }
      }
    }

    for (int i = 0; i < path.size() - 1; i++) {
      path[i].x = path[i + 1].x - path[i].x;
      path[i].y = path[i + 1].y - path[i].y;
    }
    return &path;
  }

  int count = 0;
  void followPath(Vector2D& vel, Vector2D& pos) {
    vel.x = path[0].x;
    vel.y = path[0].y;
  }
};

#endif  //  PROJECT5_ENEMYAI_H_


