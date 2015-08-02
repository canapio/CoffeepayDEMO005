#include "GameStartScene.h"

#include "GameScene.h"

USING_NS_CC;





Scene* GameStartScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameStartScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameStartScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	is_typhoon_touched = false;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	layout_singleton = LayoutSingleton::getInstance();
	layout_singleton->set_original_device_size(visibleSize);
	UserInfoSingleton::getInstance()->init_values();

	auto background_image = Sprite::create("Images/demo_concept002_003@3x.png");
	Size img_size = background_image->getContentSize();
	background_image->setScale(visibleSize.width / img_size.width, visibleSize.height / img_size.height);
	background_image->setAnchorPoint(Point::ZERO);
	this->addChild(background_image, 0);

	background = LayerColor::create(Color4B(0.f, 0.f, 0.f, 200.f), visibleSize.width, visibleSize.height);
	background->setPosition(Vec2(0,0));

	//터치
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	auto positionListener = EventListenerTouchOneByOne::create();
	positionListener->setSwallowTouches(true);
	positionListener->onTouchBegan = CC_CALLBACK_2(GameStartScene::onTouchBegan, this);
	positionListener->onTouchMoved = CC_CALLBACK_2(GameStartScene::onTouchMoved, this);
	positionListener->onTouchCancelled = CC_CALLBACK_2(GameStartScene::onTouchCancelled, this);
	positionListener->onTouchEnded = CC_CALLBACK_2(GameStartScene::onTouchEnded, this);
	dispatcher->addEventListenerWithSceneGraphPriority(positionListener, this);

	typhoon = Typhoon::create();
	typhoon->set_position();
	typhoon->get_sprite()->setPosition(Point(layout_singleton->scaleup_value(40),layout_singleton->scaleup_value(80)));



	this->addChild(background, z_order_bg2);
	this->addChild(typhoon, z_order_typhoon);
    
    
    
    
    
	return true;
}


void GameStartScene::view_game_scene(){
	auto game_scene = GameScene::createScene();
	Director::getInstance()->replaceScene(game_scene);
}






// Touch
bool GameStartScene::onTouchBegan(Touch* touch, Event* event) {
	//getCurrentTarget은 Node를 반환한다. 이것이 터치한 오브젝트가 된다.
	auto target = event->getCurrentTarget();
	Point location = target->convertToNodeSpace(touch->getLocation());

	log("touch began %f, %f", location.x, location.y);
	
	
	log("%f", typhoon->get_sprite()->getBoundingBox().size.width);
	
	if (typhoon->get_sprite()->getBoundingBox().containsPoint(touch->getLocation())){
		is_typhoon_touched = true;
		log("touch began typhoon");
	}
	
	return true;
}
void GameStartScene::onTouchMoved(Touch *touch, Event *unused_event) {
	auto target = unused_event->getCurrentTarget();
	Point location = target->convertToNodeSpace(touch->getLocation());

	//log("touch moved %f, %f", location.x, location.y);

}
void GameStartScene::onTouchEnded(Touch *touch, Event *unused_event) {
	auto target = unused_event->getCurrentTarget();
	Point location = target->convertToNodeSpace(touch->getLocation());

	//auto userrect = new Rect(typhoon->getPosition().x - typhoon->getContentSize().width / 2.0f, typhoon->getPosition().y - typhoon->getContentSize().height/2.0f, typhoon->getContentSize().width, typhoon->getContentSize().height);

	log("touch ended %f, %f", location.x, location.y);
	
	if (typhoon->get_sprite()->getBoundingBox().containsPoint(touch->getLocation())){
		if (is_typhoon_touched){
			log("touch ended typhoon");
			//auto game_scene = GameScene::createScene();
			//Director::getInstance()->replaceScene(game_scene);
			auto action = MoveTo::create(2.0f, Point(layout_singleton->get_original_device_size().width / 2.0f, layout_singleton->scaleup_value(80)));
			typhoon->get_sprite()->runAction(action);

			//auto action_bg = Sequence::create(FadeOut::create(2.1f),CallFunc::create(CC_CALLBACK_1(GameStartScene::view_game_scene,this)),NULL);
			auto action_bg = FadeOut::create(2.0f);
			auto action_tran = CallFunc::create(CC_CALLBACK_0(GameStartScene::view_game_scene, this));
			auto seq = Sequence::create(action_bg, action_tran, NULL);
			background->runAction(seq);

			//this->view_game_scene();
		}
	}
	else{
		is_typhoon_touched = false;
	}
	
	
	
}

void GameStartScene::onTouchCancelled(Touch *touch, Event *unused_event) {
	auto target = unused_event->getCurrentTarget();
	Point location = target->convertToNodeSpace(touch->getLocation());

	log("touch cancelled %f, %f", location.x, location.y);


}

void GameStartScene::onExit(){
	

	Layer::onExit();
}
