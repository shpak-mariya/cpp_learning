#include <SFML/Graphics.hpp>
#include "headers/field.h"

int main() {
    Field field;

    sf::ContextSettings settings;
//    settings.antialiasingLevel = 6;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Figures",
                            sf::Style::Default, settings);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        window.display();
    }
    return EXIT_SUCCESS;
}