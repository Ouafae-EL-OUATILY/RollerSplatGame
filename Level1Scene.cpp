
#include "Level1Scene.h"
#include "Level2Scene.h"
#include "cocos2d.h"

USING_NS_CC;

 Scene* Level1::createScene()
{
    return Level1::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Level1::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
   
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // Exit button
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(Level1::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto CloseMenu = Menu::create(closeItem, NULL);
 
    CloseMenu->setPosition(Vec2::ZERO);
    this->addChild(CloseMenu, 1);

    // Next level button
    auto nextImg = MenuItemImage::create( "next.png","next.png", CC_CALLBACK_1(Level1::nextLevel, this));

    if (nextImg == nullptr ||
        nextImg->getContentSize().width <= 0 ||
        nextImg->getContentSize().height <= 0)
    {
        problemLoading("'Next.png' and 'Next.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - nextImg->getContentSize().width / 2;
        float y = origin.y + nextImg->getContentSize().height / 2;
        nextImg->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto nextMenu = Menu::create(nextImg, NULL);
    nextMenu->setScale(0.1);
    nextMenu->setPosition(Vec2(600,0));
    this->addChild(nextMenu, 1);
    
    // Label
    auto myLabel = Label::createWithTTF("LEVEL 1", "fonts/MarkerFelt.ttf", 50);
    myLabel->setTextColor(Color4B::MAGENTA);
    myLabel->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + 280));
    this->addChild(myLabel);

    TintTo* makeNextInvisible = TintTo::create(0, 0, 0, 0);
    nextMenu->runAction(makeNextInvisible);


  
    // Ball
    auto mySprite = Sprite::create("ball.png");
    mySprite->setPosition(Point((visibleSize.width / 2) + 223, (visibleSize.height / 2) - 222));
    //Level 1 map
    auto level1 = Sprite::create("level1.png"); 
    level1->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    level1->setScale(0.9f);
    // Sprite Path 1
    auto road1 = Sprite::create("road1.png");
    road1->setPosition(Point((visibleSize.width / 2) - 223, (visibleSize.height / 2) + origin.y));
    road1->setScale(0.9f);
    this->addChild(road1);
    // Sprite Path 2
    auto road2 = Sprite::create("road3.png");
    road2->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) -223));
    road2->setScale(0.9f);
    this->addChild(road2);

     this->addChild(level1);
     mySprite->setScale(0.58f);
     TintTo* red = TintTo::create(0, 255, 0, 0);
     this->addChild(mySprite);
     // Change Sprite Color to Red
     mySprite->runAction(red);
    
   

        // Creating a keyboard event listener
        auto eventListener = EventListenerKeyboard::create();
        // Lambda Function
        eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        // Movements
        auto moveUp = MoveBy::create(0.2, Vec2(0, 444)); 
        auto moveDown = MoveBy::create(0.2, Vec2(0, -444));
        auto moveRight = MoveBy::create(0.2, Vec2(445, 0));
        auto moveLeft = MoveBy::create(0.2, Vec2(-445, 0)); 
        
        TintTo* makeNextVisible = TintTo::create(2, 90, 255, 90);

        // Object to change color of the Sprite Road
        TintTo* changeColor = TintTo::create(0.5, 0, 0, 0);

        // Fire Works Animation
        auto emitter = ParticleFireworks::create();
        auto emitter2 = ParticleFireworks::create();
        // Set Position of Fire Work Animation
        emitter->setPosition(Point((visibleSize.width / 2) + 237, (visibleSize.height / 2) + 384));
        emitter2->setPosition(Point((visibleSize.width / 2) - 237, (visibleSize.height / 2) + 384));
        emitter->setRotation(180);
        emitter2->setRotation(180);
        emitter->setScale(1.5);
        emitter2->setScale(1.5);
       

        // Keyboard Event Switch Case
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            if (mySprite->getPositionX() != 906) { break; }
            else { mySprite->runAction(moveLeft); }
                  road2->runAction(changeColor);
            break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case EventKeyboard::KeyCode::KEY_D:
                if (mySprite->getPositionX() != 461) { break; }
                if (mySprite->getPositionY() != 162) { break; }
                if (mySprite->getPositionX() == 461 && mySprite->getPositionY() == 606) { break; }
                else {
                    mySprite->runAction(moveRight);
                    break;
                }
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W: 
            if (mySprite->getPositionY() != 162) { break; } 
            if (mySprite->getPositionX() != 461) { break; }
            if (mySprite->getPositionX() == 906 && mySprite->getPositionY() == 162) { break; }
            else {
            mySprite->runAction(moveUp);
            road1->runAction(changeColor);
            nextMenu->runAction(makeNextVisible);
            addChild(emitter, 10);
            addChild(emitter2, 10);
            break;
            }
            
            case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            case EventKeyboard::KeyCode::KEY_S:
                if (mySprite->getPositionY() != 606 ) { break; }
                else {
                    mySprite->runAction(moveDown);
                    break;
                }
         
        }  
       
        
    };
   
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, mySprite);
     
    return true;
}

void Level1::nextLevel(Ref* pSender) { 
    // go to level 2

    auto scene1 = Level2::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene1, Color3B::ORANGE));
}


void Level1::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

}
