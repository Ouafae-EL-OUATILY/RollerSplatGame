
#ifndef __CREDIT_SCENE_H__
#define __CREDIT_SCENE_H__

#include "cocos2d.h"

class Credit : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Credit);


    //Menu 
    void Blank(Ref* pSender);
    void Main(Ref *pSender);
  
    

};

#endif 
