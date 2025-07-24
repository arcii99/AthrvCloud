//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: visionary
#include <stdio.h> //the standard input/output library
#include <string.h> //the string manipulation library

#define MAX_INPUT 100 //define the maximum length of user input

//function to check if the input string is a palindrome
int isPalindrome(char input[]) {
    int length = strlen(input);
    for(int i=0; i < length/2; i++) { //loop through the first half of the string
        if(input[i] != input[length-1-i]) { //if the characters at the corresponding positions don't match
            return 0; //return false
        }
    }
    return 1; //return true if all characters match
}

int main() {
    char input[MAX_INPUT]; //declare a char array to store user input
    
    printf("Welcome to the Palindrome Checker! Enter a word or phrase:\n");
    fgets(input, MAX_INPUT, stdin); //read user input
    
    int result = isPalindrome(input); //check if the input is a palindrome
    
    if(result) { //if it is
        printf("Congratulations! \"%s\" is a palindrome.\n", input);
    } else { //if it's not
        printf("Sorry, \"%s\" is not a palindrome.\n", input);
    }
    
    return 0;
}