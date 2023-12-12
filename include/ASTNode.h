#pragma once

// ASTNode.h

class ASTNode
{
    public:
        ASTNode(char, ASTNode*, ASTNode*);
        virtual ~ASTNode();

        char getValue() const;
        const ASTNode* const getLeftNode() const;
        const ASTNode* const getRightNode() const;


    private:
        const char value;
        const ASTNode* const leftNode;
        const ASTNode* const rightNode;

};