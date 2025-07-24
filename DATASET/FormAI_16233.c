//FormAI DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_word(char *sentence, char *word) {
    int count = 0;
    char *token;
    char delim[] = " ,.!?\n";
    token = strtok(sentence, delim);
    while (token != NULL) {
        if (strcmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, delim);
    }
    return count;
}

int main() {
    char *sentence;
    char word[20];
    int num_words, count;

    printf("Enter a sentence (max 100 characters): ");
    sentence = (char *) malloc(101 * sizeof(char));  // Dynamically allocate memory for sentence
    fgets(sentence, 101, stdin);
    sentence = (char *) realloc(sentence, (strlen(sentence) + 1) * sizeof(char));  // Reallocate memory to fit exact size of sentence

    printf("Enter a word to count: ");
    scanf("%s", word);

    count = count_word(sentence, word);
    printf("The word '%s' appears %d time(s) in the sentence.\n", word, count);

    free(sentence);  // Free allocated memory

    return 0;
}