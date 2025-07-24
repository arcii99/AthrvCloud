//FormAI DATASET v1.0 Category: Spell checking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char word[100], dictionary[100][100];
    int i, j, dictSize, wordSize, flag = 0;

    printf("Enter the size of the dictionary: ");
    scanf("%d", &dictSize);

    printf("Enter the dictionary words:\n");
    for(i=0; i<dictSize; i++) {
        scanf("%s", dictionary[i]);
    }

    printf("Enter a word to check: ");
    scanf("%s", word);

    wordSize = strlen(word);

    //Checking for spelling errors
    for(i=0; i<dictSize; i++) {
        if(strlen(dictionary[i]) == wordSize) {
            for(j=0; j<wordSize; j++) {
                if(dictionary[i][j] != word[j]) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                printf("The word '%s' is spelled correctly.\n", word);
                exit(0);
            }
            else {
                flag = 0;
            }
        }
    }

    printf("The word '%s' is spelled incorrectly.\n", word);
    return 0;
}