//
//  MouseController.hpp
//  ball
//
//  Created by Dcalsky on 16/5/30.
//
//

#ifndef MouseController_hpp
#define MouseController_hpp

#include "Ball.h"
#include "cocos2d.h"

class MouseController : public cocos2d::Node {
public:
    virtual bool init() override;
    virtual ~MouseController() {};
    void addBalls(std::vector<Ball*>);
    CREATE_FUNC(MouseController);
private:
    void _handleMouseUp(cocos2d::Event*);
    void _handleMouseMove(cocos2d::Event*);
    void _handleMouseDown(cocos2d::Event*);
    std::vector<Ball*> _balls;
    std::pair<Ball*, bool> selected;
};

#endif /* MouseController_hpp */
