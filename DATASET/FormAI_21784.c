//FormAI DATASET v1.0 Category: Word Count Tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS_DIM 1000
#define MAX_WORD_LEN 100

int main() {
    char inputString[MAX_WORDS_DIM]; //Array to store the input string
    char words[MAX_WORDS_DIM][MAX_WORD_LEN]; //2D-Array to store the words
    int count[MAX_WORDS_DIM]; //Array to store the frequency of words
    int i, j, k, wordCount = 0;

    printf("Enter the string:\n");
    fgets(inputString, MAX_WORDS_DIM, stdin);

    //Converting the input string to lower case
    for (i = 0; inputString[i]; i++) {
        inputString[i] = tolower(inputString[i]);
    }

    //Extracting individual words and storing in an array
    i=0;
    while (inputString[i] != '\0') {
        while (inputString[i] == ' ' || inputString[i] == '\n' || inputString[i] == '\t') {
            i++;
        }

        j=0;
        while (inputString[i] != ' ' && inputString[i] != '\n' && inputString[i] != '\t' && inputString[i] != '\0') {
            words[wordCount][j] = inputString[i];
            j++;
            i++;
        }

        words[wordCount][j] = '\0';
        wordCount++;
    }

    //Calculating the frequency of each word
    for (i = 0; i < wordCount; i++) {
        count[i] = 1;
        for (j = i + 1; j < wordCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count[i]++;
                for (k = j; k < wordCount; k++) {
                    strcpy(words[k], words[k + 1]);
                }
                wordCount--;
                j--;
            }
        }
    }

    //Printing the word count
    printf("\nWord count:\n");
    for (i = 0; i < wordCount; i++) {
        printf("%s - %d\n", words[i], count[i]);
    }

    return 0;
}