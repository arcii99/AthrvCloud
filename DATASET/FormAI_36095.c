//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main()
{
    char message[1000];
    printf("Enter the message: ");
    fgets(message, 1000, stdin);
    
    int i, length = strlen(message), count = 0;
    for (i = 0; i < length; i++)
    {
        if (message[i] == 'c' || message[i] == 'C')
        {
            count++;
        }
    }
    
    if (count == 1)
    {
        printf("This message contains 1 'c'\n");
    }
    else if (count > 1)
    {
        printf("This message contains %d 'c's\n", count);
    }
    else
    {
        printf("This message does not contain any 'c's\n");
    }
    
    return 0;
}