//
//  MenuScene.cpp
//  ball
//
//  Created by Dcalsky on 16/6/1.
//
//

#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include "Config.h"
#include "Audio.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    // 'layer' is an autorelease object
    auto layer = MenuScene::create();

    //auto itemLayer = Item::create();
    // add layer as a child to scene
    scene->addChild(layer);
    //scene->addChild(itemLayer);
    // return the scene
    return scene;
}

bool MenuScene::init() {
    if (!Node::init())
    {
        return false;
    }
    Audio *audio = new Audio();
    int i = 0;
    auto bg = Sprite::create(MENU_SCENE_FRAME);
    auto computerItem = MenuItemImage::create(COMPUTER_TEXTURE, COMPUTER_TEXTURE);
    auto onlineItem = MenuItemImage::create(ONLINE_TEXTURE, ONLINE_TEXTURE);
    auto aboutItem = MenuItemImage::create(ABOUT_TEXTURE, ABOUT_TEXTURE);
    auto exitItem = MenuItemImage::create(EXIT_TEXTURE, EXIT_TEXTURE);
    auto menu = Menu::create(computerItem, onlineItem, aboutItem, exitItem, nullptr);
    
    audio->playMenuSceneMusic();
    //Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Size windowSize = Director::getInstance()->getWinSize(); // background image for full screen
    
    bg->setScale(windowSize.width / bg->getContentSize().width, windowSize.height / bg->getContentSize().height);
    bg->setPosition(Vec2(windowSize.width/2, windowSize.height/2));
    
    for(const auto &child : menu->getChildren()) {
        float offset = 50.0f * i;
        child->setScale(0.45f);
        child->setPosition(Vec2(-windowSize.width / 2 + child->getContentSize().width / 2 - 20.0f, 145.0f - offset));
        i++;
    }
    
    this->addChild(menu, 2);
    this->addChild(bg, 1);
    return true;
}