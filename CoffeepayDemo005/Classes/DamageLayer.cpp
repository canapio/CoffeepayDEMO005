#include "DamageLayer.h"

DamageLayer* DamageLayer::create(){
	DamageLayer *temp_damagelayer = new (std::nothrow) DamageLayer();
	if (temp_damagelayer && temp_damagelayer->init()){
		temp_damagelayer->autorelease();
	}
	else{
		CC_SAFE_DELETE(temp_damagelayer);
	}
	temp_damagelayer->setPosition(0, 0);
	return temp_damagelayer;
}
void DamageLayer::show_damage(int damage, Enemy* input_en, int delay, Layer* ly){
	
	LabelTTF* label_damage = LabelTTF::create(std::to_string(damage), "fonts/pixelation.ttf", SCALEUP_VALUE(5));
	label_damage->setOpacity(200.0f);
	label_damage->enableStroke(Color3B(0,0,0),SCALEUP_VALUE(7),true);
	
	Size sprite_size = input_en->get_sprite()->getContentSize();
	Point sprite_point = input_en->getPosition();
	label_damage->setColor(Color3B::RED);
	//label_damage->setPosition(Point(sprite_point.x , sprite_point.y + sprite_size.height * SCALE_RATE / 2.0f + SCALEUP_VALUE(5) ));
	label_damage->setPosition(sprite_point.x, 0);
	//input_en->get_sprite()->setOpacity(155);
	
	
	ly->addChild(label_damage, z_order_enemy_health);
	
	float time = delay * 0.1f;
<<<<<<< HEAD
	auto action_damage_move = MoveBy::create(time, Point(0, SCALEUP_VALUE(10)));
	auto action_damage_fadeout = FadeOut::create(time);
	//auto action_blink = Blink::create(time/5, 1);
	auto action_spawn = Spawn::create(action_damage_move, action_damage_fadeout,NULL);
	auto action_tint_1 = FadeTo::create(0.01, 120);
	auto action_delay = DelayTime::create(time / 10);
	auto action_tint_2 = FadeTo::create(0.01, 255);
	auto action_spawn_fade = Sequence::create(action_tint_1,action_delay, action_tint_2, NULL);
	label_damage->runAction(action_spawn);
	//input_en->get_sprite()->runAction(action_tint_1);
	input_en->get_sprite()->runAction(action_spawn_fade);
=======
	auto action_damage_move = MoveBy::create(1.0f, Point(0, SCALEUP_VALUE(10)));
	auto action_damage_fadeout = FadeOut::create(1.0f);

	auto action_spawn = Spawn::create(action_damage_move, action_damage_fadeout,NULL);
	
	label_damage->runAction(Sequence::create(action_spawn,RemoveSelf::create(),NULL));
>>>>>>> ca3dfe820f12f46babab802dfeddc7a1587ab340

}