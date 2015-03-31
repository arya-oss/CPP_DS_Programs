/*
 * This code is an implementation of converting base of number.
 * it coverts Decimal to Binary, Octal and Hexadecimal equivalent string.
 * this code is application of stack
 * this code is implemented by using standard template library (stack).
 * You can use your own stack here.
 */
#include <iostream>
#include <stack>

using namespace std;

string decimalToBinary(int num) {
    string str="";
    stack<int> s;
    while(num != 0){
        s.push(num%2);
        num = num/2;
    }
    while(!s.empty()) {
        str += (char)(48+s.top()); // converting integer to character
        s.pop();
    }
    return str;
}

string decimalToOctal(int num) {
    string str="";
    stack<int> s;
    while(num != 0){
        s.push(num%8);
        num = num/8;
    }
    while(!s.empty()) {
        str += (char)(48+s.top()); // converting integer to character
        s.pop();
    }
    return str;
}

string decimalToHex(int num) {
    string str="";
    stack<int> s;
    while(num != 0){
        s.push(num%16);
        num = num/16;
    }
    while(!s.empty()) {
        int top = s.top();
        if(top <= 9)
            str += (char)(top+48);
        else if( top == 10)
            str +='A';
        else if( top == 11)
            str += 'B';
        else if (top == 12)
            str += 'C';
        else if (top == 13)
            str += 'D';
        else if(top == 14)
            str += 'E';
        else str += 'F';
        s.pop();
    }
    return str;
}

int main() {
    int num;
    cout<<"Enter Decimal Number : ";
    cin >> num;
    cout<< "\nBinary Equivalent : " <<decimalToBinary(num);
    cout<< "\nOctal Equivalent : " <<decimalToOctal(num);
    cout<< "\nHexadecimal Equivalent : " <<decimalToHex(num);
    return 0;
}
