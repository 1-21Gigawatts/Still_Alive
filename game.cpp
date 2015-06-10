#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game.hpp"
#include "game_state.hpp"
#include "texture_manager.hpp"

void Game::loadTextures()   // Uses the texture manager to load textures into memory
{
    texmgr.loadTexture("background", "resources/background.png");
}

void Game::pushState(GameState* state)
{
    this->states.push(state);

    return;
}

void Game::popState()
{
    delete this->states.top();
    this->states.pop();

    return;
}

void Game::changeState(GameState* state)
{
    if(!this->states.empty())
        popState();
    pushState(state);

    return;
}

GameState* Game::peekState()
{
    if(this->states.empty()) return nullptr;
    return this->states.top();
}

void Game::gameLoop()
{
    sf::Clock clock;

    while(this->window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if(peekState() == nullptr) continue;
        peekState()->handleInput(); // The current state should handleInput
        this->window.clear(sf::Color::Black);
        peekState()->draw(dt);
        this->window.display();
    }
}

Game::Game()
{
    this->loadTextures();

    this->window.create(sf::VideoMode(935, 680), "Still Alive", sf::Style::Titlebar | sf::Style::Close);
    this->window.setFramerateLimit(60);

    this->background.setTexture(this->texmgr.getRef("background"));
}

Game::~Game()
{
    while(!this->states.empty()) popState();
}
