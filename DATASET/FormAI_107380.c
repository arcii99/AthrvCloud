//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include <stdio.h>

void move(int n, char source, char auxiliary, char destination){
    if (n == 1){
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    move(n-1, source, destination, auxiliary);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    move(n-1, auxiliary, source, destination);
}

int main(){
    int n = 4; // Number of disks
    char source = 'A', auxiliary = 'B', destination = 'C'; // Rods

    printf("Welcome to the Tower of Hanoi game!\n");
    printf("Your goal is to move the disks from rod A to rod C.\n");
    printf("You can only move one disk at a time, and you cannot place a larger disk on top of a smaller disk.\n");
    printf("Let's begin!\n\n");
    
    printf("The initial state of the game is:\n");
    for (int i = n; i >= 1; i--){
        printf("Disk %d on rod %c\n", i, source);
    }
    printf("\n");
    printf("Instructions:\n\n");

    move(n, source, auxiliary, destination);

    printf("\nThe final state of the game is:\n");
    for (int i = n; i >= 1; i--){
        printf("Disk %d on rod %c\n", i, destination);
    }
    printf("\nCongratulations, you have won the game!");

    return 0;
}