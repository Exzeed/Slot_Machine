#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Scene.h"
#include "Label.h"
#include "ResetButton.h"
#include "QuitButton.h"
#include "SpinButton.h"
#include "Slot.h"
#include "Reel.h"

class PlayScene : public Scene
{
public:
	// constructor
	PlayScene();
	// destructor
	~PlayScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// Game Objects
	Label* m_pJackpotLabel;
	Label* m_pMoneyLabel;
	Label* m_pBetLabel;
	Label* m_pResultLabel;
	
	ResetButton* m_pResetButton;
	QuitButton* m_pQuitButton;
	SpinButton* m_pSpinButton;
	
	Slot* m_pSlotMachine;
	Reel* m_pReelLeft;
	Reel* m_pReelRight;
	Reel* m_pReelMid;

	// private data member
	glm::vec2 m_mousePosition;
};

#endif /* defined (__PLAY_SCENE__) */