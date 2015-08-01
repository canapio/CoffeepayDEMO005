//
//  LayoutSingleton.h
//  CoffeePayDEMO001
//
//  Created by GwakDoyoung on 2015. 7. 19..
//
//

#ifndef __CoffeePayDEMO001__LayoutSingleton__
#define __CoffeePayDEMO001__LayoutSingleton__


#include "cocos2d.h"
USING_NS_CC;





#define SCALE_RATE LayoutSingleton::getInstance()->scale_rate


#define SCALEUP_VALUE(v) LayoutSingleton::getInstance()->scaleup_value(v)

#define SCALEUP_POINT_XY(x, y) LayoutSingleton::getInstance()->scaleup_point(x, y)
#define SCALEUP_POINT(p) LayoutSingleton::getInstance()->scaleup_point(p)

#define SCALEUP_SIZE_WH(w, h) LayoutSingleton::getInstance()->scaleup_size(w, h)
#define SCALEUP_SIZE(s) LayoutSingleton::getInstance()->scaleup_size(s)




enum { z_order_bg1, z_order_bg2, z_order_enemy_sprite, z_order_typhoon,z_order_enemy_health_back, z_order_enemy_health, z_order_upgrade_ui,z_order_option};


class LayoutSingleton {
private:
    static LayoutSingleton * instance ;
    ~LayoutSingleton(){/*empty*/};
    LayoutSingleton(){/*empty*/};
    
    Size original_device_size;
    Size small_device_size;
    
public:
    static LayoutSingleton * getInstance();
    static void releaseInstance();
    
    
    
    void set_original_device_size (Size ds) ;
    void set_small_device_size (Size ss) ;
    
    Size get_original_device_size () ;
    Size get_small_device_size () ;
    
    
    
    
    float scale_rate;
    
    float scaleup_value(float t) ;
    Point scaleup_point(float x, float y) ;
    Point scaleup_point(Point p) ;
    
    Size scaleup_size(float w, float h) ;
    Size scaleup_size(Size s) ;
    
    
};


#endif /* defined(__CoffeePayDEMO001__LayoutSingleton__) */
