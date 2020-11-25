#include <iostream>
#include <stack>
#include <string>
#include <cstddef>
#include "Node.h"

using namespace std;

/**
 * Class extends the Node class to implement the functions
*/
class TreeNode : public Node {
public:
	/* validates an operator */
	bool isOperator() {
		/* TODO: Implement your logic here */
	}

	/* get operator value */
	char getOperator() {
		/* TODO: Implement your logic here */
	}

	/* get operand value */
	unsigned int getOperand() {
		/* TODO: Implement your logic here */
	}

	/* get left child */
	Node *getLeft() {
		/* TODO: Implement your logic here */
	}

	/* get right child */
	Node *getRight() {
		/* TODO: Implement your logic here */
	}

	/* set left child */
	void setLeft(Node *left) {
		/* TODO: Implement your logic here */
	}

	/* set right child */
	void setRight(Node *right) {
		/* TODO: Implement your logic here */
	}
};

/**
 * Function to construct infix tree from expression
 * 
 * @param exp - string expression for which tree is to be constructed
 * @return node - returns root to infix expression tree
*/
Node *buildInfixTree(string exp) {
	Node *root = NULL;

	/* TODO: Implement your logic here */

	return root;
}

/**
 * Function to print pre order traversal for infix expression tree
 * 
 * @param root - reference to the root of the infix tree
 * @returns - resultant expression string after pre order traversal
*/
string doPreOrder(Node *root) {
	string result;

	/* TODO: Implement your logic here */

	return result;
}

/**
 * Function to evaluate the expression tree using stacks
 * 
 * @param root - reference to the root of the infix tree
 * @returns - result after expression is evaluated
*/
int evaluate(Node *root) {
	int result;
	stack<Node *> st;

	/* TODO: Implement your logic here */

	return result;
}

/**
 * Checks whether a given 
 * expression is a valid mathematical expression
 * 
 * @param exp - expression string to be validated
 * @returns - true if the expression is valid, false otherwise
*/
bool isValid(string exp) {
	stack<char> st;
	bool result;

	/* TODO: Implement your logic here */

	return result;
}

/**
 * Function to print output to console
 * @param result - result from evaluating validity if expression
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
	//cout << "Enter expression: ";
	cin >> exp;

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
	 * Internak nodes: operators
     * Leaves: integer operands
     * 
    */

	/* Construct infix expression tree */
	Node *root = buildInfixTree(exp);

	/* Print pre order traversal */
	string preOrderResult = doPreOrdert(root);

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