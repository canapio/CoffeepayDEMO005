#ifndef __COLLISIONCONTROLLER_H__
#define __COLLISIONCONTROLLER_H__

#include <cocos2d.h>
#include "Typhoon.h"
#include "EnemyController.h"
#include "UserInfoSingleton.h"

class CollisionController{
private:
public:
	/*
	Typhoon ��ü�� Enemy ���͸� ������ �浹 ���ϴ� Method => �Ǳ��̴� �Ŷ� ���Ž� ��&����ġ �޾Ƴ��ߵ�
	
	*/
	void check_collision(Typhoon* input_ty, EnemyController* input_ec);

};
#endif