#include <iostream>

#include "Field.h"
#include "math.h"

Field::Field(sf::RenderWindow& window)
    : useArrows{false},
      xBounds{sf::Vector2f(-10.f, 10.f)},
      yBounds{sf::Vector2f(-10.f, 10.f)},
      density{1.f},
      stepSize{1.f, 1.f},
      window{&window}
{

    sf::Vector2f pos {xBounds.x, yBounds.x};

    float magnitude = 0.0;
    float direction = 0.0;

    while (pos.x <= xBounds.y)
    {
        while (pos.y <= yBounds.y)
        {
            sf::Vector2f relativePos{500 + pos.x*50, 500 + pos.y*50};
            magnitude = std::sqrt(pos.x*pos.x + pos.y*pos.y);

            float x_vect = f(pos.x, pos.y);
            float y_vect = g(pos.x, pos.y);

            direction = std::atan2(y_vect, x_vect) * 180/3.14159265;

            std::cout << "pos.x: " << pos.x << "   ";
            std::cout << "pos.y: " << pos.y << "   ";
            std::cout << "rel.x: " << relativePos.x << "    ";
            std::cout << "rel.y: " << relativePos.y << "    ";
            std::cout << "g: " << y_vect << "    ";
            std::cout << "f: " << x_vect << "    ";
            std::cout << "direc: " << direction << "    ";
            std::cout << "magnt: " << magnitude << std::endl;

            FieldLine* line = new FieldLine{relativePos, magnitude, direction};
            lines.push_back(line);

            pos.y += stepSize.y / density;
        }
        pos.y = yBounds.x;

        pos.x += stepSize.x / density;
    }
}

Field::~Field()
{ }

void Field::showArrows()
{
    useArrows = true;
}

void Field::noArrows()
{
    useArrows = false;
}

void Field::draw()
{
    for (FieldLine* line : lines)
    {
        window->draw(*line);
    }
}