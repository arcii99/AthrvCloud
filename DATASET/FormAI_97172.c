//FormAI DATASET v1.0 Category: Word Count Tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

int main() {
    char inputStr[1000];
    char* words[MAX_WORDS];
    int wordCount[MAX_WORDS];
    int wordTotal = 0;
    int i = 0, j = 0, k = 0, temp = 0;
    int len = 0;
    char delim[] = " \n\t";
    char* word;

    printf("Enter a string : ");
    fgets(inputStr, 1000, stdin);

    word = strtok(inputStr, delim); // Get the first word
    while (word != NULL) {
        if (strlen(word) > MAX_WORD_LENGTH) {
            printf("%s is too long\n", word);
        }
        else {
            len = strlen(word);
            for (i = 0; i < len && isalpha(word[i]); i++) {
                word[i] = tolower(word[i]); // Convert to lowercase
            }
            word[i] = '\0'; // add null terminator
            temp = 0;
            for (j = 0; j < wordTotal; j++) {
                if (strcmp(words[j], word) == 0) {
                    wordCount[j]++; // word already seen before; increment count
                    temp = 1;
                }
            }
            if (temp == 0) {
                if (wordTotal < MAX_WORDS) {
                    // add to words array
                    words[wordTotal] = malloc((len + 1) * sizeof(char));
                    strcpy(words[wordTotal], word);
                    wordCount[wordTotal] = 1;
                    wordTotal++;
                }
                else {
                    printf("%s not counted as max words exceeded\n", word);
                }
            }
        }
        word = strtok(NULL, delim); // Get next word
    }

    // Print count of each word
    printf("\nWord count:\n");
    for (i = 0; i < wordTotal; i++) {
        printf("%-15s : %d\n", words[i], wordCount[i]);
    }

    // Free memory
    for (i = 0; i < wordTotal; i++) {
        free(words[i]);
    }

    return 0;
}