//FormAI DATASET v1.0 Category: Math exercise ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // Generate two random numbers between 1 and 20
    int num1 = rand() % 20 + 1;
    int num2 = rand() % 20 + 1;

    printf("Welcome to the Brave Math Exercise!\n");
    printf("You will be asked to solve a challenging math problem.\n");
    printf("Are you ready for the challenge?\n");

    char response[10];
    scanf("%s", response);

    if (response[0] == 'Y' || response[0] == 'y') {
        printf("Great, here's your problem:\n");
        printf("%d + %d = ", num1, num2);

        int answer;
        scanf("%d", &answer);

        if (answer == num1 + num2) {
            printf("Congratulations, you solved the problem!\n");
        } else {
            printf("Sorry, the correct answer is %d.\n", num1 + num2);
        }
    } else {
        printf("Oh no, the coward has retreated!\n");
    }

    return 0;
}