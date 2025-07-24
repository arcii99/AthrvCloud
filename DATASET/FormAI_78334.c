//FormAI DATASET v1.0 Category: String manipulation ; Style: real-life
#include<stdio.h>
#include<string.h>

int main()
{
    char name[100], temp[100];
    int choice, len;

    printf("Enter your name: ");
    scanf("%s", name);

    len = strlen(name);

    printf("\n1. Reverse the name\n2. Convert name to uppercase\n3. Convert name to lowercase\n4. Replace a character in the name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            for(int i=len-1, j=0; i>=0; i--, j++)
            {
                temp[j] = name[i];
            }
            printf("\nReversed name: %s", temp);
            break;

        case 2:
            for(int i=0; i<len; i++)
            {
                if(name[i]>=97 && name[i]<=122)
                {
                    name[i] = name[i] - 32;
                }
            }
            printf("\nUppercase name: %s", name);
            break;

        case 3:
            for(int i=0; i<len; i++)
            {
                if(name[i]>=65 && name[i]<=90)
                {
                    name[i] = name[i] + 32;
                }
            }
            printf("\nLowercase name: %s", name);
            break;

        case 4:
            char ch, replace;
            printf("\nEnter the character to replace: ");
            scanf(" %c", &ch);
            printf("\nEnter the replacement character: ");
            scanf(" %c", &replace);

            for(int i=0; i<len; i++)
            {
                if(name[i] == ch)
                {
                    name[i] = replace;
                }
            }
            printf("\nName after replacing %c with %c: %s", ch, replace, name);
            break;

        default:
            printf("\nInvalid choice!");
            break;
    }

    return 0;
}