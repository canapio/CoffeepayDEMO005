#include "CollisionController.h"

CollisionController::CollisionController(){
	damage_layer = DamageLayer::create();
}
CollisionController::~CollisionController(){}

void CollisionController::check_collision(Typhoon* input_ty, EnemyController* input_ec){
	for (int i = 0; i < input_ec->get_vector()->size(); i++){
		int delay = input_ty->get_delay();
		auto en = input_ec->get_vector()->at(i);
		if (input_ty->check_hit(en->get_rect())){//부딪힘
			en->hit_number++;
			log("delay %d", en->hit_number);
			if (delay <= en->hit_number){
				float health_changed = en->get_current_health() - input_ty->get_damage();
				/*여기다가 체력 깍이는 animation 보여주면됨 데미지랑 위치 받아와서*/
				damage_layer->show_damage(input_ty->get_damage(), en, this->scene);
				if (health_changed <= 0){//체력 다 까짐-> 없애라는 함수호출

					UserInfoSingleton::getInstance()->add_money_value(en->get_property()->money);
					input_ec->delete_enemy(en);
					input_ec->get_vector()->eraseObject(en);
					//input_ec->get_vector()->erase(input_ec->get_vector()->find(en));
					
					i--;
				}
				else{
					
					en->set_current_health(health_changed);//체력 하락
					en->change_layercolor_enemy_health(input_ty->get_damage());//체력 바 하락
					en->hit_number = 0;
				}
				
			}
		}
	}
}
void CollisionController::set_scene(Layer* input_la){
	this->scene = input_la;
}