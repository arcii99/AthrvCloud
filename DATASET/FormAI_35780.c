//FormAI DATASET v1.0 Category: Spell checking ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *wordList[] = {"hello", "world", "this", "is", "a", "spell", "checking", "program"};

int checkSpelling(char *word) {
    for(int i=0; i<8; i++) {
        if(strcmp(word, wordList[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {

    int numWords;
    printf("Enter the number of words you want to check: ");
    scanf("%d", &numWords);

    char **words = (char**)malloc(numWords * sizeof(char*));

    for(int i=0; i<numWords; i++) {
        words[i] = (char*)malloc(50 * sizeof(char));
        printf("Enter word %d: ", i+1);
        scanf("%s", words[i]);
    }

    printf("\n");
    printf("------ SPELL CHECK RESULTS ------\n\n");

    for(int i=0; i<numWords; i++) {
        if(checkSpelling(words[i])) {
            printf("%s is spelled correctly!\n", words[i]);
        } else {
            printf("%s is spelled incorrectly!\n", words[i]);
        }
    }

    for(int i=0; i<numWords; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}