#include "ASTNode.h"

ASTNode::ASTNode(std::string value, TokenType type)
    : value{value},
      type{type},
      leftNode{nullptr},
      rightNode{nullptr}
{ }

ASTNode::~ASTNode()
{ }

const TokenType ASTNode::getType() const
{
    return type;
}

const std::string getValue() const
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

bool ASTNode::setLeftNode(ASTNode* node)
{
    bool nodeSet { false }; // TODO: Conditionally set nodeSet variable

    leftNode = node;

    return nodeSet;
}

bool ASTNode::setRightNode(ASTNode* node)
{
    bool nodeSet { false }; // TODO: Conditionally set nodeSet variable

    rightNode = node;

    return nodeSet;
}