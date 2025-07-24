//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    char input[MAX_SIZE];
    int len;
    int i,j,k;

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    len = strlen(input);

    // Loop through the input string
    for(i = 0; i < len; i++)
    {
        // If the character is not alphanumeric, it could be a special character
        if(!isalnum(input[i]))
        {
            // Check if it's a repeat character sequence
            for(j = i + 1; j < len; j++)
            {
                if(input[j] != input[i])
                {
                    break;  
                }
            }

            // If it's a repeat sequence, we have an intrusion
            if(j - i > 3)
            {
                printf("Intrusion detected: REPEAT CHARACTER SEQUENCE %c%c%c%c\n", input[i], input[i], input[i], input[i]);
                return 1; // Exit the program
            }

            // Check for a shell injection
            if(input[i] == '$')
            {
                for(j = i + 1; j < len; j++)
                {
                    if(input[j] == '(')
                    {
                        for(k = j + 1; k < len; k++)
                        {
                            if(input[k] == ')')
                            {
                                printf("Intrusion detected: SHELL INJECTION\n");
                                return 1; // Exit the program
                            }
                        }
                    }
                }
            }

            // Check for a SQL injection
            if(input[i] == '-')
            {
                if(input[i+1] == '-')
                {
                    printf("Intrusion detected: SQL INJECTION\n");
                    return 1; // Exit the program
                }
            }

            // Check for a buffer overflow
            if(input[i] == 'A')
            {
                if(input[i+1] == 'A' && input[i+2] == 'A' && input[i+3] == 'A')
                {
                    printf("Intrusion detected: BUFFER OVERFLOW\n");
                    return 1; // Exit the program
                }
            }
        }
    }

    printf("No intrusion detected.\n");
    return 0;
}