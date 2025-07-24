//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[50];

    printf("Enter a string: ");
    fgets(word, sizeof(word), stdin);

    // Removing the newline character from the end of the input word
    word[strcspn(word, "\n")] = 0;

    // Converting all characters to lowercase to ignore case while comparing
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
    
    // Setting up the Sherlock Holmes style narrative
    printf("My dear Watson, it seems we have a new mystery to solve.\n");
    printf("The word presented to us is: %s\n", word);
    printf("Let us investigate further, shall we?\n\n");

    int length = strlen(word);
    int isPalindrome = 1; // Initializing to true

    for (int i = 0; i < length/2; i++) {
        if (word[i] != word[length-i-1]) {
            isPalindrome = 0; // Setting to false 
            break;
        }
    }
    
    // Continuing the narrative with findings
    if (isPalindrome) {
        printf("My dear Watson, it appears that this string is indeed a palindrome!\n");
        printf("The culprit could not hide from our sharp eyes and intellect.\n");
    } else {
        printf("Oh dear, Watson, we seem to have been misled.\n");
        printf("This word is not a palindrome, after all.\n");
        printf("But fear not! We shall continue our search for the truth.\n");
    }

    return 0;
}