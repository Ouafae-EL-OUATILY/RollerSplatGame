
#ifndef __LEVEL2_SCENE_H__
#define __LEVEL2_SCENE_H__

#include "cocos2d.h"

class Level2: public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Level2);
    cocos2d::Label* mylabel;
    cocos2d::Sprite* mySprite;
    void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void nextLevel(Ref* pSender);

    

};

#endif // __LEVEL2_SCENE_H__
