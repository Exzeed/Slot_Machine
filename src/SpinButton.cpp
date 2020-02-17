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
