//FormAI DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <string.h>

/* This program takes a user input string, converts the first letter to uppercase and appends " is Awesome!" */

int main() {
    char string[50];
    printf("Enter a string: ");
    fgets(string, 50, stdin); // read user input
    string[strcspn(string, "\n")] = '\0'; // remove newline character at end of input
    
    int length = strlen(string);
    
    // convert first letter to uppercase
    if (string[0] > 96 && string[0] < 123) { // check if lowercase letter
        string[0] -= 32; // convert to uppercase
    }
    
    char newString[60];
    strcpy(newString, string); // copy original string to new string
    
    // append " is Awesome!"
    strcat(newString, " is Awesome!");
    
    printf("\n%s\n", newString); // print final string
    
    return 0;
}