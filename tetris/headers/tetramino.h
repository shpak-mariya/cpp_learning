//
// Created by mar on 18/03/2020.
//

#ifndef TETRIS_TETRAMINO_H
#define TETRIS_TETRAMINO_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <map>
#include <vector>

enum TetraminoType {
    field, i, j, l, o, s, t, z
};

extern std::map<TetraminoType, sf::Color> TetraminoColor;

class Tetramino {
    TetraminoType type;
    std::vector<bool> scheme;
public:
    Tetramino();
    void rotate();
};
#endif //TETRIS_TETRAMINO_H
