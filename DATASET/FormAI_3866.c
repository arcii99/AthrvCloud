//FormAI DATASET v1.0 Category: Spell checking ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100 // Maximum length of a word in the dictionary

int main() {
    char word[MAX_LENGTH];
    char dictionary[100][MAX_LENGTH];
    int i = 0, j = 0, k = 0, l = 0;

    // Read dictionary from file
    FILE* fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Failed to open dictionary file.\n");
        return 1;
    }
    while ((fgets(dictionary[i], MAX_LENGTH, fp)) != NULL) {
        strtok(dictionary[i], "\n"); // Remove newline character
        i++;
    }
    fclose(fp);

    // Allow user to input words to spell check
    printf("Enter a word to spell check (or \"quit\" to exit): ");
    fgets(word, MAX_LENGTH, stdin);
    while (strcmp(word, "quit\n") != 0) {
        strtok(word, "\n"); // Remove newline character
        int found = 0;
        for (j = 0; j < i; j++) {
            if (strcmp(word, dictionary[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            // Check for similar words in dictionary
            for (k = 0; k < i; k++) {
                l = 0;
                while (word[l] != '\0' && dictionary[k][l] != '\0' && word[l] == dictionary[k][l]) {
                    l++;
                }
                if (word[l+1] == dictionary[k][l+1]) {
                    printf("Did you mean \"%s\"?\n", dictionary[k]);
                    break;
                }
            }
            if (k == i) {
                printf("Cannot find word in dictionary.\n");
            }
        }
        else {
            printf("Word spelled correctly.\n");    
        }

        printf("Enter a word to spell check (or \"quit\" to exit): ");
        fgets(word, MAX_LENGTH, stdin);
    }

    return 0;
}