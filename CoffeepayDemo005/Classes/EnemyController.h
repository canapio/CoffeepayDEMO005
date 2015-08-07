#ifndef __ENEMY_CONTROLLER_H__
#define __ENEMY_CONTROLLER_H__

#include <cocos2d.h>
#include "Enemy.h"
#include "UserInfoSingleton.h"

USING_NS_CC;
class EnemyController{
private:
	cocos2d::Vector<Enemy*> vec_enemy;
	Layer * scene;
public:
	//cocos2d::Vector<Enemy*> vec_enemy;
	void set_scene(Layer* input);
	Layer* get_scene();
	cocos2d::Vector<Enemy*>* get_vector();
	void delete_enemy(Enemy* input);
	void print_enemy(Enemy* input);
	void add_enemy();
	void beAttacked(float not_use);
	
};

#endif