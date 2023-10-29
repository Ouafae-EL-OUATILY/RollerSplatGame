
#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"
#include "AudioEngine.h"

class MainMenu: public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
  
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);


   
    cocos2d::Sprite* background; // background image

    //Menu Methods
    void Play(Ref *pSender);
    void Credits(Ref *pSender);
    void Exit(Ref* pSender);

};

#endif // __MAINMENU_SCENE_H__