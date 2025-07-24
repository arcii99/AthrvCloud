//FormAI DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100     // the maximum number for the calculation
#define MAX_FACTOR 10   // the maximum factor for the multiplication
#define MAX_TIME 60     // the maximum time limit for the game

int main(void) {
    int score = 0;      // initialize the score as 0
    time_t start, end;  // variables for recording the time

    printf("Welcome to the Math Game!\n\n");

    printf("Rules: You will have %d seconds to answer as many multiplication questions as possible.\n", MAX_TIME);
    printf("       Each question will have a random factor between 1 and %d.\n", MAX_FACTOR);
    printf("       The result will be less than or equal to %d.\n", MAX_NUM);
    printf("       Type your answer and press Enter.\n");
    printf("       Each correct answer will earn you 1 point. No penalties for wrong answers.\n");
    printf("\nReady? Press Enter to start the game!");
    getchar();

    // start the game
    time(&start);   // record the start time
    while (difftime(time(NULL), start) < MAX_TIME) {    // keep playing until time's up
        // generate two random factors and ask the user to multiply them
        int factor1 = rand() % MAX_FACTOR + 1;
        int factor2 = rand() % MAX_FACTOR + 1;
        int expected = factor1 * factor2;
        printf("%d. What is %d x %d?  ", score + 1, factor1, factor2);

        // read the user's answer
        char input[10];
        fgets(input, 10, stdin);
        int answer = atoi(input);

        // check the answer and update the score
        if (answer == expected) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong. The correct answer is %d.\n", expected);
        }
    }
    time(&end); // record the end time

    // show the final score and time used
    printf("\nTime's up! Your final score is: %d\n", score);
    printf("You played for %.0f seconds.\n", difftime(end, start));

    return 0;
}