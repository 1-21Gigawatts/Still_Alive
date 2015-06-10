#ifndef ONSCREEN_TEXT_HPP_INCLUDED
#define ONSCREEN_TEXT_HPP_INCLUDED

#include <string>
#include "game.hpp"

class OnscreenText {
    private:
        sf::Text onscreen_text;
        int x_pos, y_pos;
        sf::Font font;
        sf::Color color;
    public:
        Game* game;
        OnscreenText(const std::string text, int x_position, int y_position, Game* game);
        void delayPrint(const int delay_msec);
};

void interval(int delay_msec);

#endif // ONSCREEN_TEXT_HPP_INCLUDED
