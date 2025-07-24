//FormAI DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    char original_string[MAX_SIZE], new_string[MAX_SIZE];
    int i, counter = 0, length;
    
    printf("Enter a string: ");
    fgets(original_string, MAX_SIZE, stdin);
    length = strlen(original_string);
    
    for (i = 0; i < length; i++)
    {
        if (original_string[i] != ' ')
        {
            new_string[counter++] = original_string[i];
        }
    }
    new_string[counter] = '\0';
    
    printf("Original string: %s", original_string);
    printf("\nNew string without spaces: %s", new_string);
    
    return 0;
}