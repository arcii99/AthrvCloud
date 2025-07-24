//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize seed for random number generator
    srand(time(NULL));

    printf("Welcome to Automated Fortune Teller\n\n");

    while (1)
    {
        printf("Enter your question (type 'quit' to exit): ");
        char input[100];
        fgets(input, 100, stdin);

        // Convert input to lowercase for easier comparison
        for (int i = 0; input[i]; i++)
            input[i] = tolower(input[i]);

        // Check if the user wants to quit
        if (strcmp(input, "quit\n") == 0)
        {
            printf("Exiting the program...\n");
            break;
        }

        // Generate random number between 1 and 10
        int result = rand() % 10 + 1;

        // Use the random number to generate a fortune
        switch (result)
        {
            case 1:
                printf("It is certain.\n");
                break;
            case 2:
                printf("It is decidedly so.\n");
                break;
            case 3:
                printf("Without a doubt.\n");
                break;
            case 4:
                printf("Yes – definitely.\n");
                break;
            case 5:
                printf("You may rely on it.\n");
                break;
            case 6:
                printf("As I see it, yes.\n");
                break;
            case 7:
                printf("Most likely.\n");
                break;
            case 8:
                printf("Outlook good.\n");
                break;
            case 9:
                printf("Yes.\n");
                break;
            case 10:
                printf("Signs point to yes.\n");
                break;
            default:
                printf("Error: result is out of range.\n");
        }
        printf("\n");
    }

    return 0;
}