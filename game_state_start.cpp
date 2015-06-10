#include <SFML/Graphics.hpp>

#include "game_state_start.hpp"
#include "game_state.hpp"
#include "onscreen_text.hpp"

void GameStateStart::draw(const float dt)
{
    this->game->window.setView(this->view);

    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);

    OnscreenText s1("This was a triumph.", 15, 15, this->game); s1.delayPrint(110); interval(1950);
    OnscreenText s2("I'm making a note here:", 15, (1*18+15), this->game); s2.delayPrint(100);
    OnscreenText s3("HUGE SUCCESS.", 15, 2*18+15, this->game); s3.delayPrint(120);
    return;
}

void GameStateStart::handleInput()
{
    sf::Event event;

    while(this->game->window.pollEvent(event))
    {
        switch(event.type)
        {
            /* Close the window */
            case sf::Event::Closed:
            {
                game->window.close();
                break;
            }
            /* Resize the window */
            // NOTE: TOTALLY REDUNDANT, THIS WINDOW CANNOT BE RESIZED!!
            case sf::Event::Resized:
            {
                this->view.setSize(event.size.width, event.size.height);
                this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
                this->game->background.setScale(
                    float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
                    float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
                break;
            }
            case sf::Event::KeyPressed:
            {
                if(event.key.code == sf::Keyboard::Escape) this->game->window.close();
                break;
            }
            default: break;
        }
    }

    return;
}

GameStateStart::GameStateStart(Game* game)
{
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);
}
