#include <iostream>

#include <SFML/Graphics.hpp>

#include "FieldPlot.h"

int main(int argc, char const *argv[])
{
    sf::RenderWindow window{sf::VideoMode(1000, 1000), "Vector Field Plot"};

    FieldPlot vectField(&window);

    vectField.enableArrows();

    // sf::Clock clock;

    // timePerFrame = sf::seconds(1.0f / 60.0f);
    // sf::Time timeSinceLastUpdate = sf::Time::Zero;

    window.setView(window.getDefaultView());

    while (window.isOpen())
    {
        window.clear(sf::Color::White);
        vectField.draw();
        window.display();
    }

    return 0;
}
