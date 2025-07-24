//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    srand((unsigned) time(&t));  // Initializing random number generator

    char answers[10][50] = {
                            "It is certain",
                            "Without a doubt",
                            "You may rely on it",
                            "Yes, definitely",
                            "It is decidedly so",
                            "As I see it, yes",
                            "Most likely",
                            "Yes",
                            "Outlook good",
                            "Signs point to yes"
                            };

    printf("Welcome to the Automatic Fortune Teller!\n");
    printf("Ask a question that can be answered with a yes or no:\n");

    char question[100];
    fgets(question, 100, stdin);  // Reading user input

    int random_number = rand() % 10;  // Generating a random number from 0 to 9
    printf("\nAnswer: %s\n", answers[random_number]);

    return 0;
}