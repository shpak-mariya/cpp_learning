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

I::I() {
    type = TetraminoType::i;
}

void I::rotate() {

}
