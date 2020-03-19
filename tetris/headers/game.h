//
// Created by mar on 19/03/2020.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>
#include "field.h"

class Game {
    sf::RenderWindow* window;
    sf::Event event;
    void init_window();
public:
    Game();
    ~Game();

    void update_event();
    void update();
    void render();
    void run();
};

#endif //TETRIS_GAME_H
