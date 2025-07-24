//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100 // maximum input length

void sanitize(char* input, char* sanitized_input)
{
    int i, j=0;
    for(i=0; i<strlen(input); i++)
    {
        if(isalnum(input[i]))
        {
            sanitized_input[j++] = tolower(input[i]);
        }
    }
    sanitized_input[j] = '\0'; // terminate string
}

int main()
{
    char input[MAX_LEN];
    char sanitized_input[MAX_LEN];

    printf("Enter some text: ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character from input

    sanitize(input, sanitized_input);

    printf("Sanitized Input: %s\n", sanitized_input);

    return 0;
}