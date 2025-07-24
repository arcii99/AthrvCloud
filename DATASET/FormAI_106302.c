//FormAI DATASET v1.0 Category: Spam Detection System ; Style: calm
#include <stdio.h>
#include <string.h>

int main()
{
    char message[1000];
    int count = 0;
    printf("Enter a message:\n");
    fgets(message, 1000, stdin);
    int length = strlen(message);
    for(int i=0; i<length; i++)
    {
        if(message[i] == 'c' || message[i] == 'C')
        {
            if(message[i+1] == 'a' || message[i+1] == 'A')
            {
                if(message[i+2] == 's' || message[i+2] == 'S')
                {
                    if(message[i+3] == 'i' || message[i+3] == 'I')
                    {
                        if(message[i+4] == 'n' || message[i+4] == 'N')
                        {
                            count++;
                        }
                    }
                }
            }
        }
    }
    if(count >= 2)
    {
        printf("This message appears to be spam.\n");
    }
    else
    {
        printf("This message is not spam.\n");
    }
    return 0;
}