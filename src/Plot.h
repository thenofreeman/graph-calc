#pragma once

// Plot.h

#include <SFML/Graphics.hpp>

class Plot
{
    public:
        // Public Member Variables

    public:
        Plot() = delete;
        Plot(sf::RenderWindow* window, sf::Vector2u globalDimensions);
        virtual ~Plot();

        virtual void draw() const = 0;
        virtual void buildPlot() = 0;

    protected:
        sf::RenderWindow* window;
        sf::View view;
        sf::IntRect globalBounds; 

    private:
        // Private Methods

};