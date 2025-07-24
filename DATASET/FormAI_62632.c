//FormAI DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        fprintf(stderr, "Error: could not open file \"%s\"\n", argv[1]);
        return EXIT_FAILURE;
    }

    char buffer[MAX_BUFFER_SIZE + 1];
    size_t word_count = 0;
    size_t buffer_len;

    while ((buffer_len = fread(buffer, 1, sizeof(buffer) - 1, fp)) > 0)
    {
        buffer[buffer_len] = '\0';

        char *word_start = buffer;
        char *word_end = buffer;

        // Asynchronously search for word boundaries
        while (*word_end)
        {
            while (*word_start && !isalpha(*word_start)) ++word_start;
            word_end = word_start;
            while (*word_end && isalpha(*word_end)) ++word_end;

            if (word_end > word_start) ++word_count;
            word_start = word_end;
        }
    }

    fclose(fp);

    printf("%zu words\n", word_count);

    return EXIT_SUCCESS;
}