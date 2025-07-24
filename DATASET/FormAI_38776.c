//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: futuristic
#include <stdio.h>

void moveDisks(int, char, char, char); // function prototype

int main()
{
    int numDisks;
    char start = 'A', aux = 'B', end = 'C';  // column names
    printf("Welcome to the futuristic Tower of Hanoi problem!\n");
    printf("Enter the number of disks you want to play with: ");
    scanf("%d", &numDisks);
    printf("Your mission is to move the disks from column A to column C.\n");
    printf("Here is the initial configuration of the disks:\n");
    for (int i = numDisks; i >= 1; i--) {
        printf("%*s", numDisks-i+1, ""); // print leading spaces
        for (int j = 1; j <= i; j++) 
            printf("%c ", start); // print disk and space
        printf("\n"); // newline
    }
    printf("\n");
    moveDisks(numDisks, start, aux, end); // call the function
    printf("Congratulations, you have completed the futuristic Tower of Hanoi problem!\n");
    return 0;
}

void moveDisks(int n, char s, char a, char e)
{
    static int numMoves = 0; // keep track of number of moves
    if (n == 1) {
        numMoves++;
        printf("Move disk 1 from column %c to column %c\n", s, e);
        return;
    }
    moveDisks(n-1, s, e, a); // move n-1 disks from start to aux
    numMoves++;
    printf("Move disk %d from column %c to column %c\n", n, s, e); // move nth disk from start to end
    moveDisks(n-1, a, s, e); // move n-1 disks from aux to end
}