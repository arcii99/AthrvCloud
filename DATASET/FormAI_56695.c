//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main()
{
    char input[BUFFER_SIZE];
    char compressed[BUFFER_SIZE];
    int i, j, count;
    
    printf("Please enter the string to be compressed: ");
    fgets(input, BUFFER_SIZE, stdin);

    count = 1;
    j = 0;

    for (i = 0; i < strlen(input) - 1; i++) {
        if (input[i] == input[i + 1]) {
            count++;
        }
        else {
            compressed[j++] = input[i];
            compressed[j++] = count + '0';
            count = 1;
        }
    }

    // Add the last character to the compressed string
    compressed[j++] = input[strlen(input) - 1];
    compressed[j++] = count + '0';
    compressed[j] = '\0';

    printf("The compressed string is: %s\n", compressed);

    return 0;
}