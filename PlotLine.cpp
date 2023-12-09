#include "PlotLine.h"

PlotLine::PlotLine(sf::Vector2f position, float length, float direction, float weight)
    : tailPos{position},
      length{length},
      weight{weight},
      showArrow{false},
      line{sf::Vector2f(weight, length)},
      arrowHead{length/5, length/5}
{
    this->setPosition(tailPos);
    this->setRotation(direction);

    line.setFillColor(sf::Color::Black);
    // line.setPosition(tailPos);
    // line.rotate(direction);

    headPos = sf::Vector2f{tailPos.x + length*std::cos(direction), tailPos.y + length*std::sin(direction)};

    arrowHead.setFillColor(sf::Color::Black);
    arrowHead.setOrigin(sf::Vector2f{length/5.f, 0.f});
    arrowHead.setPosition(headPos);
    // arrowHead.rotate(direction);
}

PlotLine::~PlotLine()
{ }

void PlotLine::enableArrow()
{
    arrowHead.setFillColor(sf::Color::Black);
    showArrow = true;
}

void PlotLine::disableArrow()
{
    arrowHead.setFillColor(sf::Color::Transparent);
    showArrow = false;
}

void PlotLine::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(line, states);
    target.draw(arrowHead, states);
}