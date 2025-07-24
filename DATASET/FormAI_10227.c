//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char input;
    int score = 0, count = 0;
    srand(time(NULL)); // set seed for random number generator
    printf("Welcome to the Gratitude Game! Press 'y' to continue or 'n' to quit.\n");
    scanf("%c", &input);
    if (input == 'n') {
        printf("Goodbye!\n");
        exit(0);
    }
    printf("Instructions: You will be given a random number between 1 and 10.\
            \nYou must say something you are grateful for that corresponds with that number.\
            \nFor example, if the number is 3, you could say 'I am grateful for my health'.\
            \nReady? Press 'y' to start or 'n' to quit.\n");
    scanf(" %c", &input);
    if (input == 'n') {
        printf("Goodbye!\n");
        exit(0);
    }
    while (input == 'y') {
        int rand_num = 1 + rand() % 10;
        printf("What are you grateful for that corresponds with %d?\n", rand_num);
        scanf(" %[^\n]s", input);
        count++;
        if (count == 10) {
            printf("You've answered 10 questions! Your final score is %d.\n", score);
            break;
        }
        else {
            score++;
            printf("Great! You've earned a point. Your current score is %d.\n", score);
            printf("Press 'y' to continue or 'n' to quit.\n");
            scanf(" %c", &input);
            if (input == 'n') {
                printf("You've answered %d questions. Your final score is %d. Goodbye!\n", count, score);
                break;
            }
        }
    }
    return 0;
}