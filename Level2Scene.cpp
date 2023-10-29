
#include "Level2Scene.h"
#include "Level3Scene.h"
#include "cocos2d.h"

USING_NS_CC;

Scene* Level2::createScene()
{
    return Level2::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Level2::init()
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
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(Level2::menuCloseCallback, this));

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
    // menu->setScale(0.1);
    CloseMenu->setPosition(Vec2::ZERO);
    this->addChild(CloseMenu, 1);

    // next level button
    auto nextImg = MenuItemImage::create("next.png", "next.png", CC_CALLBACK_1(Level2::nextLevel, this));

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

    // Create menu, it's an autorelease object
    auto nextMenu = Menu::create(nextImg, NULL);
    nextMenu->setScale(0.1);
    nextMenu->setPosition(Vec2(600, 0));
    this->addChild(nextMenu, 1);

    // Label
    auto myLabel = Label::createWithTTF("LEVEL 2", "fonts/MarkerFelt.ttf", 50);
    myLabel->setTextColor(Color4B::MAGENTA);
    myLabel->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + 280));
    this->addChild(myLabel);
 
    TintTo* makeNextInvisible = TintTo::create(0, 0, 0, 0);

    nextMenu->runAction(makeNextInvisible);
    //Ball
    auto mySprite = Sprite::create("ball.png");
    mySprite->setPosition(Point((visibleSize.width / 2) - 223, (visibleSize.height / 2) - 222));

    auto level2 = Sprite::create("level2.png");
    level2->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    level2->setScale(0.9f);

    // middle road
    auto road5 = Sprite::create("l2road5.png");
    road5->setPosition(Point((visibleSize.width / 2) -0.4, (visibleSize.height / 2) -76));
    road5->setScale(0.9f);
    this->addChild(road5);
    // lower road
    auto road4 = Sprite::create("l2road4.png");
    road4->setPosition(Point((visibleSize.width / 2) + 108, (visibleSize.height / 2) - 222.5));
    road4->setScale(0.9f);
    this->addChild(road4);
    // right road
    auto road3 = Sprite::create("l2road3.png");
    road3->setPosition(Point((visibleSize.width / 2) + 222.9, (visibleSize.height / 2) + origin.y));
    road3->setScale(0.9f);
    this->addChild(road3);
    // upper road
    auto road2 = Sprite::create("l2road2.png");
    road2->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + 223));
    road2->setScale(0.9f);
    this->addChild(road2);
    // left road
    auto road1 = Sprite::create("l2road1.png");
    road1->setPosition(Point((visibleSize.width / 2) - 223, (visibleSize.height / 2) + origin.y));
    road1->setScale(0.9f);
    this->addChild(road1);

   
    
   

        this->addChild(level2);
        mySprite->setScale(0.58f);
        TintTo* orange = TintTo::create(0, 255, 215, 0);
        this->addChild(mySprite);
        mySprite->runAction(orange);

        // Creating a keyboard event listener
        auto eventListener = EventListenerKeyboard::create();
        // Lambda Function
        eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        // Movements 1
        auto moveUp = MoveBy::create(0.2, Vec2(0, 444));
        auto moveDown = MoveBy::create(0.2, Vec2(0, -444));
        auto moveRight = MoveBy::create(0.2, Vec2(445, 0));
        auto moveLeft = MoveBy::create(0.2, Vec2(-445, 0)); 
        // Movements 2
        auto moveHalfLeft = MoveBy::create(0.1, Vec2(-222.5, 0));
        auto moveHalfUp = MoveBy::create(0.1, Vec2(0, 260));
        auto moveHalfDown = MoveBy::create(0.1, Vec2(0, -260));
        auto moveHalfRight = MoveBy::create(0.1, Vec2(222.5, 0));
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


        TintTo* makeNextVisible = TintTo::create(2, 120, 255, 120);
        TintTo* changeColor = TintTo::create(0.5, 0, 0, 0);

        // Keyboard Event Switch Case
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            if (mySprite->getPositionX() != 905) {break;  }
            if (mySprite->getPositionX() == 905 && mySprite->getPositionY() == 162) {
                mySprite->runAction(moveHalfLeft);
                road4->runAction(changeColor);
                break;
            }
            mySprite->runAction(moveLeft);
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            if (mySprite->getPositionX() == 682.50 && mySprite->getPositionY() == 162) {
                mySprite->runAction(moveHalfRight);
                break;}
            if (mySprite->getPositionX() != 460) { break; }
            if (mySprite->getPositionY() != 606) { break; }
            if (mySprite->getPositionX() == 460 && mySprite->getPositionY() == 606) {
                mySprite->runAction(moveRight);
                road2->runAction(changeColor);
                break;}
            mySprite->runAction(moveRight);
                break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            if (mySprite->getPositionY() != 162) { break; }
            if (mySprite->getPositionX() == 682.50 && mySprite->getPositionY() == 162) {
                mySprite->runAction(moveHalfUp);
                road5->runAction(changeColor);
                nextMenu->runAction(makeNextVisible);
                addChild(emitter, 10);
                addChild(emitter2, 10);
                break;}
            mySprite->runAction(moveUp);
            road1->runAction(changeColor);
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            if (mySprite->getPositionX() == 682.50 && mySprite->getPositionY() == 422) {
                mySprite->runAction(moveHalfDown);
                break;}
            if (mySprite->getPositionX() == 905 && mySprite->getPositionY() == 606) {
                mySprite->runAction(moveDown);
                road3->runAction(changeColor);
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


void Level2::nextLevel(Ref* pSender) {
    // Go to Level 3
    auto scene2 = Level3::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene2, Color3B::GREEN));
}

void Level2::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
}
