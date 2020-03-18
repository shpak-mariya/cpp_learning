//
// Created by mar on 18/03/2020.
//

#include "../headers/tetramino.h"

std::map<TetraminoType, sf::Color> TetraminoColor = {
        {TetraminoType::field, sf::Color(76, 111, 117)},
        {TetraminoType::i, sf::Color(0, 240, 240)},
        {TetraminoType::j, sf::Color(0, 0, 240)},
        {TetraminoType::l, sf::Color(240, 160, 240)},
        {TetraminoType::o, sf::Color(240, 240, 0)},
        {TetraminoType::s, sf::Color(0, 240, 0)},
        {TetraminoType::t, sf::Color(160, 0, 240)},
        {TetraminoType::z, sf::Color(240, 0, 0)}
};


Tetramino::Tetramino() {
    int r = std::rand() % 7 + 1;
    type = static_cast<TetraminoType>(r);
    switch (r) {
    case 1: // i
        scheme = {true, true, true, true, false, false, false, false};
        break;
    case 2: // j
        scheme = {true, false, false, false, true, true, true, false};
        break;
    case 3: // l
        scheme = {false, false, true, false, true, true, true, false};
        break;
    case 4: // o
        scheme = {true, true, false, false, true, true, false, false};
        break;
    case 5: // s
        scheme = {false, true, true, false, true, true, false, false};
        break;
    case 6: // t
        scheme = {false, true, false, false, true, true, true, false};
        break;
    case 7: // z
        scheme = {true, true, false, false, false, true, true, false};
        break;
    }
}

void Tetramino::rotate() {

}
