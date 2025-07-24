//FormAI DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    printf("Write a message for your loved one: ");
    fgets(message, sizeof(message), stdin);
    printf("\n");
    
    printf("You wrote:\n");
    printf("%s", message);
    printf("\n");
    
    int i, j;
    int length = strlen(message);
    
    printf("Your message in romantic style:\n");
    for(i=0; i<length; i++)
    {
        if(i%2 == 0)
        {
            for(j=0; j<i; j++)
            {
                printf("-");
            }
            printf("%c\n", message[i]);
        }
        else
        {
            for(j=length; j>i; j--)
            {
                printf("-");
            }
            printf("%c\n", message[i]);
        }
    }
    
    return 0;
}