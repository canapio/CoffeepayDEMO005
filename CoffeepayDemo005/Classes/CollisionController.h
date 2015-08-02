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
	Typhoon 객체와 Enemy 벡터를 가져와 충돌 비교하는 Method => 피깍이는 거랑 제거시 돈&경험치 받아내야됨
	
	*/
	CollisionController();
	~CollisionController();
	void check_collision(Typhoon* input_ty, EnemyController* input_ec);
	void set_scene(Layer* input_la);
};
#endif