#include "UpgradeController.h"



void UpgradeController::to_next_attack_power(){
	user_info->add_damage(2);
	user_info->add_money_value(-2);
}

void UpgradeController::to_next_attack_delay(){
	user_info->add_delay(-1);
	user_info->add_money_value(-2);
}
void UpgradeController::to_next_velocity(){
	user_info->add_velocity(20.0f);
	user_info->add_money_value(-2);
}

