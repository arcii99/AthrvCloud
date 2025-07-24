//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char questions[10][100] = {"What is my future?", "Will I be rich?", "What will happen to me tomorrow?", "Should I take that job?", "Will I meet my soulmate?", "Is today my lucky day?", "Should I buy that lottery ticket?", "Will my dreams come true?", "What is my destiny?", "Am I on the right path?"};
    char answers[10][100] = {"Most likely", "Outlook good", "Signs point to yes", "Without a doubt", "Yes definitely", "Cannot predict now", "Concentrate and ask again", "Don't count on it", "Outlook not so good", "Very doubtful"};

    // Get the current time
    time_t currentTime;
    time(&currentTime);
    srand(currentTime);

    // Print the welcome message
    printf("Welcome to the Automated Fortune Teller!\n");

    // Loop until the user decides to quit
    while (1)
    {
        // Ask the user to enter their question
        printf("\nAsk me a question or type 'quit' to exit: ");
        char input[100];
        scanf("%[^\n]s", input);
        getchar();

        // Check if the user wants to quit
        if (strcmp(input, "quit") == 0)
            break;

        // Generate a random answer from the answers array
        int randomIndex = rand() % 10;
        char randomAnswer[100];
        strcpy(randomAnswer, answers[randomIndex]);

        // Print the answer to the user's question
        printf("%s\n", randomAnswer);
    }

    // Print the goodbye message
    printf("\nThank you for using the Automated Fortune Teller!\n");

    return 0;
}