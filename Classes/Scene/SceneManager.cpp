/*
 * SceneManager.cpp
 *
 *  Created on: 2012-9-16
 *      Author: arch
 */

#include "SceneManager.h"
//各个场景
#include "MenuScene.h"
#include "GameScene.h"
#include "AboutScene.h"
#include "GameOver.h"

void SceneManager::loadScene(SceneType type) {

	switch (type) {
	case GAME_SCENE:
		CCLog("GAME SCENE");
		CCDirector::sharedDirector()->replaceScene(GameScene::scene());
		break;
	case ABOUT_SCENE:
		CCLog("About Scene");
		CCDirector::sharedDirector()->replaceScene(AboutScene::scene());
		break;
	case EXIT:
		CCLog("exit");
		break;

	case SETTING:
		CCLog("go to setting scene");
		//
		break;

	case HOME:
		CCLog("back to home");
		CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
		break;
	case GAMEOVER:
		CCLog("go to Game Over Scene..................");
		CCDirector::sharedDirector()->replaceScene(GameOver::scene());
		break;

	default:
		CCLog("Can not find any Scene.....................");
		break;
	}

}
