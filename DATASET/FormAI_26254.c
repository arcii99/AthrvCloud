//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: immersive
#include <stdio.h>

void moveDisk(char from, char to, int disk){
    printf("Move disk %d from %c to %c\n", disk, from, to);
}

void TOH(int disk, char A, char C, char B){
    if (disk == 1){
        moveDisk(A, C, disk);
    }
    else{
        TOH(disk-1, A, B, C);
        moveDisk(A, C, disk);
        TOH(disk-1, B, C, A);
    }
}

int main(){
    int disk;
    char A = 'A';
    char B = 'B';
    char C = 'C';

    printf("Welcome to the Tower of Hanoi Immersive Experience!\n");
    printf("Rules: You have to transfer all the disks from rod A to rod C.\n");
    printf("But remember, there are 3 rules that you must follow:\n");
    printf("1. Only one disk can be moved at a time.\n");
    printf("2. You can only move the top disk of a stack.\n");
    printf("3. A larger disk cannot be placed on top of a smaller disk.\n");
    printf("Enter the number of disks you want to start with: ");
    scanf("%d", &disk);

    TOH(disk, A, C, B);

    printf("Well done! You have completed the Tower of Hanoi challenge.\n");
    return 0;
}