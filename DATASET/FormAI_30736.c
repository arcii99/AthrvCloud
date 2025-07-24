//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

/* function to sanitize user input by removing leading and trailing white spaces */
void sanitize(char *input)
{
    char *start = input;
    char *end = input + strlen(input) - 1;

    /* remove leading white spaces */
    while (*start && isspace(*start))
    {
        start++;
    }

    /* remove trailing white spaces */
    while (end > start && isspace(*end))
    {
        end--;
    }

    /* null terminate the sanitized input */
    *(end + 1) = '\0';

    /* move the sanitized input to the beginning of the input buffer */
    memmove(input, start, strlen(start) + 1);
}

int main()
{
    char input[BUFFER_SIZE];

    /* read user input */
    printf("Enter a string: ");
    fgets(input, BUFFER_SIZE, stdin);

    /* sanitize user input */
    sanitize(input);

    /* print sanitized input */
    printf("Sanitized Input: %s\n", input);

    return 0;
}