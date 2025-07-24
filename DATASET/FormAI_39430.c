//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
// Hi there! Welcome to the cheerful C Word Frequency Counter example program!
// This program will count the frequency of every word in a given text file and display it in a nice, colorful table!
// Let's start by including some libraries and defining some colors for our output!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"      
#define GREEN   "\033[32m"     
#define YELLOW  "\033[33m"      
#define BLUE    "\033[34m"      
#define MAGENTA "\033[35m"     
#define CYAN    "\033[36m"      

// Now let's define our main function!

int main(int argc, char **argv) {

    // First, let's check if the user provided a file name as an argument.

    if (argc < 2) {
        printf(RED "Error: No file provided!\n" RESET);
        printf("Please provide a file name as an argument.\n");
        return 1;
    }

    // If the user provided a file name, let's try to open it.

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf(RED "Error: File not found!\n" RESET);
        printf("Please provide a valid file name as an argument.\n");
        return 1;
    }

    // Now that we have our file open, let's read it line by line and count the frequency of every word!

    char line[256];
    char *token;

    // We'll use a dynamic array of structs to keep track of our word counts.

    struct WordCount {
        char *word;
        int count;
    } *wordCounts = NULL;

    int numWords = 0;
    int i, j;

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, " \t\n");

        while (token != NULL) {

            // First, let's convert the word to lowercase to ignore any case sensitivity.

            for (i = 0; i < strlen(token); i++) {
                token[i] = tolower(token[i]);
            }

            // Let's check if the word is already in our wordCounts array.

            for (j = 0; j < numWords; j++) {
                if (strcmp(wordCounts[j].word, token) == 0) {
                    wordCounts[j].count++;
                    break;
                }
            }

            // If the word is not in our array, let's add it!

            if (j == numWords) {
                numWords++;

                wordCounts = (struct WordCount *)realloc(wordCounts, sizeof(struct WordCount) * numWords);
                wordCounts[j].word = (char *)malloc(sizeof(char) * (strlen(token) + 1));
                strcpy(wordCounts[j].word, token);
                wordCounts[j].count = 1;
            }

            token = strtok(NULL, " \t\n");
        }
    }

    // We're done reading our file! Let's close it and start displaying our results!

    fclose(file);

    printf("\n");
    printf(YELLOW "Word Frequency Counter Results:\n" RESET);
    printf("=================================\n\n");

    // We'll sort our wordCounts array in descending order of frequency.

    struct WordCount temp;

    for (i = 0; i < numWords - 1; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (wordCounts[j].count > wordCounts[i].count) {
                temp = wordCounts[i];
                wordCounts[i] = wordCounts[j];
                wordCounts[j] = temp;
            }
        }
    }

    // Now let's display our results in a nice, colorful table!

    printf(CYAN "Word" RESET);
    printf("\t\t");
    printf(CYAN "Frequency\n" RESET);

    for (i = 0; i < numWords; i++) {
        printf("%s", GREEN);
        printf("%s", wordCounts[i].word);
        printf("%s", RESET);
        printf("\t\t");
        printf("%s", MAGENTA);
        printf("%d", wordCounts[i].count);
        printf("%s", RESET);
        printf("\n");
    }

    // Finally, let's free up the memory we allocated for our array.

    for (i = 0; i < numWords; i++) {
        free(wordCounts[i].word);
    }

    free(wordCounts);

    printf("\n");
    printf(GREEN "Thank you for using our Word Frequency Counter! Have a great day!\n" RESET);

    return 0;
}