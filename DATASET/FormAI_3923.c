//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: funny
#include<stdio.h>

void moveDisks(int, char, char, char);

int main() {
    int numDisks;
    printf("Welcome to my Tower of Hanoi game!\n");
    printf("Please enter the number of disks you'd like to play with: ");
    scanf("%d", &numDisks);
    printf("\nLet's begin!!!\n\n");
    moveDisks(numDisks, 'A', 'B', 'C');
    printf("\n\nCongratulations!!! You have successfully completed the game!!!\n");
    return 0;
}

void moveDisks(int numDisks, char source, char destination, char auxiliary) {
    if (numDisks == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    moveDisks(numDisks-1, source, auxiliary, destination);
    printf("Move disk %d from rod %c to rod %c\n", numDisks, source, destination);
    moveDisks(numDisks-1, auxiliary, destination, source);
}