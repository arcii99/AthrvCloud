//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

/*
 * Function to convert all characters in a string to lowercase
 */
void toLower(char *word) {
    int i = 0;
    while (word[i] != '\0') {
        word[i] = tolower(word[i]);
        i++;
    }
}

/*
 * Main function
 */
int main(){
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {0};  // Array to store the words
    int word_count[MAX_WORDS] = {0};  // Array to store the frequency of each word
    char input[1000];

    printf("Welcome to the Cheerful Word Frequency Counter Program!\n");
    printf("Please enter some sentences (max 1000 characters) then press Enter:\n");

    fgets(input, 1000, stdin);  // Get input from user

    // Tokenize input into words
    char *token = strtok(input, " \n");

    int i = 0, j;
    while (token != NULL) {

        // Remove any non-alphanumeric characters from the word
        int k = 0;
        for (j = 0; token[j] != '\0'; j++) {
            if (isalnum(token[j])) {
                words[i][k++] = token[j];
            }
        }

        // Convert word to lowercase
        toLower(words[i]);

        // Increment the count for this word
        int found = 0;
        for (j = 0; j < i; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                found = 1;
                word_count[j]++;
                break;
            }
        }
        if (!found) {
            word_count[i]++;
            i++;
        }

        if (i == MAX_WORDS) {
            printf("Sorry! This program only supports up to %d unique words.\n", MAX_WORDS);
            return 1;
        }

        // Get next token
        token = strtok(NULL, " \n");
    }

    // Print the frequency of each word
    printf("Word Frequency:\n");
    for (j = 0; j < i; j++) {
        printf("%s: %d\n", words[j], word_count[j]);
    }

    printf("Thank you for using the Cheerful Word Frequency Counter Program!\n");
    return 0;
}