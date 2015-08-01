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
		temp = new EnemyProperty("¿ÃÃ¬ÀÌ", 2, 1, 1, 5);
		temp->sprite_enemy = Sprite::create("Images/demo_egg002.png");
		return temp;
	}
	else if (num == eType_Dae_Wong_Wol_Chang){
		temp = new EnemyProperty("´ë¿Õ ¿ÃÃ¬ÀÌ", 4, 3, 2, 10);
		temp->sprite_enemy = Sprite::create("Images/demo_egg001.png");
		return temp;
	}
	else if (num == eType_Wool_Chang){
		temp = new EnemyProperty("¿ïÃ¬ÀÌ", 10, 2, 1, 5);
		temp->sprite_enemy = Sprite::create("Images/demo_egg003.png");
		return temp;
	}
}