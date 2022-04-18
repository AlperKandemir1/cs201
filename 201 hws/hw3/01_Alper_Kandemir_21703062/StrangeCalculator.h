#ifndef STRANGECALCULATOR_H
#define STRANGECALCULATOR_H
#include <iostream>
#include <string>

using namespace std;


class StrangeCalculator{

public:



    StrangeCalculator();
    StrangeCalculator(const StrangeCalculator& aStack);
    ~StrangeCalculator();
    

 
    bool isEmpty() const;
    bool push(string newItem);
    bool pop();
    bool pop(string& stackTop);
    bool getTop(string& stackTop) const;

    struct StackNode {            // a node on the stack
        string item;            // a data item on the stack
        StackNode *next;        // pointer to next node
    };

    StackNode *topPtr;     // pointer to first node in the stack
};
    int precedence(char ch);
    string infix2prefix( const string exp );
    string infix2Postfix( string infix);
    double evaluatePrefix( const string exp );
    bool isBalancedInfix( const string exp );
    void evaluateInputPrefixExpression( );

#endif 






