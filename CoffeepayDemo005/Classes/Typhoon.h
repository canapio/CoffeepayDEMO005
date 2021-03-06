#ifndef __TYPHOON_H__
#define __TYPHOON_H__

#include <cocos2d.h>
#include "LayoutSingleton.h"
#include "UserInfoSingleton.h"
#define typhoon_rotate_time 2.0f
USING_NS_CC;

class Typhoon : public Layer{
private:
	Sprite* sprite_typhoon;

	int typhoon_damage;
	int attack_delay;
	float typhoon_radius;
	float typhoon_velocity;
	RotateBy* action_rotate;

	int typhoon_level;
	
public:
	void init_options();
	static Typhoon* create();
	LayerColor* bound;
	Sprite* get_sprite();


	void set_damage(int input);
	int get_damage();

	void set_velocity(float velocity);
	float get_velocity();

	void set_delay(int input);
	int get_delay();

	void set_radius(float input);
	float get_radius();

	void set_level(int input);
	int get_level();

	bool check_hit(Rect input);

	void update_status();

	void set_position();//중앙(초기위치) 설정할때 1번 쓰일거라 예상
	void rotate_typhoon(float not_use);


};
#endif