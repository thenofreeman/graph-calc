#include "SFMLX/TriangleShape.h"

namespace sf
{

TriangleShape::TriangleShape(float height, float width)
    : triangleVertex{sf::Triangles, 3}
{
    triangleVertex[0].position = sf::Vector2f(0.f, 0.f);
    triangleVertex[1].position = sf::Vector2f(width/2.f, height);
    triangleVertex[2].position = sf::Vector2f(width, 0.f);

    setFillColor(sf::Color::Black);
}

TriangleShape::~TriangleShape()
{ }

void TriangleShape::setFillColor(sf::Color color)
{
    triangleVertex[0].color = color;
    triangleVertex[1].color = color;
    triangleVertex[2].color = color;
}

void TriangleShape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(triangleVertex, states);
}

}