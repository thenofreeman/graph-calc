#pragma once

#include <SFML/Graphics.hpp>

class FieldLine : public sf::Drawable
{
    public:
        FieldLine(sf::Vector2f, float magnitude, float direction);
        ~FieldLine();

    private:
        sf::Vector2f tailPos;
        sf::Vector2f headPos;
        bool showArrow;
        float magnitude;
        float direction;

        sf::RectangleShape line;

    private: 
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


};