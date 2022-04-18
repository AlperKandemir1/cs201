#include "StrangeCalculator.h"
#include <algorithm>
using namespace std;
// default constructor


StrangeCalculator::StrangeCalculator() : topPtr(NULL){

}

// copy constructor
StrangeCalculator::StrangeCalculator(const StrangeCalculator& aStack){

   if (aStack.topPtr == NULL)
      topPtr = NULL;  // original stack is empty

   else {
      // copy first node
      topPtr = new StackNode;
      topPtr->item = aStack.topPtr->item;

      // copy rest of stack
      StackNode *newPtr = topPtr;
      for (StackNode *origPtr = aStack.topPtr->next;
                      origPtr != NULL;
                      origPtr = origPtr->next){
         newPtr->next = new StackNode;
         newPtr = newPtr->next;
         newPtr->item = origPtr->item;
      }
      newPtr->next = NULL;
   }
}

// destructor 
StrangeCalculator::~StrangeCalculator(){

   // pop until stack is empty
   while (!isEmpty())
      pop();

}

bool StrangeCalculator::isEmpty() const {

   return topPtr == NULL;

}

bool StrangeCalculator::push(string newItem) {

   // create a new node
   StackNode *newPtr = new StackNode;

   // set data portion  of new node
   newPtr->item = newItem;

   // insert the new node
   newPtr->next = topPtr;
   topPtr = newPtr;
   // cout << topPtr->item << endl;
   return true;
}

bool StrangeCalculator::pop() {

   if (isEmpty())
      return false;

   // stack is not empty; delete top
   else{   
      StackNode *temp = topPtr;
      topPtr = topPtr->next;

      // return deleted node to system
      temp->next = NULL;  // safeguard
      delete temp;
      return true;
   }
}

bool StrangeCalculator::pop(string& stackTop) {

   if (isEmpty())
      return false;

   // not empty; retrieve and delete top 
   else{
      stackTop = topPtr->item;
      StackNode *temp = topPtr;
      topPtr = topPtr->next;

      // return deleted node to system
      temp->next = NULL;  // safeguard
      delete temp;
      return true;
   }
}

bool StrangeCalculator::getTop(string& stackTop) 
             const {

   if (isEmpty())
      return false;

   // stack is not empty; retrieve top
   else {
      stackTop = topPtr->item;
      
      return true;
   }

}



//Global Functions ---------------------------------------------------------

int precedence(char ch){
    if (ch == '-' || ch == '+')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
        
    return 0;
    }
    
string infix2Postfix(string infix){
    StrangeCalculator* s = new StrangeCalculator();
    string stackTop;
//    s->push("+");
//    s->getTop(stackTop);
//    cout << stackTop;
    
    infix = '(' + infix + ')';
    int size = infix.size();
    
    string result="";
    //cout<<"size:"<<size;    
    for (int i = 0; i < size; i++) {
    //cout<<infix[i];
    //cout<<"infix:"<<infix[i];    
    // If it's a digit add to result
    if(isdigit(infix[i]))
        {
            result = result + infix[i];
            //cout<< result << endl;
        }
    
  
    // push ‘(‘ to the stack.   
    else if(infix[i]=='(')
        {
           s->push("(");
//           s->getTop(stackTop);
//           cout << stackTop;
        }
    // pop ‘)’ from the stack
    else if(infix[i]==')')
        {
            s->getTop(stackTop);
            while(stackTop[0] != '(' )
                {
                    
                    result = result + stackTop[0];
                    //cout<< result << endl;
                    s->pop();
                    //cout<<"*";
                    s->getTop(stackTop);
                }
                // Remove
                s->pop();            
        }
    // Operator    
    else
        {
            string a;
            s->getTop(stackTop);
            //cout<<stackTop<<endl;
            //cout<<"adsdas"<<endl;
            if(!isdigit(stackTop[0]) && stackTop[0]!='(' && stackTop[0] !=')')
            {
                //cout<<stackTop<<endl;
                while((precedence(infix[i]) <= precedence(stackTop[0])))
                    {
                    //cout<<stackTop[0];
                    //cout<<infix[i];
                    result = result + stackTop[0];
                    s->pop(stackTop);
                    s->getTop(stackTop);
                    }
            
            }           
            // Push current Operator on stack
            a = infix[i]; 
            s->push(a);
        }
    
    // stack = ( + *
    // rsult = 3 5 7
    }
    return result;
}

string infix2prefix(const string exp)
{
    StrangeCalculator* s = new StrangeCalculator();
    string infix=exp;
    string postfix = infix2Postfix(infix);
    string stackTop;
    int size = postfix.size();
    //cout<<postfix;
    string res="";
    for (int i = 0; i < size; i++) {
        if(!isdigit(postfix[i])){
            s->getTop(stackTop);   
            string str1=stackTop;
            s->pop();
            s->getTop(stackTop);   
            string str2=stackTop;
            s->pop();
            
            res =  str1+str2+ postfix[i]  ;
            s->push(res);
            }
        else{  
            string temp(1, postfix[i]);
            s->push(temp);
        }
    }        
    string result = "";
    while (!s->isEmpty()) {
        s->getTop(stackTop); 
        result += stackTop;
        s->pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

bool isBalancedInfix( const string exp ){
    StrangeCalculator* s = new StrangeCalculator();
    string stackTop;
    int size = exp.size();
    bool control = true;

    for(int i=0; i <size; i ++){
       
            
        if(exp[i]=='(')
            {
                //cout<<"*";
                s->push("(");
            }
        else if(exp[i]==')')
            {
                if(!s->isEmpty())
                    {
                        //cout<<"**";
                        s->pop();
                    }
                else
                    control= false;
            }
    }
    if(control && s->isEmpty() )
        return 1;
    else
        return 0;
}
//------------------------------------------------------------------------
double evaluatePrefix( const string exp ){
    StrangeCalculator* s = new StrangeCalculator();
    string stackTop;
    int size = exp.size();
    
    for(int i=size-1; i>=0; i--){
        
        if(!isdigit(exp[i])){
            //operator
            s->getTop(stackTop);   
            double first = stod(stackTop);
            s->pop();
            s->getTop(stackTop);   
            double second = stod(stackTop);
            s->pop();
            
            if(exp[i]=='+'){
                string temp=to_string(first + second);
                s->push(temp);
            }
            
            if(exp[i]=='-'){
                string temp=to_string(first - second);
                s->push(temp);
            }
            
            if(exp[i]=='*'){
                string temp=to_string(first * second);
                s->push(temp);
            }
            
            if(exp[i]=='/'){
                string temp=to_string(first / second);
                s->push(temp);
            }
        }
        else if(isdigit(exp[i])){
                string temp=to_string(exp[i]- '0');
                s->push(temp);
        }
    }
    s->getTop(stackTop);
    return stod(stackTop);
}

void evaluateInputPrefixExpression( ){
    string infix;
    cout<<"enter infix: \n";
    getline(cin,infix);
    int size = infix.size();
    for(int i=0; i <size; i ++){
        if(infix[i]==' '){
            infix.erase(i,1);
            }
    }
    //cout<< infix;
    if(isBalancedInfix(infix)){
        string temp = infix2prefix(infix);
        cout<<"result: "<<evaluatePrefix(temp)<<endl;
        }
    else
        cout<<"unbalanced input\n";
}