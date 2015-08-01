#ifndef __UPGRADE_UI_H__
#define __UPGRADE_UI_H__

#include "cocos2d.h"
USING_NS_CC;
#include "LayoutSingleton.h"
#include "UpgradeController.h"
#include "UserInfoSingleton.h"

class UpgradeUI : public Layer{
public:
	//static UpgradeUI* create(UpgradeController* p_controller);
	static UpgradeUI* create();
	

	MenuItemImage* attack_power_upgrade_item;
	MenuItemImage* attack_delay_upgrade_item;
	MenuItemImage* velocity_upgrade_item;

	LabelTTF* attack_power_upgrade_label;
	LabelTTF* attack_delay_upgrade_label;
	LabelTTF* velocity_upgrade_label;

	void check_need_money();
	void init_with_controller(UpgradeController* controller){
		upgrade_controller = controller;
	}
private:


	void init_options();
	void init_layers();

	UpgradeController* upgrade_controller;

	void upgrade_attack_power(Object* pSender);
	void upgrade_attack_delay(Object* pSender);
	void upgrade_velocity(Object* pSender);

	UserInfoSingleton* user_info;

	
};

#endif