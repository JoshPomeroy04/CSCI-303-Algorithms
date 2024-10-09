#include <iostream>
#include <limits>
#include <string>
using namespace std;

void draw_triangle(int n);
void draw_diamond(int n);
void draw_trapezoid(int n);

/*
* Main function that prompts the user for a number input and calls the 3 other functions.
*/
int main(){
    int user_input;

    cout << "Type a number: ";
    while(!(cin >> user_input)){
        cout << "Please enter a number! ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    draw_triangle(user_input);
    cout << "\n";
    draw_diamond(user_input);
    cout << "\n";
    draw_trapezoid(user_input);
    cout << "\n";
    return 0;
}

/* 
* Function to print a triangle shape. Takes an integer n as input.
* Integer n determines how many asterisks are contained in the top row.
* The triangle is built facing downward (the top of the triangle is the thickest).
*/
void draw_triangle(int n){
    string dots = "";
    int tail = n - 1, dots_left = n;
    int head = 0;

    for (int i = 0; i < n; i++){
        dots += '*';
    }

    cout << dots << "\n";
    while(dots_left > 2){
        dots[head] = ' ';
        dots[tail] = ' ';
        cout << dots << "\n";
        head++;
        tail--;
        dots_left -= 2;
    }
}

/*
* Function to print a diamond shape. Takes an integer n as input.
* Integer n determines how many asterisks are contained in the middle row.
*/
void draw_diamond(int n){
    string dots = "";
    int length = n;
    int bottom, rows_left;

    if (n%2 == 0){
        bottom = 2;
        rows_left = (n - 1) / 2;
    } else{
        bottom = 1;
        rows_left = n / 2;
    }

    for (int i = 0; i < n; i++){
        dots += '*';
    }

    while (rows_left > 0){
        for (int i = 0; i < ((length - bottom) / 2); i++){
            cout << " ";
        }
        for (int i = 0; i < bottom; i++){
            cout << "*";
        }
        cout << "\n";
        bottom += 2;
        rows_left--;
    }

    draw_triangle(length);
}

/*
* Function to print a trapezoid shape. Takes an integer n as input.
* Integer n determines how long the trapezoid is.
* The trapezoid grows in height by 1 for every 2 length past length 5.
* The default height of the trapezoid for lengths 6 and below is 2.
*/
void draw_trapezoid(int n){
    string dots = "";
    int height;
    int counter = 1;

    if (n > 6 && n % 2 == 1){
        height = ((n - 5) / 2) + 2;
    } else{
        height = 2;
    }

    for (int i = 0; i < n; i++){
        dots += '*';
    }

    cout << dots << "\n";
    while (height > 1){
        for (int i = 0; i < counter; i++){
            cout << " ";
        }
        cout << dots << "\n";
        counter++;
        height--;
    }
}