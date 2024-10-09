#include <iostream>
#include <limits>
#include <string>
using namespace std;

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
string divide(int a, int b);
bool do_operation(int a, int b);

/*
* Main function that prompts user input and calls for an operation to be done.
*/
int main(){
    int first_operand, second_operand;

    cout << "Enter the first number: " << "\n";
    while(!(cin >> first_operand)){
        cout << "Please enter a number! ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter the second number: " << "\n";
    while(!(cin >> second_operand)){
        cout << "Please enter a number! ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while(!do_operation(first_operand, second_operand));

    return 0;
}

/*
* Function that returns a boolean value and accepts two integers a and b.
* Function prompts user to enter an operator and continues until a proper
* operator is entered. The corresponding function is then called to do the
* operation. Result of the operation is printed out.
*/
bool do_operation(int a, int b){
    char operation;

    cout << "Enter an operator (+,-,*,/): " << "\n";
    while(!(cin >> operation)){
        cout << "Please enter an operator! ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch(operation){
        case '+':
            cout << add(a, b) << "\n";
            return true;
        case '-':
            cout << subtract(a, b) << "\n";
            return true;
        case '*':
            cout << multiply(a, b) << "\n";
            return true;
        case '/':
            cout << divide(a, b) << "\n";
            return true;
        default:
            cout << "Please enter a valid operator! " << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
    }
}

/*
* Function that returns the sum of integers a and b
*/
int add(int a, int b){
    return a + b;
}

/*
* Function that returns the difference of integers a and b
*/
int subtract(int a, int b){
    return a - b;
}

/*
* Function that returns the product of integers a and b
*/
int multiply(int a, int b){
    return a * b;
}

/*
* Function that returns the quotient of integers a and b. Returns "Cannot divide by 0"
* if integer b is 0.
*/
string divide(int a, int b){
    if (b == 0){
        return "Cannot divide by 0";
    } else{
        return to_string(a / b);
    }
}