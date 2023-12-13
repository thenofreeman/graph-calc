#pragma once

// ASTNode.h

#include "OperatorType.h"

class ASTNode
{
    public:
        ASTNode(std::string, TokenType);
        virtual ~ASTNode();

        const std::string getValue() const;
        const TokenType getType() const;
        const ASTNode* const getLeftNode() const;
        const ASTNode* const getRightNode() const;

        bool setLeftNode(ASTNode*);
        bool setRightNode(ASTNode*);

    private:
        const std::string value;
        const TokenType type;
        const ASTNode* leftNode;
        const ASTNode* rightNode;

};