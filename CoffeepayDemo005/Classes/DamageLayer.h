#ifndef __DAMAGELAYER_H__
#define __DAMAGELAYER_H__
#include <cocos2d.h>
#include "Enemy.h"
USING_NS_CC;
class DamageLayer :public Layer{
private:
	MoveBy* action_damage_move;
	LabelTTF* label_damage;
	FadeOut* action_damage_fadeout;
public:
	static DamageLayer* create();
	void show_damage(int damage, Enemy* input_en, Layer* input_la);
};
#endif