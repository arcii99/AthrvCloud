//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Type your question and receive your answer...\n");
    printf("Enter 'quit' to end the program.\n\n");

    while (1)
    {
        char input[1000];
        printf("Question: ");
        fgets(input, 1000, stdin);

        if (strcmp(input, "quit\n") == 0)
        {
            printf("Goodbye!\n");
            break;
        }

        int num = rand() % 5;

        switch (num)
        {
            case 0:
                printf("Yes, definitely.\n");
                break;
            case 1:
                printf("It is decidedly so.\n");
                break;
            case 2:
                printf("Ask again later.\n");
                break;
            case 3:
                printf("Cannot predict now.\n");
                break;
            case 4:
                printf("Don't count on it.\n");
                break;
        }
    }

    return 0;
}