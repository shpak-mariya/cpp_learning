//
// Created by mar on 18/03/2020.
//
#include "../headers/block.h"

Block::Block() : empty(true), type(TetraminoType::field) {}

void Block::set_empty() {
    empty = false;
    type = TetraminoType::field;
}
