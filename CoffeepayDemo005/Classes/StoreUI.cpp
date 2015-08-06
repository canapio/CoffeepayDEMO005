#include "StoreUI.h"
#include "StoreController.h"

//StoreUI* StoreUI::create(StoreController* p_controller){
StoreUI* StoreUI::create(){
	StoreUI* ret = new (std::nothrow) StoreUI();
	
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

void StoreUI::init_options(){
	user_info = UserInfoSingleton::getInstance();
	
	this->init_layers();
}

void StoreUI::init_layers(){
	float only_upgrade_width = get_store_width_ingame();
	//Store Background
	LayerColor* background = LayerColor::create(Color4B(0, 0, 0, 160), LayoutSingleton::getInstance()->get_original_device_size().width,
		LayoutSingleton::getInstance()->get_original_device_size().height);
	background->setPosition(Point(0, 0));
	this->addChild(background, 1);
	
	

	//Upgrade Button
	attack_power_upgrade_item = MenuItemImage::create("Images/btn_upgrade_normal.png", "Images/btn_upgrade_selected.png", 
		"Images/btn_upgrade_disable.png", CC_CALLBACK_1(StoreUI::upgrade_attack_power, this));
	attack_delay_upgrade_item = MenuItemImage::create("Images/btn_upgrade_normal.png", "Images/btn_upgrade_selected.png", 
		"Images/btn_upgrade_disable.png", CC_CALLBACK_1(StoreUI::upgrade_attack_delay, this));
	velocity_upgrade_item = MenuItemImage::create("Images/btn_upgrade_normal.png", "Images/btn_upgrade_selected.png", 
		"Images/btn_upgrade_disable.png", CC_CALLBACK_1(StoreUI::upgrade_velocity, this));

	//Upgrade button setting
	attack_power_upgrade_label = LabelTTF::create("공격력\n" + std::to_string(UpgradeDB::get_need_money_power(user_info->lv_attack_power + 1)) + " G", "fonts/Yoon_Dod_Woom.ttf", SCALEUP_VALUE(5));
	attack_delay_upgrade_label = LabelTTF::create("공격속도\n" + std::to_string(UpgradeDB::get_need_money_delay(user_info->lv_attack_delay + 1)) + " G", "fonts/Yoon_Dod_Woom.ttf", SCALEUP_VALUE(5));
	velocity_upgrade_label = LabelTTF::create("이동속도\n" + std::to_string(UpgradeDB::get_need_money_velocity(user_info->lv_velocity +1)) + " G", "fonts/Yoon_Dod_Woom.ttf", SCALEUP_VALUE(5));

	attack_delay_upgrade_item->setScale(SCALE_RATE);
	attack_power_upgrade_item->setScale(SCALE_RATE);
	velocity_upgrade_item->setScale(SCALE_RATE);

	Size button_size = Size(attack_power_upgrade_item->getContentSize().width * SCALE_RATE,
		attack_power_upgrade_item->getContentSize().height * SCALE_RATE);

	//ToStore Button
	to_store_item = MenuItemFont::create("상점으로", CC_CALLBACK_1(StoreUI::to_store, this));
	to_store_item->setPosition(Point(button_size.width / 2.0f, button_size.height / 2.0f));
	to_store_item->setTag(1);
	auto to_store_menu = Menu::create(to_store_item, NULL);
	to_store_menu->setPosition(Point::ZERO);
	this->addChild(to_store_menu, 2);

	//upgrade button position
	attack_power_upgrade_item->setPosition(Point(button_size.width / 2.0f, button_size.height / 2.0f + SCALEUP_VALUE(30)));
	attack_delay_upgrade_item->setPosition(Point(button_size.width / 2.0f, button_size.height * 1.5f + SCALEUP_VALUE(32)));
	velocity_upgrade_item->setPosition(Point(button_size.width /2.0f, button_size.height * 2.5f + SCALEUP_VALUE(34)));

	attack_power_upgrade_label->setPosition(Point(button_size.width / 2.0f, button_size.height / 2.0f + SCALEUP_VALUE(30)));
	attack_delay_upgrade_label->setPosition(Point(button_size.width / 2.0f, button_size.height * 1.5f + SCALEUP_VALUE(32)));
	velocity_upgrade_label->setPosition(Point(button_size.width / 2.0f, button_size.height * 2.5f + SCALEUP_VALUE(34)));

	this->addChild(attack_power_upgrade_label, 3);
	this->addChild(attack_delay_upgrade_label, 3);
	this->addChild(velocity_upgrade_label, 3);

	auto upgrade_menu = Menu::create(attack_power_upgrade_item, attack_delay_upgrade_item, velocity_upgrade_item, NULL);
	upgrade_menu->setPosition(Point::ZERO);
	this->addChild(upgrade_menu, 2);
	

}

void StoreUI::check_need_money(){
	int money = user_info->get_money_value();
	// 2 는 나중에 Upgrade DB 에서 가져올 값으로 바꾼다.
	if (money < UpgradeDB::get_need_money_power(user_info->lv_attack_power + 1)){
		attack_power_upgrade_item->setEnabled(false);
	}
	else{
		attack_power_upgrade_item->setEnabled(true);
	}
	if (money < UpgradeDB::get_need_money_delay(user_info->lv_attack_delay +1 )  || UserInfoSingleton::getInstance()->get_delay() < 1){
		attack_delay_upgrade_item->setEnabled(false);
	}
	else{
		attack_delay_upgrade_item->setEnabled(true);
	}
	if (money < UpgradeDB::get_need_money_velocity(user_info->lv_velocity + 1) || user_info->lv_velocity > 20){
		velocity_upgrade_item->setEnabled(false);
	}
	else{
		velocity_upgrade_item->setEnabled(true);
	}
}

void StoreUI::upgrade_attack_delay(Object* pSender){
	
	upgrade_controller->to_next_attack_delay();
	update_need_money();
	

}

void StoreUI::upgrade_attack_power(Object* pSender){
	upgrade_controller->to_next_attack_power();
	update_need_money();
	//attack_power_upgrade_label->
}

void StoreUI::upgrade_velocity(Object* pSender){
	upgrade_controller->to_next_velocity();
	update_need_money();
}

void StoreUI::to_store(Object* ob){
	int tag = to_store_item->getTag();
	if (tag == 1){
		auto action = MoveTo::create(1.0f, Point(0, 0));
		this->runAction(action);
		to_store_item->setString("게임으로");
		to_store_item->setTag(2);
	}
	else if (tag == 2){
		auto action = MoveTo::create(1.0f, Point(-StoreUI::get_store_width_ingame() + LayoutSingleton::getInstance()->get_original_device_size().width, 0));
		this->runAction(action);
		to_store_item->setString("상점으로");
		to_store_item->setTag(1);
	}
	
}

void StoreUI::update_need_money(){
	attack_power_upgrade_label->setString("공격력\n" + std::to_string(UpgradeDB::get_need_money_power(user_info->lv_attack_power + 1)) + " G");
	attack_delay_upgrade_label->setString("공격속도\n" + std::to_string(UpgradeDB::get_need_money_delay(user_info->lv_attack_delay + 1)) + " G");
	velocity_upgrade_label->setString("이동속도\n" + std::to_string(UpgradeDB::get_need_money_velocity(user_info->lv_velocity + 1)) + " G");
}