//FormAI DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char user_input[100];

    printf("Welcome to Word Reverser!\n");
    printf("Enter a word or phrase: ");
    fgets(user_input, 100, stdin); // get user input

    printf("Your reversed input is: ");

    // split input into words
    char *word = strtok(user_input, " \n");
    while (word != NULL) {
        // reverse each word
        int length = strlen(word);
        for (int i = length-1; i >= 0; i--) {
            printf("%c", word[i]);
        }
        printf(" ");
        word = strtok(NULL, " \n");
    }
    printf("\n");

    printf("Thank you for using Word Reverser!\n");

    return 0;
}