#include "GameScene.h"
#include "TyphoonMovement.h"


Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	this->removeAllChildren();

	layout_singleton = LayoutSingleton::getInstance();

	//배경 설정
	background_game = Sprite::create("Images/demo_concept002_003@3x.png");
	log("sprite %p", background_game);
	Size visibleSize = layout_singleton->get_original_device_size();
	Size img_size = background_game->getContentSize();
	background_game->setScale(visibleSize.width / img_size.width, visibleSize.height / img_size.height);
	background_game->setAnchorPoint(Point::ZERO);
	background_game->setPosition(Point(0, 0));
	this->addChild(background_game, z_order_bg1);

	//업그레이드 레이어
	upgrade_layer = UpgradeUI::create();
	upgrade_controller = new UpgradeController();
	upgrade_layer->init_with_controller(upgrade_controller);
	upgrade_layer->setPosition(10, 10);
	this->addChild(upgrade_layer,z_order_upgrade_ui);

	//터치 설정
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	auto positionListener = EventListenerTouchOneByOne::create();
	positionListener->setSwallowTouches(true);
	positionListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	positionListener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	positionListener->onTouchCancelled = CC_CALLBACK_2(GameScene::onTouchCancelled, this);
	positionListener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	dispatcher->addEventListenerWithSceneGraphPriority(positionListener, this);

	typhoon = Typhoon::create();
	typhoon->set_position();
	this->addChild(typhoon, z_order_typhoon);
    
    typhoonMovement = new TyphoonMovement();
    typhoonMovement->init_with_typhoon(typhoon);
    
	
	enemy_controller = new EnemyController();
	enemy_controller->set_scene(this);
	
	money_label = LabelTTF::create("0 G", "fonts/pixelation.ttf", SCALEUP_VALUE(5));
	money_label->setPosition(Point(LayoutSingleton::getInstance()->get_original_device_size().width - SCALEUP_VALUE(20), SCALEUP_VALUE(140)));
	money_label->setColor(Color3B::YELLOW);
	this->addChild(money_label, z_order_option);
	
	//데미지 화면에 띄우기위에 scene 받는 부분 추가
	collision_controller = new CollisionController();
	collision_controller->set_scene(this);

	this->start_schedule();
	return true;
}





void GameScene::start_schedule(){
	this->schedule(schedule_selector(GameScene::display_new_enemy), 1.0);
	this->schedule(schedule_selector(GameScene::change_button_enable), 0.1f);
	this->schedule(schedule_selector(GameScene::display_money_label), 0.1f);
	this->schedule(schedule_selector(GameScene::check_hit_schedule), 0.05f);
}

void GameScene::display_new_enemy(float dt){
	enemy_controller->add_enemy();
}

void GameScene::change_button_enable(float dt){
	upgrade_layer->check_need_money();
	typhoon->update_status();
}

void GameScene::display_money_label(float dt){
	int money = UserInfoSingleton::getInstance()->get_money_value();
	std::string str = std::to_string(money);
	std::string money_value = str+ " G";
	//log("%s", money_value);
	money_label->setString(money_value);
}

void GameScene::check_hit_schedule(float not_use){
	collision_controller->check_collision(typhoon, enemy_controller);
}
















// Touch
bool GameScene::onTouchBegan(Touch* touch, Event* event) {
	//getCurrentTarget은 Node를 반환한다. 이것이 터치한 오브젝트가 된다.
	auto target = event->getCurrentTarget();
	Point location = target->convertToNodeSpace(touch->getLocation());
	typhoon->stopAllActions();
	log("touch began %f, %f", location.x, location.y);
	
	
	return true;
}
void GameScene::onTouchMoved(Touch *touch, Event *unused_event) {
	auto target = unused_event->getCurrentTarget();
	Point location = target->convertToNodeSpace(touch->getLocation());

	//log("touch moved %f, %f", location.x, location.y);

}
void GameScene::onTouchEnded(Touch *touch, Event *unused_event) {
	auto target = unused_event->getCurrentTarget();
	Point location = target->convertToNodeSpace(touch->getLocation());

	//auto userrect = new Rect(typhoon->getPosition().x - typhoon->getContentSize().width / 2.0f, typhoon->getPosition().y - typhoon->getContentSize().height/2.0f, typhoon->getContentSize().width, typhoon->getContentSize().height);
	
	log("touch ended %f, %f", location.x, location.y);
	float scale = 2.0;
	if (location.x < SCALEUP_VALUE(55 * 3 + 5) && location.y < SCALEUP_VALUE(28)){}
	else{
		float distance_x = location.x - typhoon->get_sprite()->getPositionX();
		float distance_y = location.y - typhoon->get_sprite()->getPositionY();
		float distance = sqrt(pow(distance_x, 2) + pow(distance_y, 2)) / scale;
		float time = distance / typhoon->get_velocity();
		auto action = EaseExponentialInOut::create(MoveTo::create(time, Point(location.x, location.y)));

		typhoon->get_sprite()->runAction(action);
	}
}

void GameScene::onTouchCancelled(Touch *touch, Event *unused_event) {
	auto target = unused_event->getCurrentTarget();
	Point location = target->convertToNodeSpace(touch->getLocation());

	log("touch cancelled %f, %f", location.x, location.y);
}