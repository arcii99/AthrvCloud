//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    char* word;
    int count = 0;
    printf("Please enter a sentence or passage of text:\n");
    fgets(input, 1000, stdin);
    printf("Which word would you like to count the frequency of?\n");
    scanf("%s", word);
    char* ptr = strtok(input, " ");
    while (ptr != NULL) {
        if (strcmp(ptr, word) == 0) {
            count++;
        }
        ptr = strtok(NULL, " ");
    }
    printf("The word \"%s\" appears %d time(s) in the text input.\n", word, count);
    return (0);
}