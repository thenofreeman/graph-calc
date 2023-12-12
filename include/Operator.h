#pragma once

class Operator
{
    public:
        Operator() {}
        virtual ~Operator() = 0;

        virtual bool isRightAssociative() const = 0;
        virtual int comparePrecedence(const Operator&) const = 0;
        virtual char getSymbol() const = 0;

    private:

};