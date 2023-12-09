#pragma once

// FieldPlot.h

#include <functional>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Plot.h"
#include "PlotLine.h"

class FieldPlot : protected Plot
{
    public:
        // Public Member Variables

    public:
        FieldPlot() = delete;
        FieldPlot(sf::RenderWindow* window);
        virtual ~FieldPlot();

        void enableArrows();
        void disableArrows();
        void setFunctionF(std::function<float(float, float)> f);
        void setFunctionG(std::function<float(float, float)> g);
        void setFunctions(std::function<float(float, float)> f, 
                          std::function<float(float, float)> g);

        void draw() const;
        void buildPlot();

    private:
        bool showArrows;

        std::vector<PlotLine*> lines;
        std::function<float(float, float)> f;
        std::function<float(float, float)> g;

        sf::Vector2f stepSize;
        float lineWeight;

    private:
        // Private Methods

};