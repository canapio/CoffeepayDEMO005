#include "EnemyPropertyDB.h"

EnemyProperty::EnemyProperty(std::string str, int _money, int _exp, int _level, int _health){
	name = str;
	money = _money;
	exp = _exp;
	level = _level;
	max_health = _health;
}
EnemyProperty* EnemyPropertyDB::get_enemy_by_type(int num){
	EnemyProperty* temp;

	if (num == eType_Wol_Chang){
		temp = new EnemyProperty("��ì��", 2, 1, 1, 5);
		temp->sprite_enemy = Sprite::create("Images/demo_egg002.png");
	
	}
	else if (num == eType_Dae_Wong_Wol_Chang){
		temp = new EnemyProperty("��� ��ì��", 8, 3, 2, 10);
		temp->sprite_enemy = Sprite::create("Images/demo_egg001.png");
	
	}
	else if (num == eType_Wool_Chang){
		temp = new EnemyProperty("��ì��", 5, 2, 1, 5);
		temp->sprite_enemy = Sprite::create("Images/demo_egg003.png");
		
	}
	temp->type_num = num;
	return temp;
}