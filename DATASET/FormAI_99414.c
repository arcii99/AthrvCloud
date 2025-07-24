//FormAI DATASET v1.0 Category: Spell checking ; Style: genious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[1000], dictionary[1000];
    char *token;
    
    printf("Enter your sentence: ");
    fgets(input, 1000, stdin);
    
    printf("Enter the dictionary: ");
    fgets(dictionary, 1000, stdin);
    
    token = strtok(input, " .,!?\n");
    
    while (token != NULL) {
        int found = 0;
        int i, j;
        for (i = 0; i < strlen(token); i++) {
            if (!isalpha(token[i])) {
                continue;
            }
            int match = 0;
            for (j = 0; j < strlen(dictionary); j++) {
                if (tolower(token[i]) == tolower(dictionary[j])) {
                    match = 1;
                    break;
                }
            }
            if (!match) {
                found = 1;
                break;
            }
        }
        if (found) {
            printf("Incorrect spelling: %s\n", token);
        }
        token = strtok(NULL, " .,!?\n");
    }
    return 0;
}