#include "FieldPlot.h"

FieldPlot::FieldPlot(sf::RenderWindow* window)
    : Plot{window, sf::Vector2u{1000, 1000}},
      stepSize{sf::Vector2f{50.f, 50.f}},
      lineWeight{2.f}
{ 
    setFunctions([](float x, float y) -> float { return y; }, 
                 [](float x, float y) -> float { return -x; });
    buildPlot();
}

FieldPlot::~FieldPlot()
{ }

void FieldPlot::enableArrows()
{
    showArrows = true;
}

void FieldPlot::disableArrows()
{
    showArrows = false;
}

void FieldPlot::setFunctionF(std::function<float(float, float)> f)
{
    this->f = f;
}

void FieldPlot::setFunctionG(std::function<float(float, float)> g)
{
    this->g = g;
}

void FieldPlot::setFunctions(std::function<float(float, float)> f, std::function<float(float, float)> g)
{
    this->f = f;
    this->g = g;
}

void FieldPlot::draw() const
{
    for (PlotLine* line : lines)
    {
        window->draw(*line);
    }
}

void FieldPlot::buildPlot()
{
    sf::Vector2f currentPos {globalBounds.left, globalBounds.top};
    float magnitude {0.0};
    float direction {0.0};

    while (currentPos.y <= globalBounds.height)
    {
        while (currentPos.x <= globalBounds.width)
        {
            sf::Vector2f relativePosition {currentPos.x, currentPos.y}; 
            magnitude = std::sqrt(std::pow(currentPos.x, 2) + std::pow(currentPos.y, 2));

            float x_vect = f(currentPos.x, currentPos.y);
            float y_vect = g(currentPos.x, currentPos.y);

            direction = std::atan2(y_vect, x_vect) * 180 / M_PI;

            // std::cout << "pos.x: " << pos.x << "   ";
            // std::cout << "pos.y: " << pos.y << "   ";
            // std::cout << "rel.x: " << relativePos.x << "    ";
            // std::cout << "rel.y: " << relativePos.y << "    ";
            // std::cout << "g: " << y_vect << "    ";
            // std::cout << "f: " << x_vect << "    ";
            // std::cout << "direc: " << direction << "    ";
            // std::cout << "magnt: " << magnitude << std::endl;

            PlotLine* line = new PlotLine(relativePosition, magnitude, direction, lineWeight);
            if (showArrows) line->enableArrow();
            lines.push_back(line);

            currentPos.x += stepSize.x;
        }
        currentPos.x = globalBounds.left;

        currentPos.y += stepSize.y;
    }
    
}