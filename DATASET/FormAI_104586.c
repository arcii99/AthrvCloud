//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: visionary
#include<stdio.h>
#include<string.h>

int main()
{
    char input[1000];
    printf("Enter the string in Alien Language: ");
    fgets(input, 1000, stdin);

    int length = strlen(input);
    int i;

    for(i=0; i<length; i++)
    {
        switch(input[i])
        {
            case '^':
                printf("%c", 'a');
                break;
            case '@':
                printf("%c", 'b');
                break;
            case '*':
                printf("%c", 'c');
                break;
            case '&':
                printf("%c", 'd');
                break;
            case '$':
                printf("%c", 'e');
                break;
            case '#':
                printf("%c", 'f');
                break;
            default:
                printf("%c", input[i]);
        }
    }

    return 0;
}