//FormAI DATASET v1.0 Category: Syntax parsing ; Style: intelligent
#include <stdio.h>

int main() {
    char code[1000]; // initialize empty array of characters to store user inputted code
    printf("Please input your C syntax code: \n");
    fgets(code, sizeof(code), stdin); // get user input and store in code array
    
    int i, count = 0; // initialize loop variable and syntax count variable
    
    for (i = 0; code[i] != '\0'; i++) { // loop through each character in the code array
        if (code[i] == '{' || code[i] == '(' || code[i] == '[') { // if opening syntax is found
            count++; // increment count
        } else if (code[i] == '}' || code[i] == ')' || code[i] == ']') { // if closing syntax is found
            count--; // decrement count
        }
    }
    
    if (count == 0) { // If count is 0, then the syntax is correct
        printf("Your code has correct syntax!\n");
    } else { // If count is not 0, then there is an incorrect syntax
        printf("Your code has an incorrect syntax!\n");
    }
    
    return 0;
}