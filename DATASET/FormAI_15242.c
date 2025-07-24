//FormAI DATASET v1.0 Category: Dice Roller ; Style: surrealist
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));

    printf("Welcome to the Surrealist Dice Roller!\n");
    printf("Immerse yourself in the randomness...\n");
    printf("Roll the dice by pressing Enter!\n");

    getchar(); 

    int dice1 = (rand() % 6) + 1;
    int dice2 = (rand() % 6) + 1;

    printf("The dice have been cast...\n");
    printf("Your fate is unfolding...\n");

    for (int i = 0; i < 5; i++) {
        printf("* * *\n");
        sleep(1);
    }

    printf("The first dice reveals the number %d...\n", dice1);
    printf("The second dice reveals the number %d...\n", dice2);
    printf("Your total is %d...\n", dice1 + dice2);

    if (dice1 == dice2) {
        printf("A double? The universe is clearly favoring you today!\n");
    }

    printf("May your surreal journey continue...\n");

    return 0;
}