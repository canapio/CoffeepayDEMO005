#include "Enemy.h"
Enemy* Enemy::create(int type_number){
	Enemy *temp_enemy = new (std::nothrow) Enemy();
	if (temp_enemy && temp_enemy->init()){
		temp_enemy->autorelease();
	}
	else{
		CC_SAFE_DELETE(temp_enemy);
	}
	
	temp_enemy->enemy_property = EnemyPropertyDB::get_enemy_by_type(type_number);

	temp_enemy->current_health = temp_enemy->enemy_property->max_health;
	
	temp_enemy->hit_number = 0;
	//
	temp_enemy->labelttf_enemy_level_name = LabelTTF::create("Lv." + std::to_string(temp_enemy->enemy_property->level) + " " + temp_enemy->enemy_property->name, "fonts/Yoon_Dod_Woom.ttf", 15);
	temp_enemy->layercolor_enemy_name_back = LayerColor::create(Color4B(255, 255, 255, 60), temp_enemy->labelttf_enemy_level_name->getContentSize().width, temp_enemy->labelttf_enemy_level_name->getContentSize().height);
	temp_enemy->layercolor_enemy_health = LayerColor::create(Color4B(255, 0, 0, 255), temp_enemy->enemy_property->sprite_enemy->getContentSize().width * 4 / 5, temp_enemy->enemy_property->sprite_enemy->getContentSize().height / 10);
	temp_enemy->layercolor_enemy_health_back = LayerColor::create(Color4B(255, 0, 0, 100), temp_enemy->enemy_property->sprite_enemy->getContentSize().width * 4 / 5, temp_enemy->enemy_property->sprite_enemy->getContentSize().height / 10);

	temp_enemy->enemy_property->sprite_enemy->getTexture()->setAliasTexParameters();
	temp_enemy->enemy_property->sprite_enemy->setScale(SCALE_RATE);
	temp_enemy->layercolor_enemy_health->setScale(SCALE_RATE);
	temp_enemy->layercolor_enemy_health_back->setScale(SCALE_RATE);
	//temp_enemy->labelttf_enemy_level_name->setScale(SCALE_RATE);
	

	return temp_enemy;
}

int Enemy::get_current_health(){
	return this->current_health;
}
void Enemy::set_current_health(int input){
	this->current_health = input;
}

int Enemy::get_max_health(){
	return this->enemy_property->max_health;
}
void Enemy::set_max_health(int input){
	this->enemy_property->max_health = input;
}

LabelTTF* Enemy::get_label(){
	return this->labelttf_enemy_level_name;
}
int Enemy::get_level(){
	return this->enemy_property->level;
}
Rect Enemy::get_rect(){
	return this->rect_enemy;
}
std::string Enemy::get_name(){
	return this->enemy_property->name;
}
Sprite* Enemy::get_sprite(){
	return this->enemy_property->sprite_enemy;
}
LayerColor* Enemy::get_layercolor_health(){
	return this->layercolor_enemy_health;
}
LayerColor* Enemy::get_layercolor_health_back(){
	return this->layercolor_enemy_health_back;
}
LabelTTF* Enemy::get_label_name(){
	return this->labelttf_enemy_level_name;
}
LayerColor* Enemy::get_layercolor_name_back(){
	return this->layercolor_enemy_name_back;
}

void Enemy::change_layercolor_enemy_health(int damage){
	float health_float = this->layercolor_enemy_health->getContentSize().width;
	float max_health_float = this->layercolor_enemy_health_back->getContentSize().width;
	health_float = health_float - damage * health_float / this->enemy_property->max_health;
	this->layercolor_enemy_health->changeWidth(health_float);
}

void Enemy::set_position(){
	bool is_right_position = false;
	int visible_width = LayoutSingleton::getInstance()->get_original_device_size().width - this->enemy_property->sprite_enemy->getContentSize().width;
	int visible_height = LayoutSingleton::getInstance()->get_original_device_size().height - this->enemy_property->sprite_enemy->getContentSize().height;
	int random_x;
	int random_y;
	int mod_random_x;
	int mod_random_y;
	while (!is_right_position){
		
		int random_number_wi = RandomHelper::random_int(1000, 100000);
		int random_number_he = RandomHelper::random_int(1000, 100000);

		random_x = random_number_wi % (visible_width);
		random_y = random_number_he % (visible_height);//0~(480-enemy_real_size)

		mod_random_x = random_x - this->enemy_property->sprite_enemy->getContentSize().width / 2;
		mod_random_y = random_y - this->enemy_property->sprite_enemy->getContentSize().height / 2;

		//업그레이드 버튼에 생성 됬는가
		if (random_x < SCALEUP_VALUE(55*3 + 5) && random_y < SCALEUP_VALUE(28)){
			is_right_position = false;
		}
		else{
			is_right_position = true;
		}
	}

	this->enemy_property->sprite_enemy->setPosition(random_x, random_y);
	this->layercolor_enemy_health->setPosition(mod_random_x + this->enemy_property->sprite_enemy->getContentSize().width / 10, random_y + 2 * this->enemy_property->sprite_enemy->getContentSize().height);
	this->layercolor_enemy_health_back->setPosition(mod_random_x + this->enemy_property->sprite_enemy->getContentSize().width / 10, random_y + 2 * this->enemy_property->sprite_enemy->getContentSize().height);
	this->rect_enemy.setRect(mod_random_x, mod_random_y, this -> enemy_property->sprite_enemy->getContentSize().width, this->enemy_property->sprite_enemy->getContentSize().height);
	
	this->layercolor_enemy_name_back->setPosition(random_x - this->labelttf_enemy_level_name->getContentSize().width / 2, random_y - 2.5*this->enemy_property->sprite_enemy->getContentSize().height - this->labelttf_enemy_level_name->getContentSize().height / 2);
	this->labelttf_enemy_level_name->setPosition(random_x, random_y - 2.5*this->enemy_property->sprite_enemy->getContentSize().height);

	this->layercolor_enemy_health->setAnchorPoint(Point::ZERO);
	this->layercolor_enemy_health_back->setAnchorPoint(Point::ZERO);
}

void Enemy::set_scene(GameScene* input){
	this->scene = input;
}

EnemyProperty* Enemy::get_property(){
	return enemy_property;
}