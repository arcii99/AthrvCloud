//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

int main() {
    char input[MAX_STRING_LENGTH];
    int input_size, i, j, k, num_words = 0;
    char **words;
    
    printf("Enter a string: ");
    fgets(input, MAX_STRING_LENGTH, stdin);
    input_size = strlen(input);
    if (input_size > 0 && input[input_size - 1] == '\n') {
        input[input_size - 1] = '\0';
    }
    
    // count number of words
    for (i = 0; i < input_size; i++) {
        if (input[i] == ' ') {
            num_words++;
        }
    }
    num_words++;
    
    // allocate memory for word pointers
    words = malloc(sizeof(char*) * num_words);
    if (words == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for words\n");
        return EXIT_FAILURE;
    }
    
    // initialize pointers to point to beginning of each word
    k = 0;
    for (i = 0; i < num_words; i++) {
        j = k;
        while (input[k] != '\0' && input[k] != ' ') {
            k++;
        }
        words[i] = &(input[j]);
        if (input[k] == ' ') {
            input[k] = '\0';
            k++;
        }
    }
    
    // sort words in descending order of length using bubble sort
    for (i = 0; i < num_words - 1; i++) {
        for (j = 0; j < num_words - i - 1; j++) {
            if (strlen(words[j]) < strlen(words[j + 1])) {
                char *temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
    
    // print sorted words with word length in brackets
    printf("Sorted words:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s (%d)\n", words[i], strlen(words[i]));
    }
    
    // free memory
    free(words);
}