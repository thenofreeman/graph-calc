#include <iostream>

#include "FieldLine.h"

FieldLine::FieldLine(sf::Vector2f tailPos, float magnitude, float direction)
    : tailPos{tailPos},
      magnitude{magnitude},
      direction{direction},
      showArrow{false},
      line{sf::Vector2f{3.f, magnitude}}
{ 
    line.setFillColor(sf::Color::Black);
    line.setPosition(tailPos);
    line.rotate(-direction);
}

FieldLine::~FieldLine()
{ }

void FieldLine::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // states.transform *= getTransform();
    target.draw(line, states);
}