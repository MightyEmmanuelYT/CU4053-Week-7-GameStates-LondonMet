#include "Menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs)
{
	window = hwnd;
	input = in;
	gameState = gs;

	if(!font.loadFromFile("font/go3v2.ttf"))
	{
		std::cout << "Font did not load\n";
	}

	MenuText.setFont(font);
	MenuText.setCharacterSize(24);
	MenuText.setPosition(100, 100);
	//MenuText.setColor(sf::Color::Black);
	MenuText.setFillColor(sf::Color::Red);
	MenuText.setString("You are In Menu \n Press Enter to \n Load the Level");
}

Menu::~Menu()
{
}

void Menu::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Return))
	{
		input->setKeyUp(sf::Keyboard::Return);
		gameState->setCurrentState(State::LEVEL);
	}
}

void Menu::update(float dt)
{
}

void Menu::render()
{
	beginDraw();

	window->draw(MenuText);

	endDraw();
}
