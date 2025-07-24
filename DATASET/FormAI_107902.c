//FormAI DATASET v1.0 Category: Funny ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    int numResponses = 4;
    char* responses[4] = {"Ha! That's funny.", "Oh, I get it now.", "What a knee-slapper.", "Hilarious!"};

    printf("Welcome to the Comedy Club!\n");

    while (1)
    {
        printf("Tell me a joke:\n");

        char joke[100];
        scanf("%[^\n]", joke);

        getchar(); //clear input buffer

        if (strcmp(joke, "exit") == 0 || strcmp(joke, "quit") == 0)
        {
            printf("Goodbye!");
            exit(0);
        }

        int responseIndex = rand() % numResponses;
        printf("%s %s\n", responses[responseIndex], "Would you like to hear another joke?");
    }

    return 0;
}