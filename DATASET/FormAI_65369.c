//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// function to check if a string is palindrome
bool checkPalindrome(char* str, int len) {
    for (int i = 0; i < len; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1]))
            return false;
    }
    return true;
}

int main() {
    printf("Enter a string: ");
    char str[100];
    fgets(str, 100, stdin);

    int len = strlen(str) - 1; // ignore newline character
    str[len] = '\0'; // replace newline character with null

    pid_t pid = fork(); // create a new process

    if (pid == -1) { // check if fork failed
        printf("Fork failed\n");
        exit(1);
    } 
    
    else if (pid == 0) { // child process
        bool isPalindrome = checkPalindrome(str, len); // check if string is palindrome
        printf("Is Palindrome? %s\n", isPalindrome ? "true" : "false");
        exit(0); // exit child process
    } 
    
    else { // parent process
        wait(NULL); // wait for child process to complete
        printf("Palindrome Checker Complete\n");
    }

    return 0;
}