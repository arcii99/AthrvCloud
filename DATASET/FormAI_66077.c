//FormAI DATASET v1.0 Category: Spell checking ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD_LEN 100 // Maximum length of a word
#define DICT_SIZE 10000 // Maximum number of words in dictionary

// Function to check if a word is in the dictionary
int check_dict(char *word, char *dict[]) {
    int i;
    for (i = 0; i < DICT_SIZE; i++) {
        if (dict[i] == NULL)
            break;
        if (strcmp(dict[i], word) == 0)
            return 1;
    }
    return 0;
}

// Function to print suggestions for a misspelled word
void suggest(char *word, char *dict[]) {
    int i, j, k;
    printf("Did you mean:\n");
    for (i = 0; i < DICT_SIZE; i++) {
        if (dict[i] == NULL)
            break;
        for (j = 0; j < strlen(word); j++) {
            for (k = 0; k < strlen(dict[i]); k++) {
                if (dict[i][k] == word[j]) {
                    if (j == strlen(word) - 1 && strlen(dict[i]) == strlen(word) + 1)
                        printf("%s\n", dict[i]);
                    if (j < strlen(word) - 1 && strlen(dict[i]) == strlen(word))
                        printf("%s\n", dict[i]);
                }
            }
        }
    }
}

int main() {
    char *dict[DICT_SIZE]; // Array to store dictionary
    char word[WORD_LEN]; // String to store each word in input
    char input[10000]; // String to store entire input
    int i = 0;
    printf("Enter a sentence or paragraph to check:\n");
    fgets(input, 10000, stdin); // Read input
    
    // Split input into separate words and check each word
    char *token = strtok(input, " \n\t");
    while (token != NULL) {
        // Remove punctuation from word
        int len = strlen(token);
        if (!isalpha(token[len-1]))
            token[len-1] = '\0';
        // Check if word is in dictionary
        if (!check_dict(token, dict)) {
            printf("\033[1;31m%s\033[0m ", token); // Highlight misspelled word
            suggest(token, dict); // Print suggestions for misspelled word
        }
        else {
            printf("%s ", token); // Print correctly spelled word
        }
        // Read next word
        token = strtok(NULL, " \n\t");
    }
    return 0;
}