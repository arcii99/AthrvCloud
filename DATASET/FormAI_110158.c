//FormAI DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void check_spelling(char word[]) {

    char dictionary[10][20] = {"apple", "banana", "grape", "orange", "mango", "lemon", "peach", "kiwi", "pear", "plum"};

    int i, j, flag = 0;
    for(i = 0; i < 10; i++) {
        if(strcmp(dictionary[i], word) == 0) {
            flag = 1;
            break;
        }
    }

    if(flag == 1) {
        printf("The word '%s' is spelled correctly!\n", word);
    }
    else {
        printf("The word '%s' is spelled incorrectly!\n", word);

        // Check for possible suggestion
        printf("Did you mean: ");
        for(i = 0; i < 10; i++) {
            for(j = 0; j < strlen(word); j++) {
                if(tolower(word[j]) != tolower(dictionary[i][j]))
                    break;
            }
            if(j == strlen(word) && j == strlen(dictionary[i]))
                continue;
            if(j == strlen(word) || j == strlen(dictionary[i]))
                printf("%s, ", dictionary[i]);
        }
        printf("\n");
    }
}

int main() {

    char word[20];
    printf("Enter a word: ");
    scanf("%s", word);

    check_spelling(word);

    return 0;
}