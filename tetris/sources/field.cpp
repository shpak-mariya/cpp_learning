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

void Field::display(sf::RenderWindow& window) {
    // TODO hide const values (setting values) into other structure
    const int block_size = 35;
    const int outline_size = 1;
    constexpr int full_block_size = block_size + 2 * outline_size;
    float x_margin = (window.getSize().x - full_block_size * x) / 2;
    float y_margin = (window.getSize().y - full_block_size * y) / 2;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            // TODO change for sprites
            sf::RectangleShape block(sf::Vector2f(block_size, block_size));
            block.setPosition(x_margin, y_margin);
            // TODO fix ugly reference
            block.setFillColor(TetraminoColor[(*(F.get()))[i][j].type]);
            block.setOutlineThickness(outline_size);
            block.setOutlineColor(sf::Color::Black);
            block.move(i * full_block_size,
                       j * full_block_size);
            window.draw(block);
        }
    }
}
