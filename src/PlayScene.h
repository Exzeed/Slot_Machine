#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Scene.h"
#include "Label.h"
#include "StartButton.h"

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
	Label* m_pStartLabel;
	StartButton* m_pStartButton;

	// private data member
	glm::vec2 m_mousePosition;
};

#endif /* defined (__START_SCENE__) */