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


  std::vector<Vector2D>* buildPath(Vector2D avec, Vector2D bvec) {  // ����� ���� �� ������ (ax, ay) � ������ (bx, by)
    
    const int WALL = -1;         // ������������ ������
    const int BLANK = -2;         // ��������� ������������ ������

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

    int dx[4] = { 1, 0, -1, 0 };   // ��������, ��������������� ������� ������
    int dy[4] = { 0, 1, 0, -1 };   // ������, �����, ����� � ������
    int d, x, y, k;
    bool stop;
    int len;

    if (tmppathmap[avec.y][avec.x] == WALL || tmppathmap[bvec.y][bvec.x] == WALL) return NULL;
    // ��������������� �����

    d = 0;
    tmppathmap[avec.y][avec.x] = 0;           // ��������� ������ �������� 0

    do {
      stop = true;               // ������������, ��� ��� ��������� ������ ��� ��������
      for (y = 0; y < 10; y++)
        for (x = 0; x < 15; x++)
          if (tmppathmap[y][x] == d) {                   // ������ (x, y) �������� ������ d
            for (k = 0; k < 4; k++) {              // �������� �� ���� ������������ �������
              int iy = y + dy[k], ix = x + dx[k];
              if ((iy >= 0) && (iy < h) && (ix >= 0) && (ix < w) && (tmppathmap[iy][ix] == BLANK)) {
                stop = false;              // ������� ������������ ������
                tmppathmap[iy][ix] = d + 1;      // �������������� �����
              }
            }
          }
      d++;
    } while (!stop && tmppathmap[bvec.y][bvec.x] == BLANK);

    if (tmppathmap[bvec.y][bvec.x] == BLANK) return NULL;  // ���� �� ������ 
                                                           // �������������� ����
    path.clear();

    len = tmppathmap[bvec.y][bvec.x];    // ����� ����������� ���� �� (ax, ay) � (bx, by)
    x = bvec.x;
    y = bvec.y;
    d = len;
    path.resize(len + 1);
    while (d >= 0) {  // ���������� ������ (x, y) � ����
      path[d].x = x;
      path[d].y = y;
      d--;
      for (k = 0; k < 4; ++k) {
        int iy = y + dy[k], ix = x + dx[k];
        if ((iy >= 0) && (iy < h) && (ix >= 0) && (ix < w) && (tmppathmap[iy][ix] == d)) {
          x += dx[k];
          y += dy[k];           // ��������� � ������, ������� �� 1 ����� � ������

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


