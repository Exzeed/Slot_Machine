#pragma once
#ifndef __SPIN_BUTTON__
#define __SPIN_BUTTON__

#include "Button.h"

class SpinButton : public Button
{
public:
	SpinButton();
	~SpinButton();

	bool ButtonClick() override;
	std::vector<std::string> Reels();

	static const int playerMoney = 1000;
	static const int jackpot= 5000;
	static const int playerBet= 1;

	int grapes = 0;
	int bananas = 0;
	int oranges = 0;
	int cherries = 0;
	int bars = 0;
	int bells = 0;
	int sevens = 0;
	int blanks = 0;
	
private:
	bool m_isClicked;
};

#endif /* defined (__SPIN_BUTTON__) */