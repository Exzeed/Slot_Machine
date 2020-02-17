#include "Slot.h"
#include "Game.h"

Slot::Slot()
{
	TheTextureManager::Instance()->load("../Assets/textures/slot_machine.png",
		"slot", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("slot");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	setIsColliding(false);
	setType(GameObjectType::SLOT);
}

Slot::~Slot()
{
}

void Slot::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("slot", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Slot::update()
{
}

void Slot::clean()
{
}
