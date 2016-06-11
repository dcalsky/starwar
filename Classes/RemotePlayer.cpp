//
//  Player.cpp
//  ball
//
//  Created by Dcalsky on 16/5/31.
//
//



#include "Player.h"

USING_NS_CC;



bool RemotePlayer::init()
{
    if (!Node::init()) {
        return false;
    }
    for (int i = 0; i < moonNumber; ++i) {
        auto ball = new Ball(MOON, i + 1, Vec2(moonPositionX + moonDistance * i, 750.0f - moonPositionY));
        _balls.push_back(ball);
        this->addChild(ball->getSprite(), 4); // Why 4 ? todo
    }
    
    // earth 2
    for (int i = 0; i < earthNumber; ++i) {
        auto ball = new Ball(EARTH, i + 5, Vec2(earthPositionX + earthDistance * i, 750.0f - earthPositionY));
        _balls.push_back(ball);
        this->addChild(ball->getSprite(), 4);
    }
    
    // sun 1
    for (int i = 0; i < sunNumber; ++i) {
        auto ball = new Ball(SUN, i + 7, Vec2(sunPositionX + sunDistance * i, 750.0f - sunPositionY));
        _balls.push_back(ball);
        this->addChild(ball->getSprite(), 4);
    }
    
    return true;
}

void RemotePlayer::applyShoot(int ballId, const Force &force)
{
    if(!_active) {
        return;
    }
    Ball* selectBall;
    float forceY = -force.y;
    for(const auto &ball : _balls) {
        if(ball->getId() == ballId) {
            selectBall = ball;
        }
    }
    selectBall->move(Force(force.x, forceY));
    this->schedule(CC_CALLBACK_1(RemotePlayer::_isDeparted, this), isRestingInterval, kRepeatForever, 0, "isDeparted"); // 发射完小球后立即检测
}

void RemotePlayer::_isDeparted(float dt)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto lterator = _balls.begin();
    while(lterator != _balls.end()) {
        auto l = *lterator;
        if (l->getSprite()->getTag() != mouseControllerTag &&
            (l->getSprite()->getPosition().x - 2.5f >= visibleSize.width / 2 + mapWidth / 2 || l->getSprite()->getPosition().y - 2.5f >= visibleSize.height / 2 + mapHeight / 2 ||
             l->getSprite()->getPosition().x + 2.5f <= visibleSize.width / 2 - mapWidth / 2 || l->getSprite()->getPosition().y + 2.5f <= visibleSize.height / 2 - mapHeight / 2 )) {
                printf("depart");
                l->depart();
                _balls.erase(lterator);
            } else {
        ++lterator;
            }
    }
}


void RemotePlayer::setActive(bool state)
{
    _active = state;
}