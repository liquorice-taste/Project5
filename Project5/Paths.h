#ifndef PROJECT5_PATHS_H_
#define PROJECT5_PATHS_H_

#include <vector>
#include "Vector2D.h"

class Path {
 public:
  Path();

  static void loadPaths(const char* file);
  static int choosePath(Vector2D startpos, Vector2D targetpos);
  static bool checkCell(Vector2D vec, int x, int y);
  static void DrawMap();
  static void SetPathVal(int val, Vector2D num);
};

#endif  //  PROJECT5_PATHS_H_

