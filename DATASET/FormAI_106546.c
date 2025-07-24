//FormAI DATASET v1.0 Category: Syntax parsing ; Style: cheerful
#include <stdio.h>

int main() {
    // Welcome user with a cheerful statement
    printf("Hello there! Let's parse some C code today!!\n");

    // Declare and initialize variables for keeping track of curly brackets, parentheses and square brackets
    int curlyCount = 0;
    int paraCount = 0;
    int squareCount = 0;

    // Prompt user to input the C code they want to parse
    printf("Enter C code: \n");

    // Read in the C code
    char c = getchar();

    // Keep processing input until end of file or user ends program
    while(c != EOF) {
        // Check if current character is a curly bracket
        if(c == '{') {
            // Increment curly bracket counter
            ++curlyCount;
        }

        // Check if current character is a closing curly bracket
        if(c == '}') {
            // Decrement curly bracket counter
            --curlyCount;
        }

        // Check if current character is a parenthesis
        if(c == '(') {
            // Increment parenthesis counter
            ++paraCount;
        }

        // Check if current character is a closing parenthesis
        if(c == ')') {
            // Decrement parenthesis counter
            --paraCount;
        }

        // Check if current character is a square bracket
        if(c == '[') {
            // Increment square bracket counter
            ++squareCount;
        }

        // Check if current character is a closing square bracket
        if(c == ']') {
            // Decrement square bracket counter
            --squareCount;
        }

        // Read in the next character of the C code
        c = getchar();
    }

    // Check the results of parsing the C code
    if(curlyCount == 0 && paraCount == 0 && squareCount == 0) {
        // Print cheerful message indicating successful parse of code
        printf("Hooray!! The C code is well-parsed. Keep up the good work!\n");
    } else {
        // Print message indicating code has syntax errors
        printf("Oops, there are syntax errors in the C code. Please check your code again!\n");
    }

    return 0;
}