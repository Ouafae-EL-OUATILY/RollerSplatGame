
#include "Level3Scene.h"
#include "cocos2d.h"

USING_NS_CC;

Scene* Level3::createScene()
{
    return Level3::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Level3::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
     // Close button
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(Level3::menuCloseCallback, this));

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
    auto menu = Menu::create(closeItem, NULL);
   // menu->setScale(0.1);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    // Level 3 Label 
    auto myLabel = Label::createWithTTF("LEVEL 3", "fonts/MarkerFelt.ttf", 50);
    myLabel->setTextColor(Color4B::MAGENTA);
    myLabel->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + 280));
    this->addChild(myLabel);
    TintTo* makeNextInvisible = TintTo::create(0, 0, 0, 0);

  
    //Ball
    auto mySprite = Sprite::create("ball.png");
    mySprite->setPosition(Point((visibleSize.width / 2) - 223, (visibleSize.height / 2) - 222));
    auto level3 = Sprite::create("level3.png");
    level3->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    level3->setScale(0.9f);
    
    // upper road
    auto road5 = Sprite::create("l3road5.png");
    road5->setPosition(Point((visibleSize.width / 2) - origin.x, (visibleSize.height / 2) + 222));
    road5->setScale(0.9f);
    this->addChild(road5);
    // lower road
    auto road4 = Sprite::create("l3road4.png");
    road4->setPosition(Point((visibleSize.width / 2) - 223, (visibleSize.height / 2) + 114));
    road4->setScale(0.9f);
    this->addChild(road4);
    // right road
    auto road3 = Sprite::create("l3road3.png");
    road3->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + 7));
    road3->setScale(0.9f);
    this->addChild(road3);
    // right road 2
    auto road2 = Sprite::create("l3road2.png");
    road2->setPosition(Point((visibleSize.width / 2) + 222, (visibleSize.height / 2) -106));
    road2->setScale(0.9f);
    this->addChild(road2);
    // left road
    auto road1 = Sprite::create("l3road1.png");
    road1->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) - 222));
    road1->setScale(0.9f);
    this->addChild(road1);





    this->addChild(level3);
    mySprite->setScale(0.58f);
    // change Sprite Color
    TintTo* red = TintTo::create(0, 114, 57, 228);
    this->addChild(mySprite);
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

        // Movements 2
        auto moveHalfUp = MoveBy::create(0.1, Vec2(0, 230));
        auto moveHalfUp2 = MoveBy::create(0.1, Vec2(0, 215));
        auto moveHalfDown = MoveBy::create(0.1, Vec2(0, -230));
        auto moveHalfDown2 = MoveBy::create(0.1, Vec2(0, -215));
    
        //Fire Works Effect
        auto emitter = ParticleFireworks::create();    
        auto emitter2 = ParticleFireworks::create();
        emitter->setPosition(Point((visibleSize.width / 2) + 237, (visibleSize.height / 2) + 384));
        emitter2->setPosition(Point((visibleSize.width / 2) - 237, (visibleSize.height / 2) + 384));
        emitter->setRotation(180);
        emitter2->setRotation(180);
        emitter->setScale(1.5);
        emitter2->setScale(1.5);

        TintTo* makeNextVisible = TintTo::create(2, 0, 0, 0);
        TintTo* changeColor = TintTo::create(0.5, 0, 0, 0);
        // Keyboard Event Switch Case
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            if (mySprite->getPositionX() != 905) { break; }
            if (mySprite->getPositionX() == 905 && mySprite->getPositionY() == 392) {
                mySprite->runAction(moveLeft);
                road3->runAction(changeColor);
                break;
            }
            if (mySprite->getPositionX() == 905 && mySprite->getPositionY() == 607) {
                mySprite->runAction(moveLeft);
                break;
            }
            mySprite->runAction(moveLeft);
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            if (mySprite->getPositionX() != 460) { break; }

            if (mySprite->getPositionX() == 460 && mySprite->getPositionY() == 162) {
                mySprite->runAction(moveRight);
                road1->runAction(changeColor);
                break;
            }
            
            if (mySprite->getPositionX() == 460 && mySprite->getPositionY() == 607) {
                mySprite->runAction(moveRight);
                road5->runAction(changeColor);
                addChild(emitter, 10);
                addChild(emitter2, 10);
                break;
            }
            if (mySprite->getPositionY() == 392) {
                mySprite->runAction(moveRight);
                break;
            }
            if (mySprite->getPositionY() != 607) {
                break;
            }
            mySprite->runAction(moveRight);
      
            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            if (mySprite->getPositionY() == 392 && mySprite->getPositionX() == 460) {
                mySprite->runAction(moveHalfUp2);
                road4->runAction(changeColor);
                break;
            }
            if (mySprite->getPositionY() == 162 && mySprite->getPositionX() != 905) { break; }
            if (mySprite->getPositionY() != 162) { break; }
            if (mySprite->getPositionY() == 162 && mySprite->getPositionX() == 460) { break; }
            if (mySprite->getPositionY() == 162 && mySprite->getPositionX() == 905) { 
                mySprite->runAction(moveHalfUp);
                road2->runAction(changeColor);
                break;
            }
            mySprite->runAction(moveUp);
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            if (mySprite->getPositionY() == 392 && mySprite->getPositionX() == 905) {
                mySprite->runAction(moveHalfDown);
                break;
             }
            if (mySprite->getPositionY() == 607 && mySprite->getPositionX() == 460) {
                mySprite->runAction(moveHalfDown2);
                break;
            }
            if (mySprite->getPositionY() != 606) { break; }
                mySprite->runAction(moveDown);
            break;
        }
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, mySprite);

    return true;
}

void Level3::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();


}
