#include "StoreController.h"
#include "StoreUI.h"


void StoreController::to_next_attack_power(){
	user_info->set_damage(UpgradeDB::get_UpgradeValue_power(user_info->lv_attack_power + 1));
	user_info->add_money_value(-UpgradeDB::get_need_money_power(user_info->lv_attack_power + 1));
	user_info->lv_attack_power++;
}

void StoreController::to_next_attack_delay(){
	user_info->add_delay(-1);
	user_info->add_money_value(-UpgradeDB::get_need_money_delay(user_info->lv_attack_delay + 1));
	user_info->lv_attack_delay++;
}
void StoreController::to_next_velocity(){
	user_info->add_velocity(20.0f);
	user_info->add_money_value(-UpgradeDB::get_need_money_velocity(user_info->lv_velocity + 1));
	user_info->lv_velocity++;
}

