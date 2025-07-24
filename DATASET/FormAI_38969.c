//FormAI DATASET v1.0 Category: Syntax parsing ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int length;

    printf("Enter a C syntax statement: ");
    scanf("%s", input);

    length = strlen(input);

    if(length % 2 == 1) {
        printf("Syntax error!\n");
    } else {
        char first[length/2], second[length/2];
        int i;

        for(i = 0; i < length/2; i++) {
            first[i] = input[i];
        }
        first[i] = '\0';

        for(i = length/2; i < length; i++) {
            second[i-length/2] = input[i];
        }
        second[i-length/2] = '\0';

        if(strcmp(first, "int") == 0) {
            printf("Variable name: %s\n", second);
        } else if(strcmp(first, "if") == 0) {
            printf("If statement: %s\n", second);
        } else if(strcmp(first, "for") == 0) {
            printf("For loop: %s\n", second);
        } else if(strcmp(first, "while") == 0) {
            printf("While loop: %s\n", second);
        } else {
            printf("Unknown syntax!\n");
        }
    }

    return 0;
}