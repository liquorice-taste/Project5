#ifndef PROJECT5_SPRITECOMPONENT_H_
#define PROJECT5_SPRITECOMPONENT_H_

#include "Components.h"
#include "SDL.h"
#include "TextureManager.h"

class SpriteComponent : public Component {
 private:
  TransformComponent *transform;
  SDL_Texture *Tex;
  SDL_Rect srcRect, destRect;

  bool isAnimated;

  struct Animation {
    int frames;
    int speed;
    int animationindex;

    Animation(int nf, int anind) {
     animationindex = anind;
     frames = nf;
     speed = 100;
    }
  };

 public:
  SpriteComponent() = default;
  Animation* animation = NULL;

  explicit SpriteComponent(const char* file, const int &nfr, const int &anind) {
    isAnimated = true;
    animation = new Animation(nfr, anind);
    setTexture(file);
  }

  void setTexture(const char* file) {
    Tex = TextureManager::LoadTexture(file);
  }

  void init() override {
    transform = &entity->getComponent<TransformComponent>();

    srcRect.x = srcRect.y = 0;
    srcRect.h = transform->height;
    srcRect.w = transform->width;
  }

  void update() override {
    if (isAnimated) {
      srcRect.w = 32;
      srcRect.h = 30;
      srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / animation->speed) % animation->frames);
      srcRect.y = animation->animationindex * 30;
    }

    destRect.x = static_cast<int>(transform->position.x) ;
    destRect.y = static_cast<int>(transform->position.y) + INFO_FIELD_HEIGHT;

    destRect.h = transform->height * transform->scale;
    destRect.w = transform->width * transform->scale;
  }

  void draw() override {
    TextureManager::DrawTexture(Tex, srcRect, destRect);
  }
};

#endif  //  PROJECT5_SPRITECOMPONENT_H_
