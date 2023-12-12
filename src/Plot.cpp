#include "Plot.h"

Plot::Plot(sf::RenderWindow* window, sf::IntRect globalBounds)
    : window{window},
      globalBounds{globalBounds}
{ }

Plot::~Plot()
{ }