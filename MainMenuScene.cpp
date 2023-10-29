
#include "MainMenuScene.h"
#include "Level1Scene.h"
#include "Level2Scene.h"
#include "CreditScene.h"

USING_NS_CC;


Scene* MainMenu::createScene()
{
    return MainMenu::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    //Adding a Background Music
    AudioEngine::preload("song.mp3");
    AudioEngine::play2d("song.mp3",true);
   
    // get the VisibleSize
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
   
    // Background image------------------------
    auto background = Sprite::create("bg.jpg");
    background->setPosition(-20, -20);
    background->setScale(0.7);
    this->addChild(background, 0);
    //---------------------------------------

    //Menu -------------------------------------------------------------------------------------
    
    // Create Play Text with MarkerFelt Font and 80 Font Size
    auto play = Label::createWithTTF("Play", "fonts/MarkerFelt.ttf", 80); 
    auto Credits = Label::createWithTTF("Credits", "fonts/MarkerFelt.ttf", 80);
    auto exit = Label::createWithTTF("Exit", "fonts/MarkerFelt.ttf", 80);
    // Set The Text Color
    play->setTextColor(Color4B::BLUE); 
    Credits->setTextColor(Color4B::GREEN);
    exit->setTextColor(Color4B::RED);
    //Create a MenuItemLabel to give the Labels onClick Function
    auto menu_item_1 = MenuItemLabel::create(play, CC_CALLBACK_1(MainMenu::Play, this)); 
    auto menu_item_2 = MenuItemLabel::create(Credits, CC_CALLBACK_1(MainMenu::Credits,this));
    auto menu_item_3 = MenuItemLabel::create(exit, CC_CALLBACK_1(MainMenu::Exit, this));
    // Set Position of  Menu Items
    menu_item_1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 4) * 3));
    menu_item_2->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 4) * 2));
    menu_item_3->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 4) * 1));
    auto* menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, NULL);
    menu->setPosition(Point(0, 0));
    // Add the Menu to the Scene
    this->addChild(menu);

    //-------------------------------------------------------------------------------------------------
    return true;
}
 

// MainMenu Class Methods
void MainMenu::Play(cocos2d::Ref* pSender)
{
// Create Level1 Scene
auto scene = Level1::createScene(); 
//Transitioning between Main Menu Scene and Level1 Scene using Transition Fade
Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene, Color3B::BLUE));
}

void MainMenu::Credits(cocos2d::Ref* pSender)
{
    // Create Credit Scene
    auto scene2 = Credit::createScene();
    //Transitioning between Main Menu Scene and Credit Scene using Transition Fade
    Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene2, Color3B::MAGENTA));
}
void MainMenu::Exit(cocos2d::Ref* pSender)
{     
    // Exit the Game
    Director::getInstance()->end();
}



