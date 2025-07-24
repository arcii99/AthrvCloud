//FormAI DATASET v1.0 Category: Spell checking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to check if a character is a letter or not
int is_letter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}

int main() {
    char input[1000];
    char dictionary[1000][1000];
    int dictionary_size = 0; // count of words in dictionary
    int errors_count = 0; // count of errors found

    // read words from a dictionary and store them in an array
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    char line[1000];
    while (fgets(line, 1000, fp)) {
        line[strcspn(line, "\r\n")] = 0; // remove trailing newline character
        strcpy(dictionary[dictionary_size], line); // copy word to dictionary
        dictionary_size++;
    }

    fclose(fp);

    // read input to check for errors
    printf("Enter text to check for spelling errors:\n");
    fgets(input, 1000, stdin);

    printf("Errors found:\n");

    // split input into words and check each word
    char *word = strtok(input, " ,.!?\r\n");
    while (word) {
        int found = 0;

        // convert word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        // remove punctuation from end of word
        int len = strlen(word);
        while (len > 0 && !is_letter(word[len-1])) {
            word[len-1] = '\0';
            len--;
        }

        // check if word is in dictionary
        for (int i = 0; i < dictionary_size; i++) {
            if (strcmp(word, dictionary[i]) == 0) {
                found = 1;
                break;
            }
        }

        // print error message if word is not in dictionary
        if (!found) {
            printf(" - %s\n", word);
            errors_count++;
        }

        // get next word in input
        word = strtok(NULL, " ,.!?\r\n");
    }

    // print summary of errors found
    if (errors_count == 0) {
        printf("No spelling errors found.\n");
    } else if (errors_count == 1) {
        printf("1 spelling error found.\n");
    } else {
        printf("%d spelling errors found.\n", errors_count);
    }

    return 0;
}