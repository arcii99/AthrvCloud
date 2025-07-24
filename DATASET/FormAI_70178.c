//FormAI DATASET v1.0 Category: Text processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

char *reverse_string(char *string);

int main()
{
    char input_line[MAX_LINE_LENGTH];
    char *reversed_string;
    int input_length;

    printf("Enter a string to reverse: ");
    fgets(input_line, MAX_LINE_LENGTH, stdin);

    // Remove newline character from input_line
    input_length = strlen(input_line);
    input_line[input_length-1] = '\0';

    reversed_string = reverse_string(input_line);

    printf("Your reversed string is: %s\n", reversed_string);

    return 0;
}

char *reverse_string(char *string)
{
    int string_length = strlen(string);
    char *reversed_string = malloc(string_length * sizeof(char));
    int i, j;

    for (i = 0, j = string_length-1; i < string_length; i++, j--)
    {
        reversed_string[i] = string[j];
    }

    reversed_string[string_length] = '\0';

    return reversed_string;
}