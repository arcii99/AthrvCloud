//FormAI DATASET v1.0 Category: Text processing ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    char word[20];
    int count = 0;

    printf("Hello! Let's count the occurrences of a word in a sentence!\n");
    printf("Enter a sentence (less than 100 characters): ");

    // get sentence input
    fgets(sentence, 100, stdin);

    printf("Enter the word you want to count: ");

    // get word input
    scanf("%s", word);

    // loop through sentence to find occurrences of word
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        if (strcmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }

    printf("The word '%s' occurs %d times in the sentence.\n", word, count);

    printf("Thank you for using this program. Have a great day!");

    return 0;
}