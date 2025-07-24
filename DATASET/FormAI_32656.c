//FormAI DATASET v1.0 Category: Word Count Tool ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countWords(char *inputString);

int main() {
    char input[1000];
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);
    countWords(input);
    return 0;
}

void countWords(char *inputString) {
    int count = 0, flag = 0;
    char *token = strtok(inputString, " ");
    while(token != NULL) {
        flag = 0;
        for(int i=0; i<strlen(token); i++) {
            if(!isalpha(token[i])) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }
    printf("The number of words in the sentence: %d", count);
}