//FormAI DATASET v1.0 Category: Word Count Tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[10000];
    int count = 0;
    printf("Enter a sentence to count words: ");
    scanf("%[^\n]", input);
    char *token = strtok(input, " "); //Splitting the input string at spaces
    while(token != NULL) {
        count++; 
        token = strtok(NULL, " "); //Moving to the next word
    }
    printf("The word count is %d\n", count);
    return 0;
}