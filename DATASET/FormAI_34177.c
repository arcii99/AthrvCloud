//FormAI DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the game of luck!\n");

    int num;
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &num);

    if (num < 1 || num > 10) {
        printf("Invalid input. Exiting program.\n");
        return 0;
    }

    srand(time(NULL));
    int random_num = rand() % 10 + 1;
    printf("The computer has chosen %d.\n", random_num);

    if (num == random_num) {
        printf("Congratulations! You have won!\n");
    } else {
        printf("Better luck next time!\n");
    }

    return 0;
}