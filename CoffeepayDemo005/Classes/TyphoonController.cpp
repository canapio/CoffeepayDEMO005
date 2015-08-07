#include "TyphoonController.h"
TyphoonController::TyphoonController(){
	vec_exp.push_back(20);
	for (int i = 0; i < 9; i++){
		vec_exp.push_back(vec_exp.at(i) *3 / 2 + 10);
	}
}
void TyphoonController::check_exp(Typhoon* ty_input){
	int user_exp = UserInfoSingleton::getInstance()->get_exp();
	
	//log("%d ==== %d", user_exp, vec_exp.at(0));
	if (user_exp >= vec_exp.at(0)){
		
		//float temp_radius = UserInfoSingleton::getInstance()->get_radius();
		float temp_radius = ty_input->get_radius();
		
		ty_input->set_radius(ty_input->get_radius() + 5);
		//이거 나중에 일반식으로 고칠려면 초기 크기를 가지고있어야함

		UserInfoSingleton::getInstance()->set_radius(SCALEUP_VALUE(ty_input->get_radius()));
		//log("%f //// %f", ty_input->get_radius(), temp_radius);
		float temp_scale = ty_input->get_sprite()->getScale();
		temp_scale = temp_scale + 1;
		
		ty_input->get_sprite()->setScale(temp_scale);
		//UserInfoSingleton::getInstance()->set_radius(ty_input->get_sprite()->getContentSize().width / 2.0);
		vec_exp.erase(vec_exp.begin()+ 0);
		vec_exp.push_back(vec_exp.at(vec_exp.size()-1) * 3 / 2);
	}
}