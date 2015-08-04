//
//  TyphoonMovement.h
//  CoffeepayDemo005
//
//  Created by GwakDoyoung on 2015. 8. 2..
//
//

#ifndef __CoffeepayDemo005__TyphoonMovement__
#define __CoffeepayDemo005__TyphoonMovement__

#include "cocos2d.h"
USING_NS_CC;
#include "LayoutSingleton.h"



enum MoveCount {
    moveTag_nothing = 0,
    moveTag_1 = 1,
    moveTag_2,
    moveTag_3
} ;

class Typhoon;
class TyphoonMovement {
public:
    // TyphoonMovement 초기화
    void init_with_typhoon(Typhoon *t) ;
    
    // 터치시 이동하라고 명령
    void move_to_location (Point target_point) ;
    
    // 아직은 필요 없음
//    void update (float dt) ;
    
private:
    // 태풍 객체
    Typhoon *typhoon;
    
};

#endif /* defined(__CoffeepayDemo005__TyphoonMovement__) */
