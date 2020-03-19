//
// Created by mar on 19/03/2020.
//

#include "../headers/game.h"

void Game::init_window() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 6;
    window = new sf::RenderWindow(sf::VideoMode(800, 800), "Tetris",
                            sf::Style::Close, settings);
}

Game::Game() {
    init_window();
}

Game::~Game() {
    delete window;
}

void Game::update_event() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.key.code == sf::Keyboard::Up) {
            // rotate
        }
    }
}

void Game::update() {
    update_event();
}

void Game::render() {
    window->clear(sf::Color::White);

    //some items
    Field field;
    field.display_field(*window);

    window->display();
}

void Game::run() {
    while (window->isOpen()) {
        update();
        render();
    }
}




