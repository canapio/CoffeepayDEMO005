#ifndef __GAMESTART_SCENE_H__
#define __GAMESTART_SCENE_H__

#include "cocos2d.h"
#include "LayoutSingleton.h"
#include "Typhoon.h"
#include "UserInfoSingleton.h"


class GameStartScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();


	// implement the "static create()" method manually
	CREATE_FUNC(GameStartScene);

	LayoutSingleton* layout_singleton;

	LayerColor* background;

	Typhoon* typhoon;
	Rect userrect;

	bool is_typhoon_touched;

	virtual void onExit();
	virtual bool onTouchBegan(Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	virtual void onTouchCancelled(Touch *touch, Event *unused_event);

	void view_game_scene();
};

#endif // __GAMESTART_SCENE_H__
