//FormAI DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char* compress(char input[]) {
    int i = 0;
    int count = 1;
    int len = strlen(input);

    char* output = malloc(MAX_SIZE * sizeof(char));

    for (i = 0; i < len; i++) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            char ccount[MAX_SIZE];
            sprintf(ccount, "%d", count);
            strcat(output, ccount);
            strcat(output, &input[i]);
            count = 1;
        }
    }

    return output;
}

int main() {
    char input[MAX_SIZE];
    printf("Enter the input string:\n");
    scanf("%[^\n]s", input);

    char* compressed = compress(input);

    printf("The compressed string is: %s\n", compressed);

    free(compressed);

    return 0;
}