#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch){
    if(ch == '+' || ch =='-'||ch=='*'||ch =='/')
        return true;
    else
        return false;    

}

bool isOperand(char ch)
{
    if(ch>47 && ch<58)
        return true;
    else
        return false;
}

// bool validExpr(string expr){
//     stack<char> cStack; //stack to hold characters
//     stack<int> iStack; //stack to hold integer values
//     cout<<"\nSize of Expr:"<<expr.length()<<endl;
//     for(int i = 0; i<expr.length(); i++){
//         cout<<"\nscanning"<<expr[i];
//         if(expr[i]==' ')
//             continue;       //white spaces are ignored
//         else if(expr[i] == '(')
//         {
//             //push the left braces into the stack 
//             cStack.push(expr[i]);
//             cout<<"\n\t\t\tPushing (";
//             continue;
//         }
//         else if(isOperand(expr[i])==true)
//         {
//             if(cStack.empty()==true)
//                 return false;
//             unsigned int data = 0;
//             while(i<expr.length() && isOperand(expr[i]) ==true ){
//                 data = data*10 + (expr[i]-'0'); // ASCII value of character '0' is 48 and by subtracting 48 from ASCII code of each digit represented in character form to integer form
//                 i++;
//             }
//             i--;
//             cout<<"\n"<<data;
//             if (iStack.empty()==true)
//             {
//                 iStack.push(data);   
//              }   
//             else if(isOperator(cStack.top())==true)
//             {
//                 iStack.pop();
//                 iStack.push(data);
//                 cout<<"\nPushed data "<<data;
//                 cout<<"\n\t\t\tpopped"<<cStack.top();
//                 cStack.pop();
//             }
//             else if(cStack.top()=='(')
//                 iStack.push(data);
//             else
//                 return false;
//         }
//         else if(isOperator(expr[i])==true)
//         {   if(cStack.empty()==true || isOperator(cStack.top()))
//                 return false;
//             else
//             {
//                 cStack.push(expr[i]);
//                 cout<<"\n \t\tPushed "<<expr[i];
//             }
//         }
//         else
//         {
//             if(cStack.top()=='('){
//                 cStack.pop();
//                 cout<<"\n\t\t\tPopped (";
//             }
//             else if(isOperator(cStack.top())==true)
//             {   cout<<"\n\t\t\t Popped "<<cStack.top();
//                 cStack.pop();
//                 if(cStack.top()=='(')
//                 {   cout<<"\n\t\t\tPopped "<<cStack.top();
//                     cStack.top();
//                 }
//                 iStack.pop();
//             }
//             else
//             {
//                 return false;
//             }
//         }
//     }
//     if(cStack.empty()==true)
//         return true;
//     else
//         false;
    
// }

bool validExpr(string expr)
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


int main()
{
    string expr = "(242+2)";

    bool result = validExpr(expr);
    if(result==true)
        cout<<"\n the given expression is valid"<<endl;
    if(result==false)
        cout<<"\n the given expression is invalid"<<endl;
    return 0;
}