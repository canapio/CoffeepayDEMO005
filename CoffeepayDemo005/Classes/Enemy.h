#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <cocos2d.h>
#include "LayoutSingleton.h"
#include "EnemyPropertyDB.h"

USING_NS_CC;
class GameScene;
class Enemy: public Layer{

private:

	GameScene* scene;//GameScene 화면 받을꺼용도
	Rect rect_enemy;//적의 rect
	LayerColor* layercolor_enemy_health;//체력바
	LayerColor* layercolor_enemy_health_back;//체력바 뒷배경(어두운빨간색그거)
	LayerColor* layercolor_enemy_name_back;
	LabelTTF* labelttf_enemy_level_name;
	//int level_enemy;
	//int max_health;//체력
	int current_health;
	//td::string name_enemy;

	EnemyProperty* enemy_property;//이미지, 이름, 체력, 경험치, 레벨, 돈

public:
	//Sprite* sprite_enemy;// 적의 이미지

	int hit_number;
	EnemyProperty* get_property();

	void set_scene(GameScene* input);
	static Enemy* create(int type_number);//생성자가 없고 실제 cocos2dx 함수처럼 create로함
	
	int get_current_health();//enemy의 health을 리턴
	void set_current_health(int input);//input 값으로 health를 수정
	int get_max_health();
	void set_max_health(int input);

	Rect get_rect();// rect_enemy를 리턴
	LabelTTF* get_label();
	std::string get_name();
	int get_level();
	Sprite* get_sprite();
	LayerColor* get_layercolor_health();
	LayerColor* get_layercolor_health_back();
	LayerColor* get_layercolor_name_back();
	LabelTTF* get_label_name();


	void change_layercolor_enemy_health(int damage);//피격시 체력바 change
	void add_enemy(GameScene* scene);
	void set_position();//enemy의 위치(sprite,rect,layercolor) 랜덤으로 할당

}; 
#endif