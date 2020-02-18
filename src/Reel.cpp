#include "Reel.h"
#include "Game.h"

Reel::Reel()
{
	TheTextureManager::Instance()->load("../Assets/textures/question_mark.png",
		"reel", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("reel");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	setIsColliding(false);
	setType(GameObjectType::REEL);
}

Reel::~Reel()
{
}

void Reel::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("reel", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Reel::update()
{
}

void Reel::clean()
{
}
