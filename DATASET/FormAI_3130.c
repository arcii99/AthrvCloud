//FormAI DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int roll_dice() {
    return (rand() % 6) + 1;
}

int main() {
    int choice, dice_roll;
    srand(time(0)); // Seed the random number generator with current time

    printf("***Welcome to Dice Roller***\n");
    printf("1. Roll a single die\n");
    printf("2. Roll two dice\n");
    printf("3. Roll a custom dice\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            dice_roll = roll_dice();
            printf("\nYou rolled a %d\n", dice_roll);
            break;
        case 2:
            dice_roll = roll_dice() + roll_dice();
            printf("\nYou rolled a %d\n", dice_roll);
            break;
        case 3:
            int num_of_dice, dice_faces, i, total=0;
            printf("Enter the number of dice: ");
            scanf("%d", &num_of_dice);
            printf("Enter the number of faces on each dice: ");
            scanf("%d", &dice_faces);
            printf("\nYou rolled: ");
            for(i=0; i<num_of_dice; i++) {
                int roll = (rand() % dice_faces) + 1;
                printf("%d ", roll);
                total += roll;
            }
            printf("\nTotal: %d\n", total);
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
    }

    return 0;
}