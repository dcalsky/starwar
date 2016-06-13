#include "HelloWorldScene.h"
#include "Config.h"
#include "../Controllers/GameController.h"

USING_NS_CC;

Scene* HelloWorld::createScene(NetworkController *network)
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    auto audio = new Audio;
    // scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);  // Debug
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    // 获取netWork，初始化给gameController
    auto gameController = GameController::create();
    gameController->initNetwork(network);
    scene->addChild(gameController, 3);
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
    // add layer as a child to scene
    scene->addChild(layer);
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
    // return the scene
    return scene;
}

bool HelloWorld::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto windowSize = Director::getInstance()->getWinSize(); // background image for full screen
    auto bg = Sprite::create(battleSceneFrameFile);
    auto map = Sprite::create(battleMapFrameFile);
    
    bg->setScale(1.2f);
    map->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    bg->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    
    this->addChild(bg, 0);
    this->addChild(map, 1);

    return true;
}