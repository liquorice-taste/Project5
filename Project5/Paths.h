#ifndef PROJECT5_PATHS_H_
#define PROJECT5_PATHS_H_

#include <vector>
#include "Vector2D.h"

class Path {
 public:
  Path();
  static std::array <std::array<int, 16>, 11> pathmap;

  static void loadPaths(std::string file);
  /****f* project5.paths/loadPaths
  *  NAME
  *    loadPaths -- Load walking paths from file to 2D vector pathmap[15,10]
  *    of pairs (int, char). (V77)
  *  SYNOPSIS
  *    Path->loadPaths(std::string file)
  *  FUNCTION
  *    Used to insert info into an object of the Path class from file storing
  *    an abstract map of paths depending on a current game level.
  *  INPUTS
  *    file        - std::string with a file's directory
  *  RESULT
  *    Path.pathmap vector stores data about dirt, paths, and other objects'
  *    locations on screen in an abstract form 
  *    (1 - path, 0 - dirt, D - digger, G - gem/emerald, E - enemy, L - gold).
  *  EXAMPLE
  *    //
  *  NOTES
  *    //
  *  BUGS
  *    //
  *  SEE ALSO
  *    //
  ******
  * You can use this space for remarks that should not be included
  * in the documentation.
  */

  static void DrawMap();
  static void SetPathVal(int val, Vector2D num);
  static std::vector<Vector2D>* buildPath(Vector2D avec, Vector2D bvec);
  static void followPath(std::vector<Vector2D>* vec, Vector2D& vel, Vector2D& pos);
};

#endif  //  PROJECT5_PATHS_H_

