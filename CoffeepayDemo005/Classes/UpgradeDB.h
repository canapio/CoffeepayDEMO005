#ifndef __UPGRADE_DB_H__
#define __UPGRADE_DB_H__

#include <cocos2d.h>
#include "LayoutSingleton.h"


USING_NS_CC;

class UpgradeDB{
public:
	static int get_UpgradeValue_power(int lv);
	static int get_need_money_power(int lv);

	static int get_need_money_delay(int lv);
	static int get_need_money_velocity(int lv);
};
#endif
