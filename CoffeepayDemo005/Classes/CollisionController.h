#ifndef __COLLISIONCONTROLLER_H__
#define __COLLISIONCONTROLLER_H__

#include <cocos2d.h>
#include "Typhoon.h"
#include "EnemyController.h"
#include "UserInfoSingleton.h"
#include "DamageLayer.h"
class CollisionController{
private:
	Layer* scene;
	DamageLayer* damage_layer;
public:
	/*
	Typhoon ��ü�� Enemy ���͸� ������ �浹 ���ϴ� Method => �Ǳ��̴� �Ŷ� ���Ž� ��&����ġ �޾Ƴ��ߵ�
	
	*/
	CollisionController();
	~CollisionController();
	void check_collision(Typhoon* input_ty, EnemyController* input_ec);
	void set_scene(Layer* input_la);
};
#endif