//
// Created by mar on 18/03/2020.
//
#include "../headers/block.h"

Block::Block() : empty(true), type(FigureType::field) {}

void Block::set_empty() {
    empty = false;
    type = FigureType::field;
}
