
#ifndef __LEVEL3_SCENE_H__
#define __LEVEL3_SCENE_H__

#include "cocos2d.h"

class Level3 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Level3);
    cocos2d::Label* mylabel;
    cocos2d::Sprite* mySprite;
    void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
  
};

#endif // __LEVEL3_SCENE_H__
