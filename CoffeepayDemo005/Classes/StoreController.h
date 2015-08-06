#ifndef __UPGRADE_CONTROLLER_H__
#define __UPGRADE_CONTROLLER_H__

#include "cocos2d.h"
#include "LayoutSingleton.h"
#include "UserInfoSingleton.h"


USING_NS_CC;
class StoreUI;
class StoreController{
public:
	
	StoreController(){
		
		user_info = UserInfoSingleton::getInstance();
	};

	void to_next_attack_power();
	void to_next_attack_delay();
	void to_next_velocity();

private:
	UserInfoSingleton* user_info;
	
	
};
#endif