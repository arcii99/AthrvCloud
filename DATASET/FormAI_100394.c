//FormAI DATASET v1.0 Category: Syntax parsing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input[100];
    char tokens[10][10];
    char delimeter[] = " ";
    int i = 0;

    printf("Enter the C syntax to parse:\n");
    fgets(input, 100, stdin);

    char* token = strtok(input, delimeter);

    while (token != NULL) {
        strcpy(tokens[i], token);
        i++;
        token = strtok(NULL, delimeter);
    }

    printf("Parsed tokens are:\n");
    for (int j = 0; j < i; j++) {
        printf("%s\n", tokens[j]);
    }

    return 0;
}