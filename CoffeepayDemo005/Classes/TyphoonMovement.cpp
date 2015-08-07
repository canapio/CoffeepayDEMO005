//
//  TyphoonMovement.cpp
//  CoffeepayDemo005
//
//  Created by GwakDoyoung on 2015. 8. 2..
//
//

#include "TyphoonMovement.h"
#include "Typhoon.h"



void TyphoonMovement::init_with_typhoon(Typhoon *t) {
    typhoon = t;
}
void TyphoonMovement::move_to_location(Point target_point) {
    
    
    float scale = 8.f;
    
    Point start_point = typhoon->getPosition();
    Point end_point = target_point;
    float distance_start_end = start_point.distance(end_point);
    
    float time = distance_start_end / typhoon->get_velocity();
    time /= scale;
    
   // log("target_point : %f, %f", target_point.x, target_point.y);
    auto action = EaseExponentialInOut::create(MoveTo::create(time, target_point));
    
    typhoon->runAction(action);
    
}