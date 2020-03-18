//
// Created by mar on 18/03/2020.
//

#ifndef TETRIS_TETRAMINO_H
#define TETRIS_TETRAMINO_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <map>

enum TetraminoType {
    field, i, j, l, o, s, t, z
};

extern std::map<TetraminoType, sf::Color> TetraminoColor;

class Tetramino {
protected:
    TetraminoType type;
public:
    virtual void rotate() = 0;
    virtual ~Tetramino() = default;
};

class I : Tetramino {
public:
    I();
    void rotate() override;
    ~I() override = default;
};

#endif //TETRIS_TETRAMINO_H
