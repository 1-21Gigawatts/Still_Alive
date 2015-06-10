#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <stack>    // Data structure for holding GameStates
#include <SFML/Graphics.hpp>

#include "texture_manager.hpp"

class GameState;

class Game
{
	private:

	void loadTextures();

    public:

    std::stack<GameState*> states;  // A stack of addresses of GameStates

    sf::RenderWindow window;
	TextureManager texmgr;
	sf::Sprite background;

    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);
    GameState* peekState(); // Returns a pointer to the current GameState

    void gameLoop();

    Game();
    ~Game();
};

#endif // GAME_HPP_INCLUDED
