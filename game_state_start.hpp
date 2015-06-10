#ifndef GAME_STATE_START_HPP_INCLUDED
#define GAME_STATE_START_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "game_state.hpp"

class GameStateStart : public GameState
{
    private:

    sf::View view;

    public:

    virtual void draw(const float dt);
    virtual void handleInput();

    GameStateStart(Game* game);
};

#endif // GAME_STATE_START_HPP_INCLUDED
