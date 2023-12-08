#pragma once

// PlotLine.h

#include <SFML/Graphics.hpp>

class PlotLine : public sf::Drawable
{
    public:
        // Public Member Variables

    public:
        PlotLine() = delete;
        PlotLine(/*...*/); // TODO: Missing arguments
        virtual ~PlotLine();

        void enableArrow();
        void disableArrow();
        void setPosition();
        void setPosition();
    
    private:
        sf::Vector2f tailPos;
        sf::Vector2f headPos;
        float length;
        float direction;
        bool showArrow;

        sf::RectangleShape line;
        sf::RectangleShape leftArrowHead;
        sf::RectangleShape rightArrowHead;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};