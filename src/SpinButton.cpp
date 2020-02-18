#include "SpinButton.h"
#include "Game.h"

SpinButton::SpinButton()
	// call super constructor
	:Button(
		"../Assets/textures/SpinButton.png",
		"spinButton",
		SPIN_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{
	TheSoundManager::Instance()->load("../Assets/audio/jingle_18.flac", "jingle", SOUND_SFX);
}

SpinButton::~SpinButton()
{
}

bool SpinButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			TheSoundManager::Instance()->playSound("jingle", 0);
			SpinButton::Reels();
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}

std::vector<std::string> SpinButton::Reels()
{
	std::vector<std::string> betLine(3);//[]= {" "," "," "}; //result in each reel
	betLine[0]= " ";
	betLine[1]= " ";
	betLine[2]= " ";
	int outcome[]= {0,0,0}; //numerical value for each betLine
	
	for(int spin= 0; spin < 3; spin++)  //loops 3 times for each reel
	{
		outcome[spin] = floor((rand() % 65) + 1); //"random" whole number value between 1-65
		std::cout<<"Reel "<<spin+1<< ": "<<outcome[spin] << std::endl;

        if(outcome[spin] >= 1 && outcome[spin] <= 27) //value 1-27 = blank (41.5%)
        {
	        betLine[spin] = "blank";
        	blanks++;
        }
		if(outcome[spin] >= 28 && outcome[spin] <= 37) //value 28-37 = grape (15.4%)
		{
			betLine[spin] = "Grapes";
			grapes++;
		}
		if(outcome[spin] >= 38 && outcome[spin] <= 46) //value 38-46 = banana (13.8%)
		{
			betLine[spin] = "Banana";
			bananas++;
		}
		if(outcome[spin] >= 47 && outcome[spin] <= 54) //value 47-54 = orange (12.3%)
		{
			betLine[spin] = "Orange";
			oranges++;
		}
		if(outcome[spin] >= 55 && outcome[spin] <= 59) //value 55-59 = cherry (7.7%)
		{
			betLine[spin] = "Cherry";
			cherries++;
		}
		if(outcome[spin] >= 60 && outcome[spin] <= 62) //value 60-62 = bar (4.6%)
		{
			betLine[spin] = "Bar";
			bars++;
		}
		if(outcome[spin] >= 63 && outcome[spin] <= 64) //value 63-64 = bell (3.1%)
		{
			betLine[spin] = "Bell";
			bells++;
		}
		if(outcome[spin] == 65) //value 65 = seven (1.5%)
		{
			betLine[spin] = "Seven";
			sevens++;
		}
	}
	std::cout<<"Fruits: "<<betLine[0]<< " "<<betLine[1]<< " "<<betLine[2]<<std::endl;
	return betLine;
}
