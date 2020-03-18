//
// Created by mar on 18/03/2020.
//

#ifndef SFML_FIELD_H
#define SFML_FIELD_H

#include <SFML/Graphics.hpp>
#include "figure.h"
#include "block.h"
#include <memory>

class Field {
    const int x = 10;
    const int y = 20;
    std::unique_ptr<std::vector<std::vector<Block>>> F;
public:
    Field();
};

#endif //SFML_FIELD_H
