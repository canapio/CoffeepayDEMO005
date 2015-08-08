#include "UserInfoSingleton.h"

UserInfoSingleton* UserInfoSingleton::instance = NULL;

UserInfoSingleton* UserInfoSingleton::getInstance(){
	if (!instance) {
		instance = new UserInfoSingleton();

	}

	return instance;
}

void UserInfoSingleton::releaseInstance(){
	if (instance) delete instance;
}

void UserInfoSingleton::init_values(){
	money_value = 0;
	exp = 0;
	stage_number = 1;

	typhoon_level = 1;
	typhoon_damage = UpgradeDB::get_UpgradeValue_power(0);
	typhoon_delay = 20;
	typhoon_velocity = 50.0f;
	typhoon_radius = SCALEUP_VALUE(22);

	lv_attack_delay = 0;
	lv_attack_power = 0;
	lv_velocity = 0;
}

//ÀÓ½Ã·Î ¸¸µë’Ì¹Çµëµë
void UserInfoSingleton::check_level_up(){

	log("%d", exp);
	if (170 < exp){
		typhoon_level = 2;
	}
}