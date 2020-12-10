// ExpreeTree.cpp
#include <bits/stdc++.h> 
using namespace std; 

// Tree Structure 
typedef struct node 
{ 
	char oprtr; 
    unsigned int operand;
	struct node *left, *right; 
} * nptr; 

/**
 * Function to create new node for operator 
 * @param ch - operator to initiaze the node's operator
 * @returns - node pointer of new node
*/
nptr newNode(char ch) 
{ 
	nptr n = new node; 
	n->oprtr = ch; 			
	n->left = n->right = nullptr; 
	return n; 
} 

/**
 * Function to create new node for operand
 * @param num - operand to initiaze the node's operand
 * @returns - node pointer of new node
*/
nptr newNode(unsigned int num) 
{ 
	nptr n = new node; 
	n->operand = num; 
	n->left = n->right = nullptr; 
	return n; 
} 

/**
 * Function to build Expression Tree 
 * @param s - mathematical expression for which infix tree is to be built
 * @returns - node pointer to the root of the infix tree
*/
nptr buildInfixTree(string& s) 
{	// Stack to hold nodes 
	stack<nptr> nStack; 
	// Stack to hold chars 
	stack<char> cStack; 
	nptr t, t1, t2; // temporary node pointers
	for (int i = 0; i < s.length(); i++) 
	{ 
		if (s[i] == '(') { 

			// Push '(' in char stack 
			cStack.push(s[i]); 
		} 
		// Push the operands in node stack 
		else if (isdigit(s[i])) 
		{ 
            unsigned int number = s[i] -'0';
            i++;
            while(isdigit(s[i])){
                number = 10*number + s[i] -'0';
                i++;
            }
            i--;
            t = newNode(number); 
			nStack.push(t); 
		} 
		// push operator into the stack character stack
		else if (s[i]=='+' || s[i] == '-' || s[i] == '*' || s[i] =='/') 
		{ 
			cStack.push(s[i]); 
		}
 
		else if (s[i] == ')') { 
			while (!cStack.empty() && cStack.top() != '(') 
			{ 
				t = newNode(cStack.top()); // node t's operator gets operator as top of character stack
				cStack.pop(); 
				t1 = nStack.top(); 	// t1 holds node from top of node stack
				nStack.pop(); 		
				t2 = nStack.top(); 	// t2 holds node from top of node stack
				nStack.pop(); 		
				t->left = t2; 		// node t's left pointer is pointed to node t2
				t->right = t1; 		// node t's right pointer is pointed to node t1
				nStack.push(t); 	// node pointer t is pushed to node stack
			} 
			cStack.pop(); 		// '(' from character stack is popped out
		} 
	} 
	t = nStack.top(); // node pointer t now points to root of the tree 
	return t; 
} 
 
/**
 * Function to perform preorder traversal of inorder tree
 * @param root - node pointer to the root of the inorder tree
*/
void doPreOrder(nptr root) {
	/* Implement your logic here */
	// if the node is a leaf node
	if ((root->left)==nullptr && (root->right)==nullptr)
	{
		cout <<root->operand<<" "; // prints the operand
	}
	//if the node is a non-leaf node
    else if(root) {
		cout<< root->oprtr<<" "; // prints the operator
		doPreOrder(root->left);
		doPreOrder(root->right);
    }
}

/**
 * Function to compute the result of binary operation '+', '-','*' or '/'
 * @param x, y, oprt - left side operand , y is rightside operand and optr is operator
 * @returns - the result of binary operation
*/
int compute(int x,int y, char optr)
{
	int result;
	switch (optr)
	{
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '*':
		result = x * y;
		break;
	case '/':
		result = x / y;
		break;
	default:
		break;
	}
	return result;
}

/**
 * Function to evaluate the expression tree using stacks
 * 
 * @param root - reference to the root of the infix tree
 * @returns - result after expression is evaluated
*/
int evaluate(nptr root) {
	int result;

	/* Implement your logic here */
	if((root->left)==nullptr && (root->right)==nullptr)
	{
		result = root->operand;
	}
	else if(root)
    {
        result = compute(evaluate(root->left),evaluate(root->right),root->oprtr); 
    } 
	return result;
}


int getIntMin() {
	return numeric_limits<int>::min();
}
 
/**
 * Checks whether a given character is binary operator
 * @param ch - character which is to be checked
 * @returns - true if the character is binary operator, false otherwise
*/

bool isOperator(char ch){
    if(ch == '+' || ch =='-'||ch=='*'||ch =='/')
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
void printResultB(nptr root) {
	
    cout << "A1b:";

	// /* perform & Print pre order traversal */
    doPreOrder(root);
    cout << endl;
}

/**
 * Function to print output to console
 * @param result - result after evaluation of expression
 */
void printResultC(int result) {
	cout << "A1c:" << result << endl;
}

int main() 
{   /* Expression string */
    string exp;
   /* Input taken from console */
	getline(cin,exp);
 
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

   if(check)
   {
        /* Construct infix expression tree */
        nptr root = buildInfixTree(exp);

        // /* Printing result to console */
        printResultB(root);
      
    // /**
    //  * QUESTION 1 - PART C
    //  * 
    //  * Check if the given expression is a valid mathematical expression
    // */

	// /* Evaluate infix expression tree */
	int result = evaluate(root);

	// /* Printing result to console */
	printResultC(result);
   }
   else
   {
    cout << "A1b:NA"<<endl;
    printResultC(getIntMin());

   }
	return 0; 
}
