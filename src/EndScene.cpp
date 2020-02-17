#include "EndScene.h"
#include "Game.h"
#include <ctime>
#include "glm/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

EndScene::EndScene()
{
	EndScene::start();
}

EndScene::~EndScene()
{
}

void EndScene::draw()
{
	m_pEndLabel->draw();
	m_pQuitButton->draw();
}

void EndScene::update()
{
	m_pQuitButton->setMousePosition(m_mousePosition);
	m_pQuitButton->ButtonClick();
}

void EndScene::clean()
{
	delete m_pEndLabel;
	removeAllChildren();
}

void EndScene::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;

			case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pQuitButton->setMouseButtonClicked(true);
				break;
			}
			break;

		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pQuitButton->setMouseButtonClicked(false);
				break;
			}
			break;
			
		default:
			break;
		}
	}
}

void EndScene::start()
{
	SDL_Color red = { 255, 0, 0, 255 };
	m_pEndLabel = new Label("GAME OVER", "Consolas", 80, red, 
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.3f));
	m_pEndLabel->setParent(this);
	addChild(m_pEndLabel);

	m_pQuitButton = new QuitButton();
	m_pQuitButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	addChild(m_pQuitButton);
}

glm::vec2 EndScene::getMousePosition()
{
	return m_mousePosition;
}