#pragma once

// PlotLine.h

#include <math.h>

#include <SFML/Graphics.hpp>

#include "SFMLX/TriangleShape.h"

class PlotLine : public sf::Drawable, public sf::Transformable
{
    public:
        // Public Member Variables

    public:
        PlotLine() = delete;
        PlotLine(sf::Vector2f position, float length, float direction, float weight);
        virtual ~PlotLine();

        void enableArrow();
        void disableArrow();
    
    private:
        sf::Vector2f tailPos;
        sf::Vector2f headPos;
        float length;
        float weight;
        bool showArrow;

        sf::RectangleShape line;
        sf::TriangleShape arrowHead;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};