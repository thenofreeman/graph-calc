#pragma once

// Plot.h

#include <SFML/Graphics.hpp>

class Plot
{
    public:
        // Public Member Variables

    public:
        Plot() = delete;
        virtual ~Plot();

        virtual void draw() = 0;

    private:
        sf::RenderWindow* window;
        sf::View view;

    private:
        // Private Methods

};