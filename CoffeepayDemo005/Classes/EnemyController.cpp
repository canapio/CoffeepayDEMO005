#include "EnemyController.h"
//#include "Enemy.h"
void EnemyController::add_enemy(){
	int level = UserInfoSingleton::getInstance()->get_typhoon_level();
	int rand_start, rand_end, rand_real_end;

	if (level == 1){
		rand_start = 1;
		rand_end = 5;
		rand_real_end = 2;
	}
	else if (level == 2){
		rand_start = 2;
		rand_end = 4;
		rand_real_end = 3;
	}
	
	int random_number = RandomHelper::random_int(rand_start, rand_end);

	if (random_number < rand_real_end){
		random_number = rand_real_end;
	}
	else {
		random_number = rand_start;
	}



	Enemy* temp = Enemy::create(random_number);
	if (this->vec_enemy.size() <= 50){
		this->vec_enemy.pushBack(temp);
		temp->set_position();

		this->print_enemy(temp);
		//		log("%d", vec_enemy.size());
	}


}
void EnemyController::set_scene(Layer* input){
	
	this->scene = input;
}
Layer* EnemyController::get_scene(){
	return this->scene;
}
void EnemyController::print_enemy(Enemy* input){

	input->addChild(input->get_property()->sprite_enemy, z_order_enemy_sprite);
	//this->addChild(enemy->get_rect, 5);
	scene->addChild(input->get_layercolor_health(), z_order_enemy_health);
	scene->addChild(input->get_layercolor_health_back(), z_order_enemy_health_back);
	scene->addChild(input->get_label_name(), z_order_enemy_health);
	scene->addChild(input->get_layercolor_name_back(), z_order_enemy_health);
	scene->addChild(input,z_order_enemy_sprite);
}
void EnemyController::delete_enemy(Enemy* input){
	
	//scene->removeChild(input->get_sprite());
	scene->removeChild(input->get_layercolor_health());
	scene->removeChild(input->get_layercolor_health_back());
	scene->removeChild(input->get_layercolor_name_back());
	scene->removeChild(input->get_label_name());
	input->removeFromParentAndCleanup(true);

	//delete input;
	
}
cocos2d::Vector<Enemy*>* EnemyController::get_vector(){
	return &vec_enemy;
}