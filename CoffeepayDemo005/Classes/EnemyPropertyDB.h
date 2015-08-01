#ifndef __ENEMY_PROPERTY_DB_H__
#define __ENEMY_PROPERTY_DB_H__

#include <cocos2d.h>
USING_NS_CC;
enum{ na, eType_Wol_Chang, eType_Dae_Wong_Wol_Chang, eType_Wool_Chang };

class EnemyProperty{
public:
	EnemyProperty(std::string str,int _money,int _exp, int _level, int _health);
	EnemyProperty(){};
	int type_num;
	
	Sprite* sprite_enemy;
	
	std::string name;
	int max_health;
	int money;
	int exp;
	int level;
};


class EnemyPropertyDB{
private:


public:
	static EnemyProperty* get_enemy_by_type(int num);
};

#endif