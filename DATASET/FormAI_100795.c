//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: happy
#include <stdio.h>

void moveDisk(char from, char to, int disk){
    printf("Move disk %d from %c to %c\n", disk, from, to);
}

void hanoi(int n, char from, char to, char extra){
    if(n == 1){
        moveDisk(from, to, n);
        return;
    }
    hanoi(n-1, from, extra, to);
    moveDisk(from, to, n);
    hanoi(n-1, extra, to, from);
}

int main(){
    int num_disks = 3;
    
    printf("Welcome to the Tower of Hanoi game! Let's play! :)\n");
    printf("We have %d disks and 3 rods labeled A, B, C.\n", num_disks);
    printf("The goal of the game is to move all the disks from rod A to rod C.\n");
    
    hanoi(num_disks, 'A', 'C', 'B');
    
    printf("Congratulations! You have completed the Tower of Hanoi game with %d disks!\n", num_disks);
    return 0;
}