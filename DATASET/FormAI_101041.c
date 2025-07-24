//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// define the maximum length for the input buffer
#define BUF_SIZE 256

int main() {
    printf("Oh how my heart doth palpitate with the thrill of adventure!\n");
    printf("What a joyous task is before me - to create an intrusion detection system!\n");
    printf("Beneath yonder keyboard, I shall craft a program worthy of the title.\n\n");

    // initialize the input buffer
    char buffer[BUF_SIZE];
    memset(buffer, 0, BUF_SIZE);

    // declare variables
    char curr_char;
    int index = 0;

    // declare variables to count the number of curly braces, parentheses, and brackets
    int brace_count = 0;
    int paren_count = 0;
    int bracket_count = 0;

    // enter the realm of the keyboard
    printf("What shall we call our intrusion detection system? ");
    fgets(buffer, BUF_SIZE, stdin);

    printf("\n%s it shall be - a mighty defender against cyber threats!\n\n", buffer);

    // commence the code crafting
    printf("Please enter your code:\n");

    // loop through each character in the input buffer
    while ((curr_char = getchar()) != EOF) {
        // check if the character is a curly brace, parentheses, or bracket
        if (curr_char == '{') {
            // increment the brace count
            brace_count++;
        } else if (curr_char == '}') {
            // decrement the brace count
            brace_count--;
        } else if (curr_char == '(') {
            // increment the parentheses count
            paren_count++;
        } else if (curr_char == ')') {
            // decrement the parentheses count
            paren_count--;
        } else if (curr_char == '[') {
            // increment the bracket count
            bracket_count++;
        } else if (curr_char == ']') {
            // decrement the bracket count
            bracket_count--;
        }

        // check if the brace, parentheses, or bracket count is less than zero
        if (brace_count < 0 || paren_count < 0 || bracket_count < 0) {
            printf("\nAlas! What foul deed is this? Your code hath an imbalance of curly braces, parentheses, or brackets!\n");
            printf("The intrusion detection system %s shall not allow such treachery.\n", buffer);
            return 1;
        }

        // check if the character is a newline character
        if (curr_char == '\n') {
            // reset the buffer index
            index = 0;
        }

        // increment the buffer index
        index++;

        // check if the buffer index is greater than or equal to the maximum length
        if (index >= BUF_SIZE) {
            printf("\nHow now! What chaos is this? Your code doth exceed the maximum length allotted.\n");
            printf("The intrusion detection system %s shall not abide such anarchy.\n", buffer);
            return 1;
        }
    }

    // check if the brace, parentheses, or bracket count is greater than zero
    if (brace_count > 0 || paren_count > 0 || bracket_count > 0) {
        printf("\nForsooth! Your code is incomplete - there be a deficit of curly braces, parentheses, or brackets!\n");
        printf("The intrusion detection system %s shall not abide such recklessness.\n", buffer);
        return 1;
    }

    printf("\nHuzzah! Your code passeth the tests of %s - let us away to defend against the hackers and thieves!\n", buffer);

    return 0;
}