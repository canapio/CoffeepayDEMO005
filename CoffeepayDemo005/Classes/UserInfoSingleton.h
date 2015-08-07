#ifndef __USER_INFO_SINGLETON_H__
#define __USER_INFO_SINGLETON_H__

#include "cocos2d.h"
#include "LayoutSingleton.h"
#include "UpgradeDB.h"

USING_NS_CC;

class UserInfoSingleton{

private:
	static UserInfoSingleton* instance;
	~UserInfoSingleton(){};
	UserInfoSingleton(){};
	

	int money_value;
	int exp;
	int stage_number;

	int typhoon_level;
	float typhoon_radius;
	int typhoon_damage;
	float typhoon_velocity;
	int typhoon_delay;

	

public:
	static UserInfoSingleton * getInstance();
	static void releaseInstance();
	
	void init_values();

	void set_typhoon_level(int input) { typhoon_level = input; }
	int get_typhoon_level(){ return typhoon_level; }

	void set_damage(int input){ typhoon_damage = input; };
	void add_damage(int input){ typhoon_damage += input; };
	int get_damage(){ return typhoon_damage; };

	void set_velocity(float input){ typhoon_velocity = input; };
	void add_velocity(float input){ typhoon_velocity += input; };
	float get_velocity(){ return typhoon_velocity; };

	void set_delay(int input){ typhoon_delay = input; };
	void add_delay(int input){ typhoon_delay += input; };
	int get_delay() { return typhoon_delay; };

	void set_radius(float input){ typhoon_radius = input; };
	void add_radius(float input){ typhoon_radius += input; };
	float get_radius(){ return typhoon_delay; };

	void set_money_value(int input){
		money_value = input;
	};
	void add_money_value(int input){
		money_value += input;
	};
	int get_money_value(){
		return money_value;
	}

	void set_exp(int input){
		exp = input;
	};
	void add_exp(int input){
		exp += input;
	};
	int get_exp(){
		return exp;
	}

	int lv_attack_power, lv_attack_delay, lv_velocity;

	void check_level_up();
};

#endif