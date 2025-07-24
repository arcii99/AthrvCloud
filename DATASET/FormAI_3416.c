//FormAI DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int main()
{
    char input[MAX_LEN];
    char output[MAX_LEN];
    char *ptr = input;
    char *optr = output;

    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin);

    while (*ptr)
    {
        if (*ptr == ' ')
        {
            ptr++;
            continue;
        }
        else if (*ptr == '\n')
        {
            break;
        }

        int count = 0;
        char *temp = ptr;
        while (*temp)
        {
            if (*temp == *ptr)
            {
                count++;
                temp++;
            }
            else
            {
                break;
            }
        }
        
        if (count > 1)
        {
            *optr++ = '(';
            *optr++ = count + '0';
            *optr++ = *ptr;
            *optr++ = ')';
            ptr += count;
        }
        else
        {
            *optr++ = *ptr++;
        }
    }
    
    *optr = '\0';

    printf("Processed string: %s\n", output);

    return 0;
}