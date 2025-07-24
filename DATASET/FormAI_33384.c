//FormAI DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to roll the dice
int roll_dice(int faces) {
    return rand() % faces + 1;
}

int main() {
    srand(time(0));

    int num_dice, num_faces, roll_sum;
    char choice;

    do {
        // get user inputs
        printf("How many dice do you want to roll? ");
        scanf("%d", &num_dice);
        printf("How many faces does each die have? ");
        scanf("%d", &num_faces);

        roll_sum = 0; // reset roll sum for each roll

        // roll each die and print result
        printf("Roll results: ");
        for (int i = 0; i < num_dice; i++) {
            int roll = roll_dice(num_faces);
            printf("%d ", roll);
            roll_sum += roll;
        }

        // print total roll sum
        printf("\nTotal roll sum: %d\n", roll_sum);

        // ask user if they want to roll again
        printf("Roll again? (y/n) ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for playing!\n");

    return 0;
}