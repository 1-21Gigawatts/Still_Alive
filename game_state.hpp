#ifndef GAME_STATE_HPP_INCLUDED
#define GAME_STATE_HPP_INCLUDED

#include "game.hpp"

class GameState
{
    public:

    Game* game;

    virtual void draw(const float dt) = 0;
    virtual void handleInput() = 0;
};

#endif // GAME_STATE_HPP_INCLUDED
