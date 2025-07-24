//FormAI DATASET v1.0 Category: Word Count Tool ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

int main()
{
    char input[MAX_BUFFER_SIZE];
    char* token;
    int count = 0;

    printf("Enter a string to count words: ");
    fgets(input, MAX_BUFFER_SIZE, stdin); // taking input from user

    token = strtok(input, " ");
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, " "); // splitting the string with space delimiter
    }

    printf("\nNumber of words in the string: %d\n", count);

    return 0;
}