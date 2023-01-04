/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "GameScene.h"


USING_NS_CC;


Scene* GameScene::createScene()
{
    //'scene' is an autorelance object
    auto scene = Scene::create();
    //'layer' is an autorelease object
    auto layer = GameScene::create();

    //add layer as a child to scene
    scene->addChild(layer);
    //returnthe  scene 
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create("scene.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(backgroundSprite,-1);
  
    playerSprite = Sprite::create("sprite.png");
    playerSprite->setPosition(Point(102,180));
        this->addChild(playerSprite,-1);
       // 
       

//   
      //  auto MoveAction = MoveTo::create(4.0, Point(400, 180));
      //  auto jumpAction = JumpBy::create(2.0, Point(400, 180), 45, 5);
      //  auto action = Sequence::create(MoveAction,
       //     jumpAction, NULL);
       /// playerSprite->runAction(action);


   auto eventListener = EventListenerKeyboard::create();



   eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {

       Vec2 loc = event->getCurrentTarget()->getPosition();
       switch (keyCode) {
       case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
       case EventKeyboard::KeyCode::KEY_A:
           event->getCurrentTarget()->setPosition(loc.x -= 5, loc.y);
           break;
       case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
       case EventKeyboard::KeyCode::KEY_D:
           event->getCurrentTarget()->setPosition(loc.x += 5, loc.y);
           break;
       case EventKeyboard::KeyCode::KEY_UP_ARROW:
       case EventKeyboard::KeyCode::KEY_W:
           event->getCurrentTarget()->setPosition(loc.x, loc.y += 5);
           break;
       case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
       case EventKeyboard::KeyCode::KEY_S:
           event->getCurrentTarget()->setPosition(loc.x, loc.y -= 5);
           break;
       }
   };

   this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, playerSprite);
   return true;
}



