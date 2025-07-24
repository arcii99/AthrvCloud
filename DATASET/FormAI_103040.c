//FormAI DATASET v1.0 Category: Spam Detection System ; Style: energetic
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Welcome to our new Spam Detection System!\n");
    char message[100];
    int count = 0;
    printf("Please enter your message: ");
    fgets(message, 100, stdin);
    char spam[3][10] = {"offer", "win", "free"};
    char *token = strtok(message, " ,.!?");

    while (token != NULL)
    {
        for (int i = 0; i < 3; i++) 
        {
            if (strcmp(token, spam[i]) == 0) 
            {
                count++;
            }
        }
        token = strtok(NULL, " ,.!?");
    }

    if (count >= 2) 
    {
        printf("This message is considered spam.\n");
    }
    else 
    {
        printf("This message is not spam.\n");
    }

    return 0;
}