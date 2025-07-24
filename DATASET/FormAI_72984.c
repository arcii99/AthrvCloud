//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // Display greeting message
    printf("Welcome to the Automated Fortune Teller!\n\n");

    // Declare variables
    char name[20];
    int age;
    char question[100];
    char fortune[3][50] = {"It is certain", "Reply hazy, try again", "Don't count on it"};

    // Get user information
    printf("What is your name?\n");
    scanf("%s", name);
    printf("How old are you?\n");
    scanf("%d", &age);
    printf("What is your question? (Please enter yes or no question)\n");
    scanf("\n%[^\n]", question);

    // Seed random number generator with current time
    srand(time(NULL));

    // Generate random number to pick fortune
    int random = rand() % 3;

    // Display fortune
    printf("\n%s, the Automated Fortune Teller has your answer:\n\n", name);
    printf("%s\n\n", fortune[random]);

    return 0;
}