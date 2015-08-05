#include "UpgradeDB.h"


int UpgradeDB::get_UpgradeValue_power(int lv)
{
	if (lv == 0) return 2;
	else if (lv == 1) return 3;
	else {
		return get_UpgradeValue_power(lv - 1) + get_UpgradeValue_power(lv - 2);
	}
}

int UpgradeDB::get_need_money_velocity(int lv){
	return (int)pow(5, lv) / 2;
}

int UpgradeDB::get_need_money_delay(int lv){
	return (int)pow(5, lv) / 2;
}


int UpgradeDB::get_need_money_power(int lv){
	return (int)pow(4, lv) / 3;
}