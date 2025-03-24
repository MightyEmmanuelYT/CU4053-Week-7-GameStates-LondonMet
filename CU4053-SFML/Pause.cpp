#include "Pause.h"

Pause::Pause(sf::RenderWindow* hwnd, Input* in, GameState* gs)
{
	window = hwnd;
	input = in;
	gameState = gs;

	if (!font.loadFromFile("font/go3v2.ttf"))
	{
		std::cout << "Font did not load\n";
	}

	PauseText.setFont(font);
	PauseText.setCharacterSize(24);
	PauseText.setPosition(100, 100);
	//PauseText.setColor(sf::Color::Black);
	PauseText.setFillColor(sf::Color::Black);
	PauseText.setString("You are In Pause Menu \n Press Escapse to \n Load the Pause Menu");
}

Pause::~Pause()
{
}

void Pause::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		gameState->setCurrentState(State::LEVEL);
	}
}

void Pause::update(float dt)
{
}

void Pause::render()
{
	beginDraw();

	window->draw(PauseText);

	endDraw();
}
