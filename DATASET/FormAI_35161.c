//FormAI DATASET v1.0 Category: Text processing ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[100];
    printf("Enter a string to encrypt: ");
    fgets(input, sizeof(input), stdin);
    int length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(input[i]))
        {
            if (isupper(input[i]))
            {
                input[i] = 'Z' - (input[i] - 'A');
            }
            else if (islower(input[i]))
            {
                input[i] = 'z' - (input[i] - 'a');
            }
        }
        else if (isdigit(input[i]))
        {
            input[i] = '9' - input[i] + '0';
        }
        else
        {
            switch(input[i])
            {
                case ' ':
                    input[i] = '%';
                    break;
                case ',':
                    input[i] = '/';
                    break;
                case '.':
                    input[i] = '\\';
                    break;
                case '?':
                    input[i] = '!';
                    break;
                case '!':
                    input[i] = '-';
                    break;
                default:
                    input[i] = input[i];
            }
        }  
    }

    printf("Encrypted string: %s\n", input);
    return 0;
}