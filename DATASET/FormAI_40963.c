//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: authentic
#include <stdio.h>
#include <string.h>

/*
 * Function to check if a given string is a palindrome or not
 * 
 * @param char* - the string to check
 * @return 1 if the given string is a palindrome, 0 otherwise
 */
int is_palindrome(char*);

/*
 * Main function to run the program
 * 
 * @param argc - the number of command-line arguments passed
 * @param argv - an array of the command-line arguments
 * @return 0 on successful execution
 */
int main(int argc, char** argv) {
    // Check if the user has provided a string to check
    if(argc < 2) {
        printf("Please provide a string to check as a command-line argument.\n");
        return 1;
    }
    // Check if the given string is a palindrome
    if(is_palindrome(argv[1])) {
        printf("%s is a palindrome.\n", argv[1]);
    } else {
        printf("%s is not a palindrome.\n", argv[1]);
    }
    return 0;
}

int is_palindrome(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}