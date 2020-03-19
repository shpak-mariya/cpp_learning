//
// Created by mar on 19/03/2020.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "field.h"
#include "User.h"

class Game {
    // SFML elements
    sf::RenderWindow* window;
    sf::Event event;
    sf::Clock dt_clock;
    float dt;
    User* user;

    void init_window();
    void init_user();
public:
    Game();
    ~Game();

    void update_dt();
    void update_event();
    void update();
    void render();
    void run();
};

#endif //TETRIS_GAME_H
