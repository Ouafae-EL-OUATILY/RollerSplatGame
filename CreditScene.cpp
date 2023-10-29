

#include "CreditScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* Credit::createScene()
{
    return Credit::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Credit::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    AudioEngine::pauseAll();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // background image
    auto background = Sprite::create("bg.jpg");
    background->setPosition(-20, -20);
    background->setScale(0.7);
    this->addChild(background, 0);


    //Menu
    auto YR = Label::createWithTTF("Yassine Ribouh", "fonts/MarkerFelt.ttf", 120);
    YR->setTextColor(Color4B::BLUE);
    auto OE = Label::createWithTTF("Ouafae El Ouatily", "fonts/MarkerFelt.ttf", 120);
    OE->setTextColor(Color4B::MAGENTA);
    auto Main = Label::createWithTTF("Main Menu", "fonts/MarkerFelt.ttf", 80);
    auto exit = Label::createWithTTF("Exit", "fonts/MarkerFelt.ttf", 80);
    auto menu_item_1 = MenuItemLabel::create(YR, CC_CALLBACK_1(Credit::Blank, this));
    auto menu_item_2 = MenuItemLabel::create(OE, CC_CALLBACK_1(Credit::Blank, this));
    auto menu_item_3 = MenuItemLabel::create(Main, CC_CALLBACK_1(Credit::Main, this));
    auto menu_item_4 = MenuItemLabel::create(exit, CC_CALLBACK_1(Credit::menuCloseCallback, this));
    menu_item_1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 4));
    menu_item_2->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 3));
    menu_item_3->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 2));
    menu_item_4->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 1));
    auto* menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, menu_item_4, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu);


  
 
    return true;
}





void Credit::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

}
void Credit::Main(Ref* pSender)
{
    auto scene = MainMenu::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene, Color3B::MAGENTA));
}

void Credit::Blank(Ref* pSender) {
  
}