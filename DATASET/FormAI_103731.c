//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main()
{
    char input[MAX_LEN];
    char compressed[MAX_LEN];
    int count;
    int i, j;

    printf("Enter string to be compressed: ");
    fgets(input, MAX_LEN, stdin);

    // Remove new line character from input
    input[strcspn(input, "\n")] = 0;

    // Perform compression
    for(i = 0, j = 0; i < strlen(input); i += count, j++)
    {
        count = 1;

        while(input[i] == input[i+count] && count < 9)
        {
            count++;
        }

        if(count > 1)
        {
            compressed[j] = count + '0';
            compressed[j+1] = input[i];
            j++;
        }
        else
        {
            compressed[j] = input[i];
        }
    }

    compressed[j] = '\0';

    // Print compressed string
    printf("Compressed string: %s\n", compressed);

    return 0;
}