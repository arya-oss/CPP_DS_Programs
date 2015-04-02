/**
 * This Programs Converts Infix expression to Postfix expression
 * STL stack is used in this program.
 */
 #include <iostream>
 #include <stack>
 #include <stdlib.h>

 using namespace std;

int precedence(char ch) {
    switch(ch){
    case '#': return 0;
    case '(': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    default: return -1;
    }
}

 int main() {
    string infx,pofx="";
    cout << "Enter Expression : ";
    cin >> infx;
    stack<char> S;
    S.push('#');  // First Push a deli-meter for comparison purpose
    for(int i=0; i<infx.length(); i++){
        if(isalnum(infx[i]))
            pofx += infx[i];
        else{
            if(precedence(infx[i]) >= precedence(S.top()))
                S.push(infx[i]);
            else if(infx[i]==')'){
                while(S.top()!='('){
                    pofx += S.top();
                    S.pop();
                }
                S.pop();
            }
            else{
                pofx += S.top();
                S.pop();
                S.push(infx[i]);
            }
        }
    }
    while(S.top() != '#') {
        pofx += S.top();
        S.pop();
    }
    cout<<"\nGiven Infix Expansion : "<<infx<<"\n"<<"Postfix Expansion: "<<pofx<<"\n";
    return 0;
 }
