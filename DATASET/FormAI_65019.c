//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    int i = 0, j = 0;

    printf("Enter input: ");
    scanf("%s", input);

    while (input[i])
    {
        if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))
        {
            input[j] = input[i];
            j++;
        }
        i++;
    }
    input[j] = '\0';

    printf("Sanitized input: %s", input);
    
    return 0;
}