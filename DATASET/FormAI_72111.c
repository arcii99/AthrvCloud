//FormAI DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // set the random seed based on the current time
    int a = rand() % 10 + 1; // get a random number between 1 and 10
    int b = rand() % 10 + 1; // get another random number between 1 and 10
    int answer = a + b; // calculate the correct answer

    printf("Welcome to the funny math program!\n");
    printf("What is %d + %d?\n", a, b);

    int user_answer;
    scanf("%d", &user_answer); // get the user's answer

    if (user_answer == answer) {
        printf("Congratulations! You got the correct answer!\n");
    } else {
        printf("Sorry, that's not the right answer.\n");
        printf("The correct answer is %d.\n", answer);
        printf("Don't worry, there's plenty of fish in the sea. Or in this case, plenty of math problems to solve!\n");
    }

    return 0;
}