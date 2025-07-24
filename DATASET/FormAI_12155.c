//FormAI DATASET v1.0 Category: Word Count Tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1000];
    int count = 0;

    printf("Welcome to the Happy Word Count Tool!\n");
    printf("Enter a sentence or paragraph (less than or equal to 1000 characters):\n");
    fgets(str, 1000, stdin);

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            count++;
        }
    }

    printf("Your sentence/paragraph contains %d happy words!\n", count);

    return 0;
}