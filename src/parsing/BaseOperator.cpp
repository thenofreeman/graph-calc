#include "BaseOperator.h"

BaseOperator::BaseOperator(char symbol, bool rightAssociative, int precedence)
    : symbol{symbol},
      rightAssociative{rightAssociative},
      precedence{precedence}
{ }

BaseOperator::~BaseOperator()
{ }

bool BaseOperator::isRightAssociative() const
{
    return rightAssociative;
}

int BaseOperator::comparePrecedence(const Operator& op) const
{
    int precedenceCode { 0 };

    const BaseOperator* baseOp = dynamic_cast<const BaseOperator*>(&op);
    if(baseOp)
    {
        if (this->precedence > baseOp->precedence) 
            precedenceCode = 1;
        else if (baseOp->precedence == this->precedence) 
            precedenceCode = 0;
        else 
            precedenceCode = -1;
    }
    else
    {
        precedenceCode = -op.comparePrecedence(*this);
    }

    return precedenceCode;
}

char BaseOperator::getSymbol() const
{
    return symbol;
}