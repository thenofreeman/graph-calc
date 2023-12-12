#pragma once

#include "Operator.h"

class BaseOperator : Operator
{
    public:
        BaseOperator(char, bool, int);
        virtual ~BaseOperator();

        bool isRightAssociative() const override;
        int comparePrecedence(const Operator&) const override;
        char getSymbol() const override;

    private:
        const char symbol;
        const bool rightAssociative;
        const int precedence;

    private:


};