//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
    char word[100];
    int i, j, len;
    
    printf("Hey there! I am your friendly neighborhood palindrome checker!\n");
    printf("Give me a word or a phrase and I'll tell you if it is a palindrome or not!\n");
    
    while (1) {
        printf("\nEnter a word or phrase (type 'exit' to exit): ");
        fgets(word, sizeof(word), stdin);
        word[strcspn(word, "\n")] = '\0'; // remove the annoying newline character
        
        if (strcmp(word, "exit") == 0) {
            printf("Exiting... Goodbye!\n");
            break; // exit program
        }
        
        len = strlen(word);
        j = len - 1;
        for (i = 0; i < len / 2; i++) {
            if (word[i] != word[j]) { // check if character i and j are not equal
                printf("Sorry, '%s' is not a palindrome.\n", word);
                break; // exit loop
            }
            j--;
        }
        
        // if loop completed, then it is a palindrome
        if (i == len / 2) {
            printf("Woohoo! '%s' is a palindrome!\n", word);
        }
    }
    
    return 0;
}