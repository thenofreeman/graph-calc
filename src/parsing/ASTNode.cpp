#include "ASTNode.h"

ASTNode::ASTNode(char value, ASTNode* leftNode, ASTNode* rightNode)
    : value{value},
      leftNode{leftNode},
      rightNode{rightNode}
{ }

ASTNode::~ASTNode()
{ }

char ASTNode::getValue() const
{
    return value;
}

const ASTNode* const ASTNode::getLeftNode() const
{
    return leftNode;
}

const ASTNode* const ASTNode::getRightNode() const
{
    return rightNode;
}