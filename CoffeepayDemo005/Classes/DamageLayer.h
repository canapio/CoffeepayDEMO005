#ifndef __DAMAGELAYER_H__
#define __DAMAGELAYER_H__
#include <cocos2d.h>
#include "Enemy.h"
USING_NS_CC;
class DamageLayer :public Layer{
private:

public:
	static DamageLayer* create();
	void show_damage(int damage, Enemy* input_en, int delay, Layer* ly);
};
#endif