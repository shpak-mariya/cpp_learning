//
// Created by mar on 18/03/2020.
//
#include "../headers/field.h"

Field::Field() {
    std::vector<std::vector<Block>> field(x);
    for (int i = 0 ; i < x ; ++i)
        field[i].resize(y);
    F = std::make_unique<std::vector<std::vector<Block>>>(field);
}
