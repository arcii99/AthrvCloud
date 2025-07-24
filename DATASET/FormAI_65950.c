//FormAI DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to my super funny compression algorithm!\n");

    printf("This algorithm works by replacing every occurrence of the word 'banana' with just 'b'.\n");
    printf("Because let's face it, who needs the extra letters?\n");

    char input[100];
    printf("Please enter your text to be compressed: ");
    fgets(input, 100, stdin);

    char compressed[100];
    int compressed_index = 0;

    int i = 0;
    while (input[i] != '\0')
    {
        if (input[i] == 'b' && input[i+1] == 'a' && input[i+2] == 'n' && input[i+3] == 'a' && input[i+4] == 'n' && input[i+5] == 'a')
        {
            compressed[compressed_index] = 'b';
            i += 6;
        }
        else
        {
            compressed[compressed_index] = input[i];
            i++;
        }

        compressed_index++;
    }

    printf("Here is your funny compressed text: ");
    printf("%s", compressed);

    printf("Thanks for using my compression algorithm! I hope it helped you save some typing.\n");

    return 0;
}