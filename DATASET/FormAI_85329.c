//FormAI DATASET v1.0 Category: Compression algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    int count = 1;

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    int length = strlen(input);

    for (int i = 0, j = 0; i < length; i++, j++) {
        if (input[i] == input[i+1]) {
            count++;
        }
        else {
            output[j] = input[i];
            j++;
            sprintf(output+j, "%d", count);
            count = 1;
        }
    }

    printf("Compressed string: %s\n", output);

    return 0;
}