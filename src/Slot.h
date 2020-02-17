#pragma once
#ifndef __SLOT__
#define __SLOT__
#include "DisplayObject.h"

class Slot : public DisplayObject
{
public:
	Slot();
	~Slot();
	
	void draw() override;
	void update() override;
	void clean() override;
};

#endif /* defined (__SLOT__) */