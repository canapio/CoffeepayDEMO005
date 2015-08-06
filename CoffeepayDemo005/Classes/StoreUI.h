#ifndef __UPGRADE_UI_H__
#define __UPGRADE_UI_H__

#include "cocos2d.h"
USING_NS_CC;
#include "LayoutSingleton.h"

#include "UserInfoSingleton.h"

class StoreController;
class StoreUI : public Layer{
public:
	//static StoreUI* create(StoreController* p_controller);
	static StoreUI* create();
	

	MenuItemImage* attack_power_upgrade_item;
	MenuItemImage* attack_delay_upgrade_item;
	MenuItemImage* velocity_upgrade_item;

	LabelTTF* attack_power_upgrade_label;
	LabelTTF* attack_delay_upgrade_label;
	LabelTTF* velocity_upgrade_label;

	void check_need_money();
	void init_with_controller(StoreController* controller){
		upgrade_controller = controller;
	}

	//GameScene에서 스토어 창이 얼마나 나와있을 지
	
	static float get_store_width_ingame(){
		return SCALEUP_VALUE(55.0);
	}

	void update_need_money();
private:
	

	void init_options();
	void init_layers();

	StoreController* upgrade_controller;

	void upgrade_attack_power(Object* pSender);
	void upgrade_attack_delay(Object* pSender);
	void upgrade_velocity(Object* pSender);

	UserInfoSingleton* user_info;

	void to_store(Object* pSender);

	MenuItemFont* to_store_item;
};

#endif