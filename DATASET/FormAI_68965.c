//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dice_roll(int sides) {
    return (rand() % sides) + 1;
}

int main(void) {

    srand(time(NULL));
    int sides;
    printf("Welcome to Cyberpunk Dice Roller!\n");
    printf("Enter the number of sides of your dice: ");
    scanf("%d", &sides);
    getchar(); // consume newline

    printf("Press Enter to roll the dice...\n");

    while (1) {
        getchar(); // wait for enter key press
        int result = dice_roll(sides);
        printf("You rolled a %d!\n\n", result);
        printf("Press Enter to roll again or 'q' to quit...\n");
        char c = getchar();
        if (c == 'q') {
            printf("Thanks for playing Cyberpunk Dice Roller. Goodbye!");
            break;
        }
    }

    return 0;
}