//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: medieval
#include <stdio.h>
#include <ctype.h>

int main()
{
    char input[50], sanitized[50];
    int i, j;

    printf("Enter a string: ");
    fgets(input, 50, stdin);

    for(i = 0, j = 0; input[i] != '\0'; i++)
    {
        if(isalnum(input[i])) // check if the character is alphanumeric
        {
            sanitized[j++] = input[i];
        }
    }
    
    sanitized[j] = '\0'; // null terminate the sanitized string

    printf("The sanitized string is: %s\n", sanitized);

    return 0;
}