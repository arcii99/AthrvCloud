//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LEN 100

// Global variable to store the result of the palindrome check
bool isPalindrome = false;

// Function to check if a given string is a palindrome
void checkPalindrome(char *str) {

    // Calculate the length of the input string
    int len = strlen(str);

    // Loop through the string using two pointers
    for(int i = 0, j = len - 1; i < j; i++, j--) {

        // Ignore non-alphanumeric characters
        while(!isalnum(str[i]) && i < j) i++;
        while(!isalnum(str[j]) && i < j) j--;
        
        // If the characters at the two pointer positions do not match, exit the loop
        if(tolower(str[i]) != tolower(str[j])) {
            isPalindrome = false;
            return;
        }
    }

    // If the loop completes successfully, the input string is a palindrome
    isPalindrome = true;
}

// Function to print the result of the palindrome check
void printResult() {

    if(isPalindrome) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }
}

// Asynchronous main function using the fork() system call
int main() {

    // Initialize the input string variable
    char str[MAX_LEN];

    // Prompt the user for input
    printf("Enter a string to check for palindrome: ");
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the newline character from the input string

    // Fork the process to create a child process
    pid_t pid = fork();

    // Check for fork errors
    if(pid < 0) {
        printf("Fork failed\n");
        exit(EXIT_FAILURE);
    }

    // Child process
    else if(pid == 0) {

        // Run the palindrome check function asynchronously
        checkPalindrome(str);

        // Print the result asynchronously
        printResult();

        // Exit the child process
        exit(EXIT_SUCCESS);
    }

    // Parent process
    else {

        // Wait for the child process to finish
        wait(NULL);

        // Print a message asynchronously to indicate that the parent process has finished executing
        printf("Parent process has finished executing.\n");

        // Exit the parent process
        exit(EXIT_SUCCESS);
    }

    // Return from the main function
    return 0;
}