#pragma once

#include <vector>
#include <math.h>

#include <SFML/Graphics.hpp>

#include "FieldLine.h"

class Field
{
    public:
        Field(sf::RenderWindow& window);
        ~Field();

        void showArrows();
        void noArrows();

        void draw();

    private:

        bool useArrows;
        sf::Vector2f xBounds;
        sf::Vector2f yBounds;
        float density;
        sf::Vector2f stepSize;

        std::vector<FieldLine*> lines;

        sf::RenderWindow* window;

    private:
        float f(double x, double y)
        {
            return sin(x);
        }
        float g(double x, double y)
        {
            return sin(y);
        }

};