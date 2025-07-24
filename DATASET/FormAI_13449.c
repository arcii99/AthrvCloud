//FormAI DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_spelling(char *word, char *dictionary[], int dict_size) {
    int i;

    for (i = 0; i < dict_size; i++) { // loop through dictionary
        if (strcasecmp(word, dictionary[i]) == 0) // check if word matches dictionary entry
            return 1; // word is spelled correctly, return 1
    }

    return 0; // word is not in dictionary, return 0
}

int main() {
    char *dictionary[] = {"apple", "banana", "cherry", "delicious", "elephant", "fantastic"};
    int dict_size = sizeof(dictionary) / sizeof(char *);

    char input[100], copy[100];
    fgets(input, 100, stdin); // get user input
    
    // strip input of punctuation and convert to lowercase
    int i, j;
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            copy[j++] = tolower(input[i]);
        }
    }
    copy[j] = '\0';
    
    // split input into individual words
    char *word;
    word = strtok(copy, " ");
    while (word != NULL) {
        if (!check_spelling(word, dictionary, dict_size)) {
            printf("%s is misspelled.\n", word);
            // suggest corrections
            printf("Did you mean: ");
            int k, l;
            for (k = 0; k < dict_size; k++) {
                if (strncmp(word, dictionary[k], strlen(word)) == 0) {
                    printf("%s ", dictionary[k]);
                }
            }
            printf("\n");
        }
        word = strtok(NULL, " ");
    }
    
    return 0;
}