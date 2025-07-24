//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char questions[10][100] = { "Will I find true love?",
                                "Will I be rich?",
                                "Will I travel the world?",
                                "Will I achieve great success?",
                                "Will I find inner peace?",
                                "Will I have good health?",
                                "Will I win the lottery?",
                                "Will I find my purpose in life?",
                                "Will I meet my soulmate?",
                                "Will I be happy?" };
    char answers[10][100] = { "It is certain",
                              "Without a doubt",
                              "You may rely on it",
                              "Yes definitely",
                              "It is decidedly so",
                              "As I see it, yes",
                              "Most likely",
                              "Yes",
                              "Outlook good",
                              "Signs point to yes" };
    char repeat;
    srand(time(NULL));
    printf("Welcome to the Automated Fortune Teller program!\n");
    do {
        printf("\nPlease ask a question:\n> ");
        scanf(" %[^\n]s", questions[10]);
        printf("\nThinking...\n\n");
        int i = rand() % 10;
        printf("The answer to your question '%s' is: %s.\n", questions[i], answers[i]);
        printf("\nWould you like to ask another question? (y/n): ");
        scanf(" %c", &repeat);
    } while (repeat == 'y' || repeat == 'Y');

    printf("\nThank you for using the Automated Fortune Teller program. Goodbye!\n");
    return 0;
}