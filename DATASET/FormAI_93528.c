//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_dice, num_sides, i, roll, total = 0;
    char cipher[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-={}[]|\:;’<,>.?/~`";

    srand(time(0)); // seed random number generator with current time

    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &num_sides);

    printf("\nRolling...");
    for (i = 1; i <= num_dice; i++) {
        roll = rand() % num_sides + 1;
        total += roll;
        printf("%c%c%c%c%c%c%c", cipher[roll*2-2], cipher[roll*2-1], cipher[roll*2], cipher[roll*2+1], cipher[roll*2+2], cipher[roll*2+3], cipher[roll*2+4]);
    }

    printf("\n\nTotal roll: ");
    for (i = 0; i < 5; i++) {
        printf("%c", cipher[(total % 64) * 2]);
        printf("%c", cipher[(total % 64) * 2 + 1]);
        total /= 64;
    }
    printf("\n");

    return 0;
}