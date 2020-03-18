//
// Created by mar on 18/03/2020.
//
#include "../headers/field.h"

Field::Field() {
    std::vector<std::vector<Block>> field(x);
    for (int i = 0 ; i < x ; ++i) {
        field[i].resize(y);
    }
    F = std::make_unique<std::vector<std::vector<Block>>>(field);
}

void Field::display_field(sf::RenderWindow &window) {
    const int block_size = 35;
    const int outline_size = 1;
    constexpr int full_block_size = block_size + 2 * outline_size;
    int x_margin = (window.getSize().x - full_block_size * x) / 2;
    int y_margin = (window.getSize().y - full_block_size * y) / 2;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            // TODO change for sprites
            sf::RectangleShape block(sf::Vector2f(block_size, block_size));
            block.setPosition(x_margin, y_margin);
            // TODO set color from type of block
            block.setFillColor(sf::Color(76, 111, 117));
            block.setOutlineThickness(outline_size);
            block.setOutlineColor(sf::Color::Black);
            block.move(i * full_block_size,
                       j * full_block_size);
            window.draw(block);
        }
    }
}
