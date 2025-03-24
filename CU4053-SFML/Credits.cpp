#include "Credits.h"

Credits::Credits(sf::RenderWindow* hwnd, Input* in, GameState* gs)
{
	window = hwnd;
	input = in;
	gameState = gs;

	if (!font.loadFromFile("font/go3v2.ttf"))
	{
		std::cout << "Font did not load\n";
	}

	CreditsText.setFont(font);
	CreditsText.setCharacterSize(24);
	CreditsText.setPosition(100, 100);
	//CreditsText.setColor(sf::Color::Black);
	CreditsText.setFillColor(sf::Color::Magenta);
	CreditsText.setString("You are In Credits \n Press Spacebar to \n Load the Menu \n Press Escape to \n Quit Game");
}

Credits::~Credits()
{
}

void Credits::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		gameState->setCurrentState(State::MENU);
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		exit(0);
	}
}

void Credits::update(float dt)
{
}

void Credits::render()
{
	beginDraw();

	window->draw(CreditsText);

	endDraw();
}
