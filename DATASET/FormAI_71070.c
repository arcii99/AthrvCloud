//FormAI DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000

char *compress(char *input) {
    int count = 1, index = 0, i;
    char prev = input[0];
    char *result = (char *)malloc(sizeof(char) * SIZE);

    for (i = 1; i < strlen(input); i++) {
        if (input[i] == prev) {
            count++;
        } else {
            sprintf(result + index, "%c%d", prev, count);
            prev = input[i];
            count = 1;
            index = strlen(result);
        }
    }

    sprintf(result + index, "%c%d", prev, count);
    return result;
}

int main() {
    char input[SIZE];
    printf("Enter the input string:\n");
    scanf("%[^\n]%*c", input);
    printf("\nCompressed string: %s\n", compress(input));
    return 0;
}