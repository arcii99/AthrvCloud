//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main()
{
    int i, j, count, len, index = 0, prev = -1;
    char input[MAX_SIZE], output[MAX_SIZE], code[MAX_SIZE];

    printf("Enter the string to be compressed: ");
    fgets(input, MAX_SIZE, stdin);
    len = strlen(input);

    for (i = 0; i < len; i++) {
        count = 1;

        /* Check the next characters for similarity */
        for (j = i + 1; j < len; j++) {
            if (input[i] != input[j])
                break;
            count++;
        }

        /* If we have a sequence of similar characters, compress them */
        if (count > 2) {
            /* Store the compressed code */
            snprintf(code, sizeof(code), "%d%c", count, input[i]);
            for (j = 0; code[j]; j++)
                output[index++] = code[j];
            /* Set the previous index so we don't repeat characters */
            prev = i + count - 1;
            /* Skip the similar characters */
            i = j - 1;
        } else if (count == 2) {
            /* We have only two characters, so output them twice */
            output[index++] = input[i];
            output[index++] = input[i];
            /* Set the previous index so we don't repeat characters */
            prev = i + count - 1;
            /* Skip the similar characters */
            i = j - 1;
        } else {
            /* If the previous index is less than the current index, it means this character doesn't need to be encoded */
            if (i > prev)
                output[index++] = input[i];
        }
    }

    /* Add the null terminator to the compressed string */
    output[index] = '\0';

    /* Print the compressed string */
    printf("Compressed string: %s\n", output);

    return 0;
}