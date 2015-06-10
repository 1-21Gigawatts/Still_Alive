#include "onscreen_text.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System/Thread.hpp>
#include <string>

OnscreenText::OnscreenText(const std::string text, int x_position, int y_position, Game* game) {
    this->game = game;

    this->font.loadFromFile("resources/courier_new.ttf");
    this->color.r = 161; this->color.g = 135; this->color.b = 48;

    this->onscreen_text.setFont(font); this->onscreen_text.setColor(color);
    this->onscreen_text.setStyle(sf::Text::Bold);
    this->onscreen_text.setString(text);
    this->onscreen_text.setCharacterSize(14);

    this->x_pos = x_position; this->y_pos = y_position; // Set the coordinates for the text
    this->onscreen_text.setPosition(x_pos, y_pos);
}

void interval(int delay_msec) {
    sf::Clock clock;
    sf::Time elapsed = clock.getElapsedTime();

    while (elapsed.asMilliseconds() < delay_msec) {
        elapsed = clock.getElapsedTime();
    }
    return;
}

void OnscreenText::delayPrint(const int delay_msec) {
    const std::string placeholder = this->onscreen_text.getString();

    for (int n = 0; n < placeholder.size(); ++n) {
        this->onscreen_text.setString(placeholder[n]);
        this->onscreen_text.setPosition(x_pos+(9*n), y_pos);

        this->game->window.draw(this->onscreen_text);
        this->game->window.display();

        interval(delay_msec);
    }
    this->onscreen_text.setString(placeholder);
    this->onscreen_text.setPosition(x_pos, y_pos);

    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->onscreen_text);
    this->game->window.display();
}
