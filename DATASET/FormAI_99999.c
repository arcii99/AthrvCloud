//FormAI DATASET v1.0 Category: DOS detector ; Style: cheerful
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char command[100];
    int i, count = 0;
    printf("Welcome to the C DOS detector program!\n");

    while(1)
    {
        printf("\nEnter the command: ");
        gets(command);
        count = strlen(command);
        
        for(i=0; i<count; i++)
        {
            if(command[i] == 'c' || command[i] == 'C')
            {
                if(i+2<count && command[i+1] == ':' && command[i+2] == '\\')
                {
                    printf("\nSorry, this is a C DOS command. Try again!\n");
                    break;
                }
            }
        }

        if(i == count)
        {
            printf("\nThis is not a C DOS Command. Good job!\n");
        }

    }

    return 0;
}