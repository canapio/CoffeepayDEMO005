#include "EnemyController.h"
//#include "Enemy.h"
void EnemyController::add_enemy(){
	int random_number = RandomHelper::random_int(1, 3);
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