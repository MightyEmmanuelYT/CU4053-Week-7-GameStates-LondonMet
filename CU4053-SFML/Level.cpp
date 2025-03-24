#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs)
{
	window = hwnd;
	input = in;
	gameState = gs;

	if (!font.loadFromFile("font/go3v2.ttf"))
	{
		std::cout << "Font did not load\n";
	}

	LevelText.setFont(font);
	LevelText.setCharacterSize(24);
	LevelText.setPosition(100, 100);
	//LevelText.setColor(sf::Color::Black);
	LevelText.setFillColor(sf::Color::Black);
	LevelText.setString("You are In Level \n Press Spacebar to \n Load the Credits Menu \n \n Press Escape to \n Load Pause Menu");

	// initialise game objects

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		gameState->setCurrentState(State::PAUSE);
	}
	else if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		gameState->setCurrentState(State::CREDITS);
	}
}

// Update game objects
void Level::update(float dt)
{
	
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(LevelText);

	endDraw();
}
