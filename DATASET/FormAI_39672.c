//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char input[1000]; //initializing an input string variable to store user input
    printf("Enter a string: ");
    scanf("%[^\n]s", &input); //scan for input, including spaces

    char stripped[strlen(input)+1]; //initialize a new variable to store the stripped string
    int j = 0; //initialize a variable to keep track of stripped string index

    for (int i = 0; i < strlen(input); i++) {
        //using lowercase alpha only
        if (isalpha(input[i]) && islower(input[i])) {
            stripped[j++] = input[i];
        }
    }
    stripped[j] = '\0'; //add null character to terminate the string
  
    //check if the string is a palindrome
    int palindrome = 1; //set to 1 initially
    for(int i = 0; i < strlen(stripped)/2; i++) {
        if (stripped[i] != stripped[strlen(stripped)-i-1]) {
            palindrome = 0; //set to 0 if not a palindrome
            break; //no need to continue checking
        }
    }
  
    //print the result to the user
    if (palindrome) {
        printf("Yes, the input is a palindrome!");
    } else {
        printf("No, the input is not a palindrome.");
    }

    return 0;
}