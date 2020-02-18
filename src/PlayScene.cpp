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
	m_pJackpotLabel->draw();
	m_pMoneyLabel->draw();
	m_pBetLabel->draw();
	m_pResultLabel->draw();
	
	m_pResetButton->draw();
	m_pQuitButton->draw();
	m_pSpinButton->draw();
	
	m_pSlotMachine->draw();
	m_pReelLeft->draw();
	m_pReelMid->draw();
	m_pReelRight->draw();
}

void PlayScene::update()
{
	m_pResetButton->setMousePosition(m_mousePosition);
	m_pResetButton->ButtonClick();
	m_pQuitButton->setMousePosition(m_mousePosition);
	m_pQuitButton->ButtonClick();
	m_pSpinButton->setMousePosition(m_mousePosition);
	m_pSpinButton->ButtonClick();
}

void PlayScene::clean()
{
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
				m_pSpinButton->setMouseButtonClicked(true);
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
				m_pSpinButton->setMouseButtonClicked(false);
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
	m_pJackpotLabel = new Label("JACKPOT", "Consolas", 80, yellow, 
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.1f));
	m_pJackpotLabel->setParent(this);
	addChild(m_pJackpotLabel);

	SDL_Color black = { 0, 0, 0, 255 };
	m_pMoneyLabel = new Label("Player Money", "Consolas", 36, black, 
		glm::vec2(Config::SCREEN_WIDTH * 0.2f, Config::SCREEN_HEIGHT * 0.2f));
	m_pMoneyLabel->setParent(this);
	addChild(m_pMoneyLabel);

	m_pBetLabel = new Label("Bet Amount", "Consolas", 36, black, 
		glm::vec2(Config::SCREEN_WIDTH * 0.2f, Config::SCREEN_HEIGHT * 0.8f));
	m_pBetLabel->setParent(this);
	addChild(m_pBetLabel);

	m_pResultLabel = new Label("Result", "Consolas", 36, black, 
		glm::vec2(Config::SCREEN_WIDTH * 0.7f, Config::SCREEN_HEIGHT * 0.8f));
	m_pResultLabel->setParent(this);
	addChild(m_pResultLabel);

	m_pResetButton = new ResetButton();
	m_pResetButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.2f, Config::SCREEN_HEIGHT * 0.9f));
	addChild(m_pResetButton);

	m_pQuitButton = new QuitButton();
	m_pQuitButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.8f, Config::SCREEN_HEIGHT * 0.9f));
	addChild(m_pQuitButton);

	m_pSpinButton= new SpinButton();
	m_pSpinButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.9f));
	addChild(m_pSpinButton);

	m_pSlotMachine= new Slot();
	addChild(m_pSlotMachine);

	m_pReelRight= new Reel();
	m_pReelRight->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.26f, Config::SCREEN_HEIGHT * 0.5f));
	addChild(m_pReelRight);
	m_pReelMid= new Reel();
	addChild(m_pReelMid);
	m_pReelLeft= new Reel();
	m_pReelLeft->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.74f, Config::SCREEN_HEIGHT * 0.5f));
	addChild(m_pReelLeft);
}

glm::vec2 PlayScene::getMousePosition()
{
	return m_mousePosition;
}
