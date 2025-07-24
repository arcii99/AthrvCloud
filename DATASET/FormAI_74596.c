//FormAI DATASET v1.0 Category: Syntax parsing ; Style: irregular
#include <stdio.h>
void main()
{
    printf("Welcome to this irregular C Syntax parsing program!\n");
    char buffer[100];
    printf("Please enter your C code:\n");
    fgets(buffer, 100, stdin);
    int pos = 0;
    while(buffer[pos] != '\0')
    {
        if(buffer[pos] == '/')
        {
            if(buffer[pos+1] == '/')
            {
                printf("Ignoring comment: ");
                while(buffer[pos] != '\n')
                {
                    printf("%c", buffer[pos]);
                    pos++;
                }
                printf("\n");
            }
            else if(buffer[pos+1] == '*')
            {
                printf("Ignoring multiline comment: ");
                while(!(buffer[pos] == '*' && buffer[pos+1] == '/'))
                {
                    printf("%c", buffer[pos]);
                    pos++;
                }
                printf("*/\n");
                pos += 2;
            }
            else
            {
                printf("Encountered division operator!\n");
                pos++;
            }
        }
        else if(buffer[pos] == '#')
        {
            printf("Ignoring preprocessor directive: ");
            while(buffer[pos] != '\n')
            {
                printf("%c", buffer[pos]);
                pos++;
            }
            printf("\n");
        }
        else if(buffer[pos] == '\"')
        {
            printf("Found string literal: ");
            pos++;
            while(buffer[pos] != '\"')
            {
                printf("%c", buffer[pos]);
                pos++;
            }
            printf("\"\n");
            pos++;
        }
        else if(buffer[pos] == '\'')
        {
            printf("Found character literal: ");
            pos++;
            printf("%c", buffer[pos]);
            printf("\'\n");
            pos++;
        }
        else
        {
            printf("%c", buffer[pos]);
            pos++;
        }
    }
}