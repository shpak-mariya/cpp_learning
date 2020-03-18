//
// Created by mar on 18/03/2020.
//

#ifndef SFML_BLOCK_H
#define SFML_BLOCK_H

#include <iostream>
#include <memory>
#include <map>
#include "tetramino.h"

struct Block {
    bool empty;
    TetraminoType type;
    Block();
    void set_empty();
};

#endif //SFML_BLOCK_H
