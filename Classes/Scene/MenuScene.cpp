
#include "MenuScene.h"

#include "SceneManager.h"
#include "AboutScene.h"
#include "GameScene.h"
#include "GameLayer.h"




CCScene* MenuScene::scene()
{
    CCScene *scene = CCScene::create();

    MenuScene *layer = MenuScene::create();

    scene->addChild(layer);
    return scene;
}


bool MenuScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

    CCSize winSize = CCDirector::sharedDirector()->getWinSize();


    //------Background
    CCSprite* pSprite = CCSprite::create("logo.png");
    pSprite->setPosition( ccp(winSize.width/2, winSize.height/2) );
    this->addChild(pSprite, 0);

    //------Logo
//    string s;
//    string s;


    //-------Menu
//    string

// NEW GAME
    CCSprite* newGameNormal = CCSprite::create("s_menu1.png", CCRectMake(0, 0, 126*2, 33*2));
    CCSprite* newGameSelected = CCSprite::create("s_menu1.png", CCRectMake(0, 33*2, 126*2, 33*2));
    CCSprite* newGameDisabled = CCSprite::create("s_menu1.png", CCRectMake(0, 33*2*2, 126*2, 33*2));


    CCMenuItemSprite* newGame = CCMenuItemSprite::create(newGameNormal,
    		newGameSelected,
    		newGameDisabled,
    		this, menu_selector(MenuScene::menuGameCallback));
//SET MENU
    CCSprite* gameSettingNormal = CCSprite::create("s_menu1.png", CCRectMake(126*2,0,126*2,33*2));
    CCSprite* gameSettingSelected = CCSprite::create("s_menu1.png",CCRectMake(126*2,33*2,126*2,33*2));
    CCSprite* gameSettingDisabled = CCSprite::create("s_menu1.png",CCRectMake(126*2,33*2*2,126*2,33*2));
    CCMenuItemSprite* gameSetting = CCMenuItemSprite::create(gameSettingNormal,
    		gameSettingSelected,
    		gameSettingDisabled,
    		this, menu_selector(MenuScene::menuGameCallback));
//ABOUT MENU
    CCSprite* aboutNormal = CCSprite::create("s_menu1.png", CCRectMake(126*2*2,0,126*2,33*2));
    CCSprite* aboutSelected = CCSprite::create("s_menu1.png", CCRectMake(126*2*2,33*2,126*2,33*2));
    CCSprite* aboutDisabled = CCSprite::create("s_menu1.png", CCRectMake(126*2*2,33*2*2,126*2,33*2));
    CCMenuItemSprite* about = CCMenuItemSprite::create(aboutNormal,
    		aboutSelected,
    		aboutDisabled,
    		this,menu_selector(MenuScene::menuAboutCallback));

    //TODO 其他类似自己设定
    CCMenu* menu = CCMenu::create(newGame, gameSetting, about, NULL);

    menu->alignItemsVerticallyWithPadding(30); //垂直间隔
    this->addChild(menu, 1, 2);
    menu->setPosition(ccp(winSize.width / 2, winSize.height / 2 - 80));


//Set font size
    CCMenuItemFont::setFontSize(70);
//
//    int delta = 200;
//
//
//    //进入游戏
//    CCMenuItemFont *start = CCMenuItemFont::create("Start", this, menu_selector(MenuScene::menuGameCallback));
//    start->setPosition(size.width/2, size.height/2 +delta);
//
//    //退出游戏
//    CCMenuItemFont *exit = CCMenuItemFont::create("Exit", this, menu_selector(MenuScene::menuCloseCallback));
//    exit->setPosition(size.width/2, size.height/2 - 2*delta);
//
//    //关于
//    CCMenuItemFont *about = CCMenuItemFont::create("About", this, menu_selector(MenuScene::menuAboutCallback));
//    about->setPosition(size.width/2, size.height/2 );
//
//    //设置
//     CCMenuItemFont *set = CCMenuItemFont::create("Setting", this, menu_selector(MenuScene::menuCloseCallback));
//     set->setPosition(size.width/2, size.height/2 -delta);
//
//    //总菜单
//    CCMenu* menu = CCMenu::create(start, exit, about, set, NULL);
//    menu->setPosition(CCPointZero);
//    this->addChild(menu, 1);




    return true;
}

void MenuScene::menuCloseCallback(CCObject* pSender)
{
//	CCLog("close*************************");
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    exit(0);
#endif
}


void MenuScene::menuAboutCallback(CCObject* pSender)
{
	CCLog("Go to about scene");
//	CCDirector::sharedDirector()->replaceScene(AboutScene::scene());
//	SceneManager::loadScene(ABOUT_SCENE);
	SceneManager::loadScene(GAMEOVER);  //暂时测试 GameOver
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//	SceneManager::loadScene();

#endif
}

void MenuScene::menuGameCallback(CCObject* pSender)
{
//	CCDirector::sharedDirector()->replaceScene(GameScene::scene());
//	SceneManager::loadScene(GAME_SCENE);  //TODO 测试新类
	CCDirector::sharedDirector()->replaceScene(GameLayer::scene());
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#endif
}

void MenuScene::menuSetCallback(CCObject* pSender)
{
	SceneManager::loadScene(SETTING);
}

void MenuScene::menuGameOverCallback(CCObject* pSender) {
	SceneManager::loadScene(GAMEOVER);
}
