//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char answers[10][50] = {"Yes", "No", "Maybe", "It is uncertain", "Try again later", "Outlook not so good", "Ask again", "The future looks bright", "Cannot predict now", "Signs point to yes"};
    char question[100];

    printf("Welcome to the Automated Fortune Teller.\n");
    printf("Enter your question:\n");

    fgets(question, 100, stdin);
    printf("Thinking...\n");

    srand(time(NULL));
    int index = rand() % 10;

    printf("The answer to your question \"%s\" is: %s\n", question, answers[index]);

    return 0;
}