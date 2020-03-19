//
// Created by mar on 18/03/2020.
//

#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H

#include <iostream>
#include <memory>
#include <map>
#include "tetramino.h"

struct Block {
    bool empty;
    TetraminoType type;

    Block();
    ~Block() = default;

    void set_empty();
};

#endif //TETRIS_BLOCK_H
