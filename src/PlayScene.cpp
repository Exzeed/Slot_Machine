#include "PlayScene.h"
#include "Game.h"
#include <ctime>
#include "glm/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

PlayScene::PlayScene()
{
	PlayScene::start();
}

PlayScene::~PlayScene()
{
}

void PlayScene::draw()
{
	m_pStartLabel->draw();
	m_pResetButton->draw();
	m_pQuitButton->draw();
	
	m_pSlotMachine->draw();
}

void PlayScene::update()
{
	m_pResetButton->setMousePosition(m_mousePosition);
	m_pResetButton->ButtonClick();
	m_pQuitButton->setMousePosition(m_mousePosition);
	m_pQuitButton->ButtonClick();
}

void PlayScene::clean()
{
	delete m_pStartLabel;
	
	removeAllChildren();
}

void PlayScene::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
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
				m_pResetButton->setMouseButtonClicked(true);
				m_pQuitButton->setMouseButtonClicked(true);
				break;
			case SDL_BUTTON_RIGHT:
				Game::Instance()->changeSceneState(END_SCENE);
				break;
			}
			break;
			
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pResetButton->setMouseButtonClicked(false);
				m_pQuitButton->setMouseButtonClicked(false);
				break;
			}
			break;
			
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			}
			break;

		default:
			break;
		}
	}
}

// this function is used for initialization
void PlayScene::start()
{
	SDL_Color yellow = { 255, 255, 0, 255 };
	m_pStartLabel = new Label("JACKPOT", "Consolas", 80, yellow, 
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.1f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pResetButton = new ResetButton();
	m_pResetButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.3f, Config::SCREEN_HEIGHT * 0.9f));
	addChild(m_pResetButton);

	m_pQuitButton = new QuitButton();
	m_pQuitButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.7f, Config::SCREEN_HEIGHT * 0.9f));
	addChild(m_pQuitButton);

	m_pSlotMachine= new Slot();
	addChild(m_pSlotMachine);
}

glm::vec2 PlayScene::getMousePosition()
{
	return m_mousePosition;
}
