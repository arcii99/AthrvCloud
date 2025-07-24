//FormAI DATASET v1.0 Category: Spell checking ; Style: artistic
#include <stdio.h>
#include <ctype.h>

int main() {
    char dictionary[10][10] = {"apple", "banana", "carrot", "dragon", "elephant", "flower", "giraffe", "honey", "igloo", "jungle"};
    char input[20];
    int found = 0;
    
    printf("Enter a word to check its spelling: ");
    scanf("%s", input);

    for (int i = 0; i < 10; i++) {
        if (strcmp(input, dictionary[i]) == 0) {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        printf("The word \"%s\" is spelled correctly.\n", input);
    }
    else {
        printf("The word \"%s\" is spelled incorrectly.\n", input);
        printf("Suggestions:\n");
        for (int i = 0; i < strlen(input); i++) {
            char temp = input[i];
            for (int j = 97; j < 123; j++) {
                input[i] = j;
                for (int k = 0; k < 10; k++) {
                    if (strcmp(input, dictionary[k]) == 0) {
                        printf("%s\n", input);
                    }
                }
            }
            input[i] = temp;
        }
    }

    return 0;
}