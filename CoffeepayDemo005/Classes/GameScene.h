#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "LayoutSingleton.h"
#include "Typhoon.h"
#include "EnemyController.h"
#include "StoreUI.h"
#include "StoreController.h"
#include "CollisionController.h"

USING_NS_CC;


class TyphoonMovement;
class GameScene : public cocos2d::Layer{

private:
	Typhoon* typhoon;
	EnemyController* enemy_controller;

	CollisionController* collision_controller;

	LabelTTF* money_label;
    
    
    TyphoonMovement *typhoonMovement;
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(GameScene);

	LayoutSingleton* layout_singleton;

	Sprite* background_game;

	StoreUI* store_layer;
	StoreController* store_controller;
	void init_store_layer();


	virtual bool onTouchBegan(Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	virtual void onTouchCancelled(Touch *touch, Event *unused_event);
	
	void start_schedule();
	void display_new_enemy(float dt);
	void change_button_enable(float dt);
	void display_money_label(float dt);

	void check_hit_schedule(float not_use);
};


#endif