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

//std::map<FigureType, sf::Color> FigureColor = {
//        {FigureType::field, sf::Color::White},
//        {FigureType::i, sf::Color(0, 240, 240)},
//        {FigureType::j, sf::Color(0, 0, 240)},
//        {FigureType::l, sf::Color(240, 160, 240)},
//        {FigureType::o, sf::Color(240, 240, 0)},
//        {FigureType::s, sf::Color(0, 240, 0)},
//        {FigureType::t, sf::Color(160, 0, 240)},
//        {FigureType::z, sf::Color(240, 0, 0)}
//};

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
