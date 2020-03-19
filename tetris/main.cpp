#include "headers/game.h"

int main() {
    Field field;

    sf::ContextSettings settings;
//    settings.antialiasingLevel = 6;
    sf::RenderWindow window(sf::VideoMode(800, 800), "Tetris",
                            sf::Style::Close, settings);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.key.code == sf::Keyboard::Up) {
                // rotate
            }
        }
        window.clear(sf::Color::White);

        field.display_field(window);
        window.display();
    }
    return EXIT_SUCCESS;
}