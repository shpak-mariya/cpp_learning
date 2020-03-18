//
// Created by mar on 18/03/2020.
//

#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H


enum FigureType {
    field, i, j, l, o, s, t, z
};

//std::map<FigureType, sf::Color> BlockColors = {
//        {field, sf::Color::White},
//        {i, sf::Color(0, 240, 240)},
//        {j, sf::Color(0, 0, 240)},
//        {l, sf::Color(240, 160, 240)},
//        {o, sf::Color(240, 240, 0)},
//        {s, sf::Color(0, 240, 0)},
//        {t, sf::Color(160, 0, 240)},
//        {z, sf::Color(240, 0, 0)}
//};

class TetrisFigure {
    FigureType type;
public:
    explicit TetrisFigure(FigureType);
    virtual void rotate() = 0;
    virtual ~TetrisFigure() = default;
};

class I : TetrisFigure {
public:
    void rotate() override;
    ~I() override = default;
};

#endif //TETRIS_FIGURE_H
