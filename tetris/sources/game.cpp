//
// Created by mar on 19/03/2020.
//

#include "../headers/game.h"

void Game::init_window() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 6;
    // TODO add all settings into file/structure
    window = new sf::RenderWindow(sf::VideoMode(800, 800), "Tetris",
                            sf::Style::Close, settings);
}

void Game::init_user() {
    user = new User("name");
}

Game::Game() {
    init_window();
    init_user();
}

Game::~Game() {
    delete window;
    delete user;
}

void Game::update_dt() {
    dt = dt_clock.restart().asSeconds();
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
    user->update();
}

void Game::render() {
    window->clear(sf::Color::White);

    //some items
    user->render();
    Field field;
    field.display(*window);

    window->display();
}

void Game::run() {
    while (window->isOpen()) {
        update_dt();
        update();
        render();
    }
}



