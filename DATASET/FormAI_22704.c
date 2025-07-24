//FormAI DATASET v1.0 Category: Text processing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    int count = 1;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    if (str[strlen(str)-1] == '\n') { //removing newline character from fgets
        str[strlen(str)-1] = '\0';
    }

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\t') { //counting number of words
            count++;
        }
    }

    printf("The number of words in the sentence is: %d\n", count);

    char word[20];
    int word_count = 0;

    printf("Enter a word to search: ");
    scanf("%s", word);

    char *ptr = strtok(str, " "); //tokenizing string into words

    while (ptr != NULL) {
        if (strcmp(ptr, word) == 0) { //checking if word matches
            word_count++;
        }
        ptr = strtok(NULL, " ");
    }

    if (word_count > 0) {
        printf("The word '%s' is present %d times in the sentence.\n", word, word_count);
    } else {
        printf("The word '%s' is not present in the sentence.\n", word);
    }

    return 0;
}