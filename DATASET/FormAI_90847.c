//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: imaginative
#include <stdio.h>

void move(char from, char to) {
    printf("Move disk from %c to %c\n", from, to);
}

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        move(from, to); // move the last disk from the from rod to the to rod
    } else {
        hanoi(n-1, from, aux, to); // move the top n-1 disks from the from rod to auxiliary rod
        move(from, to); // move the last disk from the from rod to the to rod
        hanoi(n-1, aux, to, from); // move the top n-1 disks from the auxiliary rod to the to rod
    }
}

int main() {
    int disks;
    
    printf("Welcome to the Towers of Hanoi game!\n");
    printf("How many disks do you want to play with? ");
    scanf("%d", &disks);
    
    // check for valid input
    if (disks <= 0) {
        printf("Invalid input. Number of disks must be greater than zero.\n");
        return 1;
    }
    
    // play the game
    printf("\nLet's play!\n");
    hanoi(disks, 'A', 'C', 'B');
    
    printf("\nCongratulations! You won the game!");
    
    return 0;
}