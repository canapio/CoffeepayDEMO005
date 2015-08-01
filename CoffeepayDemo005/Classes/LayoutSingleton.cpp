//
//  LayoutSingleton.cpp
//  CoffeePayDEMO001
//
//  Created by GwakDoyoung on 2015. 7. 19..
//
//

#include "LayoutSingleton.h"

#define SCREEN_HEIGHT 160.f


LayoutSingleton * LayoutSingleton::instance = NULL ;

LayoutSingleton * LayoutSingleton::getInstance() {
    if (!instance) {
        instance = new LayoutSingleton();
    }
    
    return instance;
}

void LayoutSingleton::releaseInstance() {
    if(instance) delete instance;
}

void LayoutSingleton::set_original_device_size (Size ds) {
    original_device_size = ds;
    scale_rate = ds.height/SCREEN_HEIGHT;
    set_small_device_size(Size(ds.width*(1.f/scale_rate), SCREEN_HEIGHT));
}
void LayoutSingleton::set_small_device_size (Size ss) {
    small_device_size = ss;
}

Size LayoutSingleton::get_original_device_size () {
    return original_device_size;
}
Size LayoutSingleton::get_small_device_size () {
    return small_device_size;
}

float LayoutSingleton::scaleup_value(float t) {
    return t*(scale_rate) ;
}
Point LayoutSingleton::scaleup_point(float x, float y) {
    return Point(this->scaleup_value(x), this->scaleup_value(y)) ;
}
Point LayoutSingleton::scaleup_point(Point p) {
    return Point(this->scaleup_value(p.x), this->scaleup_value(p.y)) ;
}


Size LayoutSingleton::scaleup_size(float w, float h) {
    return Size(this->scaleup_value(w), this->scaleup_value(h)) ;
}
Size LayoutSingleton::scaleup_size(Size s) {
    return Size(this->scaleup_value(s.width), this->scaleup_value(s.height)) ;
}


