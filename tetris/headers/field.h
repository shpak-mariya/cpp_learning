//
// Created by mar on 18/03/2020.
//

#ifndef TETRIS_FIELD_H
#define TETRIS_FIELD_H

#include "tetramino.h"
#include "block.h"

class Field {
    const int x = 10;
    const int y = 20;
    std::unique_ptr<std::vector<std::vector<Block>>> F;
public:
    Field();
    ~Field() = default;

    void display(sf::RenderWindow&);
};

#endif //TETRIS_FIELD_H
