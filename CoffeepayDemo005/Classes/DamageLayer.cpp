#include "DamageLayer.h"

DamageLayer* DamageLayer::create(){
	DamageLayer *temp_damagelayer = new (std::nothrow) DamageLayer();
	if (temp_damagelayer && temp_damagelayer->init()){
		temp_damagelayer->autorelease();
	}
	else{
		CC_SAFE_DELETE(temp_damagelayer);
	}
	return temp_damagelayer;
}
void DamageLayer::show_damage(int damage, Enemy* input_en, Layer* input_la){
	action_damage_move = MoveBy::create(0.3, Point(0,SCALEUP_VALUE(10)));
	label_damage = LabelTTF::create(std::to_string(damage), "Arial", SCALEUP_VALUE(7));
	label_damage->setPosition(
		input_en->get_sprite()->getPosition().x,
		input_en->get_layercolor_health_back()->getPosition().y );
	label_damage->setColor(Color3B(255,0,0));
	label_damage->enableStroke(Color3B(0,0,0),SCALEUP_VALUE(5),true);
	input_la->addChild(label_damage,z_order_damage);

	label_damage->runAction(action_damage_move);

	action_damage_fadeout = FadeOut::create(0.4);
	label_damage->runAction(action_damage_fadeout);
}