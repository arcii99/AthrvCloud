//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: accurate
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char statement[1000];
    printf("Enter a statement: ");
    fgets(statement, sizeof(statement), stdin);

    const char s[2] = " ";
    char * token;

    int countC = 0;
    int countWords = 0;

    token = strtok(statement, s);

    while( token != NULL ) {
        countWords++;
        if (strcmp(token, "C") == 0 || strcmp(token, "c") == 0){
            countC++;
        }
        token = strtok(NULL, s);
    }
    printf("\nNumber of times the word 'C' appears: %d\n", countC);
    printf("Total number of words: %d\n", countWords);
    return 0;
}