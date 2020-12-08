#include <iostream>
#include <stack>
#include <string>
#include <cstddef>
#include <limits>

using namespace std;


/**
 * Class containing the data and functions for a single node in an expression tree
 * 
 * @param type - stores the type of the node, it can either be {0 : (operator), 1: (operand)}
 * @param operator_ - stores the operator, values can be {+, -, *, /}. Present only if type is 0
 * @param operand_ - stores the operand, the value is a non-negetive integers. Present only if type is 1
 * @param left - link to the left child of the node
 * @param right - link to the right child of the node
*/
class ExprNode {
private:
	int type;
	char operator_;
	unsigned int operand_;
	ExprNode *left, *right;

public:
	/* Constructor definitions */
	ExprNode(unsigned int operand) {
		type = 1;
		operand_ = operand;
		operator_ = 0;
		left = NULL;
		right = NULL;
	}

	ExprNode(char op) {
		if (op == '+' || op == '-' || op == '*' || op == '/') {
			type = 0;
			operator_ = op;
			left = NULL;
			right = NULL;
		} else {
			throw invalid_argument("Invalid operator");
		}
	}

public:
	/* validates an operator */
	bool isOperator() {
		/* Implement your logic here */
	}

	/* get operator value */
	char getOperator() {
		/* Implement your logic here */
	}

	/* get operand value */
	unsigned int getOperand() {
		/* Implement your logic here */
	}

	/* get left child */
	ExprNode* getLeft() {
		/* Implement your logic here */
		
	}

	/* get right child */
	ExprNode* getRight() {
		/* Implement your logic here */
		
	}

	/* set left child */
	void setLeft(ExprNode* left) {
		/* Implement your logic here */
		
	}

	/* set right child */
	void setRight(ExprNode* right) {
		/* Implement your logic here */
		
	}
};

/**
 * Function to construct infix tree from expression
 * 
 * @param exp - string expression for which tree is to be constructed
 * @return node - returns root to infix expression tree
*/
ExprNode* buildInfixTree(string exp) {
	ExprNode* root;

	/* Implement your logic here */

	return root;
}

/**
 * Function to print pre order traversal for infix expression tree
 * 
 * @param root - reference to the root of the infix tree
 * @returns - resultant expression string after pre order traversal
*/
string doPreOrder(ExprNode* root) {
	string result;

	/* Implement your logic here */

	return result;
}

/**
 * Function to evaluate the expression tree using stacks
 * 
 * @param root - reference to the root of the infix tree
 * @returns - result after expression is evaluated
*/
int evaluate(ExprNode* root) {
	int result;

	/* Implement your logic here */

	return result;
}

int getIntMin() {
	return numeric_limits<int>::min();
}

//function to check whether a given character represents basic mathematical operator
bool isOperator(char ch){
    if(ch == '+' || ch =='-'||ch=='*'||ch =='/')
        return true;
    else
        return false;    

}

//checks whether a character represents digit 0 t0 9 as per their ASCII value
bool isOperand(char ch)
{
    if(ch>47 && ch<58)
        return true;
    else
        return false;
}


/**
 * Checks whether a given 
 * expression is a valid mathematical expression
 * 
 * @param exp - expression string to be validated
 * @returns - true if the expression is valid, false otherwise
*/
bool isValid(string expr)
{
    stack<char>st;
    char ch;
    ch = 'a';
    for(int i = 0; i<expr.length();i++){
        if(expr[i]==' ')
            continue;
        else if(expr[i]=='(')
        {
            st.push(expr[i]);
        }
        else if(isOperator(expr[i])==true)
        {
            if(st.empty()==false && !isOperator(st.top()) && st.top()!='(')
            {
                st.push(expr[i]);
            }   
            else
            {
                return false;
            }
            
        }
        else if(expr[i]==')')
        {   if(st.empty()==true)
                return false;
            while(st.top()!='('){
                st.pop();
            } 
            st.pop();
            st.push(ch);
        }
        else
        {
            if(st.top()=='(' || isOperator(st.top()) || st.top()=='a')
            {
                st.push(ch);
            }
            else
                return false;
        }        
    }
    st.pop();
    if(st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


/**
 * Function to print output to console
 * @param result - result from evaluating validity of expression
 */
void printResultA(bool result) {
	cout << "A1a:" << (result ? "true" : "false") << endl;
}

/**
 * Function to print output to console
 * @param result - expression from the pre order traversal
 */
void printResultB(string result) {
	cout << "A1b:" << result << endl;
}

/**
 * Function to print output to console
 * @param result - result after evaluation of expression
 */
void printResultC(int result) {
	cout << "A1c:" << result << endl;
}

int main() {
	/* Expression string */
	string exp;

	/* Input taken from console */
	getline(cin, exp);

	/**
     * QUESTION 1 - PART A
     * 
     * Check if the given expression is a valid mathematical expression
    */

	/* Validate expression */
	bool check = isValid(exp);

	/* Printing result to console */
	printResultA(check);

	/**
     * QUESTION 1 - PART B
     * 
     * Build an infix expession tree for the given expression and
     * print the result of a pre order traversal on the expression tree
     * 
     * Root : must be an operator
     * Left-subtree: sub expression
     * Right-subtree: sub expression
     * Leaves: integer operands
     * 
    */

	/* Construct infix expression tree */
	ExprNode *root = buildInfixTree(exp);

	/* Print pre order traversal */
	string preOrderResult = doPreOrder(root);

	/* Printing result to console */
	printResultB(preOrderResult);

	/**
     * QUESTION 1 - PART C
     * 
     * Check if the given expression is a valid mathematical expression
    */

	/* Evaluate infix expression tree */
	int result = evaluate(root);

	/* Printing result to console */
	printResultC(result);

	return 0;
}
