#pragma once

// FieldPlot.h

#include <function>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Plot.h"
#include "PlotLine.h"

class FieldPlot : private Plot
{
    public:
        // Public Member Variables

    public:
        FieldPlot() = delete;
        FieldPlot(sf::RenderWindow& window);
        virtual ~FieldPlot();

        void enableArrows();
        void disableArrows();
        void setFunctionF(std::function f);
        void setFunctionG(std::function g);
        void setFunctions(std::function f, std::function g);

    private:
        bool showArrows;

        std::vector<PlotLine*> lines;
        std::function f;
        std::function g;

    private:
        // Private Methods

};