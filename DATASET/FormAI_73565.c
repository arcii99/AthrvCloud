//FormAI DATASET v1.0 Category: Spell checking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char word[20];
    printf("Enter a word to check for spelling errors: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0'; // remove newline character at end
    
    // Check word against dictionary of correct spellings
    char dictionary[][20] = {"apple", "banana", "orange", "pear", "grape", "kiwi", "mango", "pineapple", "watermelon", "blueberry"};
    int dict_size = sizeof(dictionary) / sizeof(dictionary[0]);
    int i, found = 0;
    for (i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Correct spelling!\n");
    } else {
        printf("Incorrect spelling!\n");
        // Offer suggestions for corrected spelling
        int j, k, l;
        char* suggestions[5];
        for (j = 0; j < 5; j++) {
            suggestions[j] = (char*) malloc(20 * sizeof(char));
        }
        int num_sugg = 0;
        for (j = 0; j < dict_size; j++) {
            if (strlen(dictionary[j]) == strlen(word)) {
                int num_mismatches = 0;
                for (k = 0; k < strlen(word); k++) {
                    if (word[k] != dictionary[j][k]) {
                        num_mismatches++;
                    }
                }
                if (num_mismatches <= 1) {
                    strcpy(suggestions[num_sugg++], dictionary[j]);
                }
            } else if (strlen(dictionary[j]) == strlen(word) + 1) {
                for (k = 0; k < strlen(dictionary[j]); k++) {
                    if (dictionary[j][k] != word[k] && dictionary[j][k+1] != word[k]) {
                        break;
                    }
                }
                if (k == strlen(dictionary[j])) {
                    strcpy(suggestions[num_sugg++], dictionary[j]);
                }
            } else if (strlen(dictionary[j]) == strlen(word) - 1) {
                for (k = 0; k < strlen(word); k++) {
                    if (dictionary[j][k] != word[k] && dictionary[j][k] != word[k+1]) {
                        break;
                    }
                }
                if (k == strlen(word)) {
                    strcpy(suggestions[num_sugg++], dictionary[j]);
                }
            }
        }
        if (num_sugg == 0) {
            printf("No suggestions found.\n");
        } else {
            printf("Suggestions: ");
            for (l = 0; l < num_sugg; l++) {
                printf("%s ", suggestions[l]);
            }
            printf("\n");
        }
        for (j = 0; j < 5; j++) {
            free(suggestions[j]);
        }
    }
    return 0;
}