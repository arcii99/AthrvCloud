//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int i, j, isPalindrome;

    printf("Hi there! I'm your friendly Palindrome checker. Let's get started!\n");

    do {
        printf("\nEnter a word or phrase to check if it's a palindrome (type 'exit' to quit): ");
        scanf("%s", input);

        // check if user typed 'exit'
        if(strcmp(input, "exit") == 0) {
            printf("\nThanks for using the Palindrome checker! Have a great day!\n");
            return 0;
        }

        // check if input is a palindrome
        isPalindrome = 1;
        for(i=0, j=strlen(input)-1; i<strlen(input)/2; i++, j--) {
            if(input[i] != input[j]) {
                isPalindrome = 0;
                break;
            }
        }

        // print appropriate output
        if(isPalindrome) {
            printf("\n'%s' is a palindrome! Yay!\n", input);
        } else {
            printf("\nSorry, '%s' is not a palindrome. Try again!\n", input);
        }

    } while(strcmp(input, "exit") != 0);
    
    return 0;
}