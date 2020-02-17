#pragma once
#ifndef __END_SCENE__
#define __END_SCENE__

#include "Scene.h"
#include "Label.h"
#include "QuitButton.h"
#include "ResetButton.h"

class EndScene : public Scene
{
public:
	EndScene();
	~EndScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	Label* m_pEndLabel;
	QuitButton* m_pQuitButton;
	ResetButton* m_pResetButton;

	// private data member
	glm::vec2 m_mousePosition;
};

#endif /* defined (__END_SCENE__) */