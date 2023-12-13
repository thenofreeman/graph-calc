#pragma once

// ShuntingYardParser.h

#include <map>
#include <stack>
#include <string>
#include <vector>

#include "ASTNode.h"
#include "Operator.h"

class ShuntingYardParser
{
    public:
        ShuntingYardParser(std::vector<Operator>);
        ~ShuntingYardParser();

        void parseInfixToAST(const std::string);

    private:
        const std::map<TokenType, std::function<double(double, double)> > operations;
        const std::map<std::string, double> constants;
        ASTNode head;

    private:
        double evaluate(ASTNode*) const;
        bool addNode(ASTNode*, ASTNode*, ASTNode*);

};