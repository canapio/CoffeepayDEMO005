#include "UpgradeUI.h"

//UpgradeUI* UpgradeUI::create(UpgradeController* p_controller){
UpgradeUI* UpgradeUI::create(){
	UpgradeUI* ret = new (std::nothrow) UpgradeUI();
	
	if (ret && ret->init())
	{
		ret->init_options();
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

void UpgradeUI::init_options(){
	user_info = UserInfoSingleton::getInstance();
	this->init_layers();
}

void UpgradeUI::init_layers(){
	attack_power_upgrade_item = MenuItemImage::create("Images/btn_upgrade_normal.png", "Images/btn_upgrade_selected.png", 
		"Images/btn_upgrade_disable.png", CC_CALLBACK_1(UpgradeUI::upgrade_attack_power, this));
	attack_delay_upgrade_item = MenuItemImage::create("Images/btn_upgrade_normal.png", "Images/btn_upgrade_selected.png", 
		"Images/btn_upgrade_disable.png", CC_CALLBACK_1(UpgradeUI::upgrade_attack_delay, this));
	velocity_upgrade_item = MenuItemImage::create("Images/btn_upgrade_normal.png", "Images/btn_upgrade_selected.png", 
		"Images/btn_upgrade_disable.png", CC_CALLBACK_1(UpgradeUI::upgrade_velocity, this));

	attack_power_upgrade_label = LabelTTF::create("공격력", "fonts/Yoon_Dod_Woom.ttf", SCALEUP_VALUE(5));
	attack_delay_upgrade_label = LabelTTF::create("공격속도", "fonts/Yoon_Dod_Woom.ttf", SCALEUP_VALUE(5));
	velocity_upgrade_label= LabelTTF::create("이동속도", "fonts/Yoon_Dod_Woom.ttf", SCALEUP_VALUE(5));

	attack_delay_upgrade_item->setScale(SCALE_RATE);
	attack_power_upgrade_item->setScale(SCALE_RATE);
	velocity_upgrade_item->setScale(SCALE_RATE);

	Size button_size = Size(attack_power_upgrade_item->getContentSize().width * SCALE_RATE,
		attack_power_upgrade_item->getContentSize().height * SCALE_RATE);

	attack_power_upgrade_item->setPosition(Point(button_size.width / 2.0f, button_size.height / 2.0f));
	attack_delay_upgrade_item->setPosition(Point(button_size.width * 1.5f + SCALEUP_VALUE(5), button_size.height / 2.0f));
	velocity_upgrade_item->setPosition(Point(button_size.width * 2.5f + SCALEUP_VALUE(10), button_size.height / 2.0f));

	attack_power_upgrade_label->setPosition(Point(button_size.width / 2.0f, button_size.height / 2.0f));
	attack_delay_upgrade_label->setPosition(Point(button_size.width * 1.5f + SCALEUP_VALUE(5), button_size.height / 2.0f));
	velocity_upgrade_label->setPosition(Point(button_size.width * 2.5f + SCALEUP_VALUE(10), button_size.height / 2.0f));

	this->addChild(attack_power_upgrade_label, 2);
	this->addChild(attack_delay_upgrade_label, 2);
	this->addChild(velocity_upgrade_label, 2);

	auto upgrade_menu = Menu::create(attack_power_upgrade_item, attack_delay_upgrade_item, velocity_upgrade_item, NULL);
	upgrade_menu->setPosition(Point::ZERO);
	this->addChild(upgrade_menu, 1);
	

}

void UpgradeUI::check_need_money(){
	int money = user_info->get_money_value();
	// 2 는 나중에 Upgrade DB 에서 가져올 값으로 바꾼다.
	if (money < 2){
		attack_power_upgrade_item->setEnabled(false);
	}
	else{
		attack_power_upgrade_item->setEnabled(true);
	}
	if (money < 2){
		attack_delay_upgrade_item->setEnabled(false);
	}
	else{
		attack_delay_upgrade_item->setEnabled(true);
	}
	if (money < 2){
		velocity_upgrade_item->setEnabled(false);
	}
	else{
		velocity_upgrade_item->setEnabled(true);
	}
}

void UpgradeUI::upgrade_attack_delay(Object* pSender){
	
	upgrade_controller->to_next_attack_delay();

	

}

void UpgradeUI::upgrade_attack_power(Object* pSender){
	upgrade_controller->to_next_attack_power();
	//attack_power_upgrade_label->
}

void UpgradeUI::upgrade_velocity(Object* pSender){
	upgrade_controller->to_next_velocity();
}