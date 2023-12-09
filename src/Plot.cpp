#include "Plot.h"

Plot::Plot(sf::RenderWindow* window, sf::Vector2u globalDimensions)
    : window{window},
      globalBounds{0, 0, globalDimensions.x, globalDimensions.y}
{ }

Plot::~Plot()
{ }