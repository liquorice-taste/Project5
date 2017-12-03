#ifndef PROJECT5_SCORESCOMPONENT_H_
#define PROJECT5_SCORESCOMPONENT_H_

#include "Components.h"
#include <string>
class ScoreComponent : public Component{
 public:
  SDL_Texture* numb;
  SDL_Texture* lett;
  SDL_Rect src, dest;
  int score, lives, digit;

  ScoreComponent() {
    numb = TextureManager::LoadTexture("../Images/NUMBERS.BMP");
    lett = TextureManager::LoadTexture("../Images/LETTERS.BMP");
    score = 0;
    lives = 3;
  }

  void update() override {
  }

  Vector2D vec;
  std::string let;

  void draw() override {
    int scorebuf = score;
    int i = 4;
    do {
      digit = scorebuf % 10;
      scorebuf /= 10;
      src.x = digit * 24;
      src.y = 0;
      dest.y = 8;
      dest.x = 50 * i + 250;
      src.h = src.w = 24;
      dest.h = dest.w  = 50;
      TextureManager::DrawTexture(numb, src, dest);
      i--;
    } while (scorebuf > 0);

    i = lives;
    do {
      src.x = 10 * 24;
      src.y = 0;
      dest.y = 8;
      dest.x =  GAME_FIELD_WIDTH - 50 * i - 30;
      src.h = src.w = 24;
      dest.h = dest.w = 50;
      TextureManager::DrawTexture(numb, src, dest);
      i--;
    } while (i > 0);


    
    vec.x = 8;
    vec.y = 8;
    let = "SCORE";
    TextureManager::DrawWord(let, vec, lett);

    vec.x = 550;
    vec.y = 8;
    let = "LIVES";
    TextureManager::DrawWord(let, vec, lett);

  }



};

#endif  //  PROJECT5_SCORESCOMPONENT_H_
