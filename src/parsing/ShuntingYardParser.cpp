#include "ShuntingYardParser.h"

ShuntingYardParser()
    : map{setOperations()},
    : constants{setConstants()},
      head{nullptr}
{ }

ShuntingYardParser::~ShuntingYardParser()
{ }

bool ShuntingYardParser::addNode(ASTNode* parent, ASTNode* leftNode, ASTNode* rightNode)
{
    bool nodeAdded { false };

    if (parent)
    {
        parent->setLeftNode(leftNode);
        parent->setRightNode(leftNode);
    }

    return nodeAdded;
}


void ShuntingYardParser::parseInfixToAST(const std::string input)
{
    std::stack<ASTNode> operators;
    std::queue<ASTNode> output;

    std::string::const_iterator it;
    for (it = input.begin(); it != input.end(); ++it)
    {
        switch (classifyToken(*it))
        {
            case TokenType::SPACE:
                break;
            case TokenType::NUMBER:
                std::ostringstream number;

                for (int i = 0; isdigit(*(it+i)); ++i)
                    number << *(it+i);

                output.push(new ASTNode(number.str(), TokenType::NUMBER));

                break;
            case TokenType::OPERATOR:
                TokenType opClass = classifyOperator(*it);
                while ((operators.top()->getType() != TokenType::OPERATOR) &&
                       (comparePrecedence(operators.top->getType(), opClass) > 0 ||
                        (comparePrecedence(operators.top->getType(), opClass) == 0 && 
                         getAssociativity(opClass) == Associativity::LEFT)))
                {
                    output.push(operators.pop());
                    operators.push(output.pop());
                }
            case TokenType::CHAR:
                std::ostringstream word;
                for (int i = 0; isalpha(*(it+i)); ++i)
                    word << *(it+i);

                if (classifyWord(word) == TokenType::VARIABLE)
                    output.push(new ASTNode(word.str(), TokenType::VARIABLE));
                else if (classifyWord(word) == TokenType::CONSTANT)
                    operators.push(new ASTNode(word.str(), TokenType::CONSTANT));
                else if (classifyWord(word) == TokenType::FUNCTION)
                    operators.push(new ASTNode(word.str(), TokenType::FUNCTION));
                    // TODO classifyConstant();
                    // TODO classifyFunction();
                if (word.str().length() == 1)
                else 

                break;
            case TokenType::LEFTPAREN:
                operators.push(new ASTNode("(", TokenType::LEFTPAREN));
                break;
            case TokenType::RIGHTPAREN:
                while (operators.top()->getType() != TokenType::LEFTPAREN)
                {
                    // assert: stack not empty
                    // !operators.empty()
                    output.push(operator.pop());
                }
                // assert: left paren on top of stack
                operators.pop(); // discard left parenthesis
                if (operators.top()->getType() == TokenType::FUNCTION)
                {
                    output.push(output.pop());
                }
                break;
            default:
                break;
        }
    }
    while (!operators.empty())
    {
        // assert: left paren NOT on top of stack
        output.push(operators.pop());
    }

/*
    ADTNode* next = output.front();
    while (next->getType() != TokenType::FUNCTION)
    {
        // TODO: add tokens to tree


        // assert: queue not empty
        // !output.empty()
        next = output.pop();
    }
    next = output.pop();
    classifyFunction(next);
*/
}

double ShuntingYardParser::evaluate(ASTNode* node) const
{
    TokenType nodeType { node->getType()};

    if (nodeType == TokenType::NUMBER)
        return std::stod(node->getValue());
    else if (nodeType == TokenType::CONSTANT)
        return contants[node->getValue()];
    else if (nodeType == TokenType::VARIABLE)
        return; // TODO: make variables work

    // TokenType::FUNCTION
    if (node->getLeftNode())
        if (node->getRightNode())
            return evaluateType(operationMap[nodeType](evaluate(node->getLeftNode()), evaluate(node->getRightNode())));
        else 
            return evaluateType(operationMap[nodeType](evaluate(node->getLeftNode()), 1.d));

    throw;

    /*
    long double output{};
    switch (node->getType())
    {
        case TokenType::PLUS:
            return evaluate(node->getLeftNode()) + evaluate(node->getRightNode());
        case TokenType::MINUS:
            return evaluate(node->getLeftNode()) - evaluate(node->getRightNode());
        case TokenType::MULT:
            return evaluate(node->getLeftNode()) * evaluate(node->getRightNode());
        case TokenType::DIVIDE:
            return evaluate(node->getLeftNode()) / evaluate(node->getRightNode());
        case TokenType::MODULO:
            return evaluate(node->getLeftNode()) % evaluate(node->getRightNode());
        case TokenType::POWER:
            return std::pow(evaluate(node->getLeftNode()), evaluate(node->getRightNode()));
        case TokenType::SINE:
            return std::sin(evaluate(node->getLeftNode()));
        case TokenType::COSINE:
            return std::cos(evaluate(node->getLeftNode()));
        case TokenType::TANGENT:
            return std::tan(evaluate(node->getLeftNode()));
        case TokenType::COSECANT:
            return std::csc(evaluate(node->getLeftNode()));
        case TokenType::SECANT:
            return std::sec(evaluate(node->getLeftNode()));
        case TokenType::COTANGENT:
            return std::cot(evaluate(node->getLeftNode()));
        case TokenType::ARCSIN:
            return std::asin2(evaluate(node->getLeftNode()));
        case TokenType::ARCCOS:
            return std::acos2(evaluate(node->getLeftNode()));
        case TokenType::ARCTAN:
            return std::atan2(evaluate(node->getLeftNode()));
        case TokenType::NUMBER:
            return;
        case TokenType::VARIABLE:
            return;
        case TokenType::LEFTPAREN:
            return;
        case TokenType::RIGHTPAREN:
            return;
        default:
            return std::stod(tree->getValue());
    }
    */

    return output;
}

static auto setOperations() -> std::map<TokenType, std::function<double(double, double)> >
{
    using namespace TokenType;

    std::map<TokenType, std::function<double(double, double)> > ops {
        {PLUS,   [](double a, double b) -> double { return (a + b)}}
        {MINUS,  [](double a, double b) -> double { return (a - b)}}
        {MULT,   [](double a, double b) -> double { return (a * b)}}
        {DIVIDE, [](double a, double b) -> double { return (a / b)}}
        {MODULO, [](double a, double b) -> double { return (a % b)}}
        {POWER,  [](double a, double b) -> double { return std::pow(a, b)}}
        {SIN,    [](double a, double b) -> double { return std::sin(a)}}
        {COS,    [](double a, double b) -> double { return std::cos(a)}}
        {TAN,    [](double a, double b) -> double { return std::tan(a)}}
        {ASIN,   [](double a, double b) -> double { return std::asin2(a)}}
        {ACOS,   [](double a, double b) -> double { return std::acos2(a)}}
        {ATAN,   [](double a, double b) -> double { return std::atan2(a)}}
        {CSC,    [](double a, double b) -> double { return std::csc(a)}}
        {SEC,    [](double a, double b) -> double { return std::sec(a)}}
        {COT,    [](double a, double b) -> double { return std::cot(a)}}
    };

    return std::move(ops);
}

static auto setConstants() -> std::map<std::string, double>
{
    using namespace TokenType;
    std::map<std::string, double> ops {
        {"pi", 3.14159265358979323846}
        {"PI", 3.14159265358979323846}
        {"e", 2.71828182845904523536}
        {"E", 2.71828182845904523536}
    }

}
