//
// Created by mar on 19/03/2020.
//

#ifndef TETRIS_USER_H
#define TETRIS_USER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <string>

class User {
    std::string name;
    int score;
public:
    User(std::string);
    ~User() = default;

    void update();
    void render();
};

#endif //TETRIS_USER_H
