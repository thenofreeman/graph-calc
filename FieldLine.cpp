#include <iostream>

#include "FieldLine.h"

FieldLine::FieldLine(sf::Vector2f tailPos, float magnitude, float direction)
    : tailPos{tailPos},
      magnitude{magnitude},
      direction{direction},
      useArrow{false},
      line{sf::Vector2f{2.f, magnitude}}
{ 
    line.setFillColor(sf::Color::Black);
    line.setPosition(tailPos);
    float trueDirection = 90 + direction;
    line.rotate(trueDirection);
}

FieldLine::~FieldLine()
{ }

void FieldLine::showArrow()
{
    useArrow = true;
}

void FieldLine::noArrow()
{
    useArrow = false;
}

void FieldLine::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // states.transform *= getTransform();
    target.draw(line, states);
}