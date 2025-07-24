//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char* questions[6] = {"What is my future?",
                          "Will I get rich?",
                          "Will I find true love?",
                          "Am I going to be successful?",
                          "Is it going to rain tomorrow?",
                          "Should I invest in cryptocurrency?"};
    char* answers[8] = {"Yes, definitely.", 
                        "It is likely.", 
                        "Without a doubt.", 
                        "Reply hazy, try again.",
                        "Cannot predict now.",
                        "Don't count on it.",
                        "Outlook not so good.",
                        "Very doubtful."};
    char question[100];
    int answer_index;

    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller! Ask a question, any question...\n");
    fgets(question, 100, stdin);
    answer_index = rand() % 8;

    printf("You asked: %s", question);
    printf("The answer is: %s", answers[answer_index]);

    return 0;
}