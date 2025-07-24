//FormAI DATASET v1.0 Category: Dice Roller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, dice, total = 0;
    char playerName[100];
    
    printf("Hello there, my love! What is your name?\n");
    scanf("%s", playerName);
    printf("Oh %s, what a beautiful name! Let's roll the dice, shall we?\n", playerName);
    
    srand(time(NULL));
    for(i = 0; i < 2; i++) {
        dice = rand() % 6 + 1;
        printf("Dice %d: %d\n", i+1, dice);
        total += dice;
    }
    
    printf("Total score: %d\n", total);
    
    if(total % 2 == 0) {
        printf("Congratulations my love, you have rolled an even number! This must be a sign of good fortune.\n");
    } else {
        printf("Oh no, my love. You have rolled an odd number. Don't worry, I will always be by your side to bring you good luck.\n");
    }
    
    printf("May the dice roll always in our favor, my love. I cherish you.\n");
    
    return 0;
}