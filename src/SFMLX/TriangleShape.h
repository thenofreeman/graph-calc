#pragma once

// Triangle.h

#include <SFML/Graphics.hpp>

namespace sf 
{

class TriangleShape : public sf::Drawable, public sf::Transformable
{
    public:
        // Public Member Variables

    public:
        // Public Member functions
        TriangleShape() = delete;
        TriangleShape(float height, float width);
        virtual ~TriangleShape();

        void setFillColor(sf::Color color);

    private:
        sf::VertexArray triangleVertex;
        sf::Vector2f dimensions;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

}