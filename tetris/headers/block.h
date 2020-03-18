//
// Created by mar on 18/03/2020.
//

#ifndef SFML_BLOCK_H
#define SFML_BLOCK_H

#include <iostream>
#include <memory>
#include <map>
#include "figure.h"

struct Block {
    bool empty;
    FigureType type;
    Block();
    void set_empty();
};

#endif //SFML_BLOCK_H
