//FormAI DATASET v1.0 Category: Spell checking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    FILE *dict_file = fopen("dictionary.txt", "r"); // open dictionary file for reading
    if (dict_file == NULL) {
        printf("Dictionary file not found.\n");
        return 1;
    }

    char word[50];
    char dictionary[100000][50];
    int dict_size = 0;

    // read each word from dictionary file and store in a string array
    while (fgets(word, 50, dict_file)) {
        word[strcspn(word,"\n")] = '\0'; // remove newline character from end of word
        strcpy(dictionary[dict_size], word);
        dict_size++;
    }
    fclose(dict_file); // close dictionary file

    // prompt user for input
    char input[50];
    printf("Enter a sentence to check for spelling errors: ");
    fgets(input, 50, stdin); // read user input

    // separate sentence into individual words
    char *token = strtok(input, " ");
    int errors = 0;
    printf("The following words are misspelled:\n");
    while (token != NULL) {
        if(token[strlen(token)-1] == '\n')
            token[strlen(token)-1] = '\0'; // remove newline character from end of word

        // convert word to lowercase for case-insensitive comparison
        for(int i=0; i<strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        // compare word with dictionary
        int found = 0;
        for(int i=0; i<dict_size; i++) {
            if(strcmp(token, dictionary[i]) == 0) {
                found = 1;
                break;
            }
        }
        if(found == 0) {
            printf("- %s\n", token);
            errors++;
        }
        token = strtok(NULL, " ");
    }

    if(errors == 0) {
        printf("No spelling errors found.\n");
    } else {
        printf("%d spelling error(s) found.\n", errors);
    }
    return 0;
}