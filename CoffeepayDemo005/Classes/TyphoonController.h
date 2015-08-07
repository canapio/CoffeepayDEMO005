#ifndef __TYPHOONCONTROLLER_H__
#define __TYPHOONCONTROLLER_H__
#include "Typhoon.h"
#include "LayoutSingleton.h"
#include "UserInfoSingleton.h"
#include <cocos2d.h>

class TyphoonController{
private:
	
	std::vector<int> vec_exp;
public:
	TyphoonController();
	void check_exp(Typhoon* ty_input);
};
#endif