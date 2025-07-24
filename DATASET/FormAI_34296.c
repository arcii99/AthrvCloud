//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: brave
#include <stdio.h>

void moveDisk(int, char, char, char); //function prototype

int main()
{
    int numOfDisks = 3; //set number of disks as 3
    printf("Welcome to the Tower of Hanoi game!\n");
    printf("You have %d disks. The objective of the game is to move all the disks from tower A to tower C using tower B.\n", numOfDisks);
    moveDisk(numOfDisks, 'A', 'B', 'C'); //calling the function
    printf("\nCongratulations! You have completed the game.\n");
    return 0;
}

void moveDisk(int num, char from, char aux, char to)
{
    if(num==1) //if only one disk is left in the original tower
    {
        printf("Move disk 1 from tower %c to tower %c.\n", from, to);
        return;
    }
    moveDisk(num-1, from, to, aux); //recursive call to move the top n-1 disks to the auxiliary tower
    printf("Move disk %d from tower %c to tower %c.\n", num, from, to); //move the n-th disk from original tower to the destination tower
    moveDisk(num-1, aux, from, to); //recursive call to move the n-1 disks from auxiliary tower to destination tower 
}