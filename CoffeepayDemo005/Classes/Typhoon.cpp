#include "Typhoon.h"

Typhoon* Typhoon::create(){
	Typhoon *temp_typhoon = new (std::nothrow) Typhoon();
	if (temp_typhoon && temp_typhoon->init()){
		temp_typhoon->autorelease();
		temp_typhoon->init_options();
	}
	else{
		CC_SAFE_DELETE(temp_typhoon);
	}
	
	return temp_typhoon;
}

void Typhoon::init_options(){
	sprite_typhoon = Sprite::create("Images/demo_typhoon001.png");
	sprite_typhoon->getTexture()->setAliasTexParameters();
	sprite_typhoon->setScale(SCALE_RATE);
	UserInfoSingleton::getInstance()->set_radius(SCALEUP_VALUE(sprite_typhoon->getContentSize().width / 2.0));
	
	
	update_status();
	
	this->addChild(sprite_typhoon, 1);
}

Sprite* Typhoon::get_sprite(){
	return this->sprite_typhoon;
}

void Typhoon::set_damage(int input){
	this->typhoon_damage = input;
}

int Typhoon::get_damage(){
	return this->typhoon_damage;
}

void Typhoon::set_velocity(float input){
	this->typhoon_velocity = input;
}

float Typhoon::get_velocity(){
	return this->typhoon_velocity;
}

void Typhoon::set_delay(int input){
	this->attack_delay = input;
}

int Typhoon::get_delay(){
	return this->attack_delay;
}

void Typhoon :: set_radius(float input){
	this->typhoon_radius = input;
}

float Typhoon::get_radius(){
	return typhoon_radius;
}



void Typhoon::set_position(){

	int visible_width = LayoutSingleton::getInstance()->get_original_device_size().width;
	int visible_height = LayoutSingleton::getInstance()->get_original_device_size().height;
	
	
	this->setPosition(visible_width / 2 , visible_height / 2 );
	this->sprite_typhoon->setPosition(0,0);

	/*
	bound = LayerColor::create(Color4B(0, 255, 0, 100),
		SCALEUP_VALUE(sprite_typhoon->getContentSize().width),
		SCALEUP_VALUE(sprite_typhoon->getContentSize().height));
	bound->setPosition(visible_width / 2 - SCALEUP_VALUE(sprite_typhoon->getContentSize().width / 2), 
		visible_height / 2 - SCALEUP_VALUE(sprite_typhoon->getContentSize().height) / 2);
		*/
}

void Typhoon::update_status(){
	typhoon_damage = UserInfoSingleton::getInstance()->get_damage();
	typhoon_radius = UserInfoSingleton::getInstance()->get_radius();
	attack_delay = UserInfoSingleton::getInstance()->get_delay();
	typhoon_velocity = UserInfoSingleton::getInstance()->get_velocity();
}

bool Typhoon::check_hit(Rect input){

	//this->typhoon_radius;
	//this->sprite_typhoon->getPosition().x;
	//this->sprite_typhoon->getPosition().y;

	return input.intersectsCircle(Vec2(this->getPosition().x, this->getPosition().y), SCALEUP_VALUE(this->typhoon_radius));


}