#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <cocos2d.h>
#include "LayoutSingleton.h"
#include "EnemyPropertyDB.h"

USING_NS_CC;
class GameScene;
class Enemy: public Layer{

private:

	GameScene* scene;//GameScene ȭ�� �������뵵
	Rect rect_enemy;//���� rect
	LayerColor* layercolor_enemy_health;//ü�¹�
	LayerColor* layercolor_enemy_health_back;//ü�¹� �޹��(��ο�����װ�)
	LayerColor* layercolor_enemy_name_back;
	LabelTTF* labelttf_enemy_level_name;
	//int level_enemy;
	//int max_health;//ü��
	int current_health;
	//td::string name_enemy;

	EnemyProperty* enemy_property;//�̹���, �̸�, ü��, ����ġ, ����, ��

public:
	//Sprite* sprite_enemy;// ���� �̹���

	int hit_number;
	EnemyProperty* get_property();

	void set_scene(GameScene* input);
	static Enemy* create(int type_number);//�����ڰ� ���� ���� cocos2dx �Լ�ó�� create����
	
	int get_current_health();//enemy�� health�� ����
	void set_current_health(int input);//input ������ health�� ����
	int get_max_health();
	void set_max_health(int input);

	Rect get_rect();// rect_enemy�� ����
	LabelTTF* get_label();
	std::string get_name();
	int get_level();
	Sprite* get_sprite();
	LayerColor* get_layercolor_health();
	LayerColor* get_layercolor_health_back();
	LayerColor* get_layercolor_name_back();
	LabelTTF* get_label_name();


	void change_layercolor_enemy_health(int damage);//�ǰݽ� ü�¹� change
	void add_enemy(GameScene* scene);
	void set_position();//enemy�� ��ġ(sprite,rect,layercolor) �������� �Ҵ�

}; 
#endif