//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h> //sleep() function

void moveDisk(int diskNum, char fromPeg, char toPeg){
    printf("Move disk %d from peg %c to peg %c\n", diskNum, fromPeg, toPeg);
    sleep(1); //Adding a delay for dramatic effect
}

void towerOfHanoi(int diskNum, char fromPeg, char toPeg, char auxPeg){
    if (diskNum == 1){
        moveDisk(diskNum, fromPeg, toPeg);
        return;
    }
    towerOfHanoi(diskNum - 1, fromPeg, auxPeg, toPeg);
    moveDisk(diskNum, fromPeg, toPeg);
    towerOfHanoi(diskNum - 1, auxPeg, toPeg, fromPeg);
}

int main(){
    int diskNum;
    char startPeg = 'A', endPeg = 'B', auxPeg = 'C';
    printf("Welcome to my Tower of Hanoi game! \n");
    printf("The rules are simple, you have to move all the disks from peg A to peg B using peg C as the helper. \n");
    printf("But beware, the disks are heavy and the pegs can only hold so much weight! \n");

    printf("Enter the number of disks you want to play with: ");
    scanf("%d", &diskNum);
    system("clear"); //Clearing the screen for a fresh start

    printf("Alright, let's begin! \n");
    sleep(2); //Adding a delay for dramatic effect

    towerOfHanoi(diskNum, startPeg, endPeg, auxPeg);

    printf("Congratulations! You have won the game! \n");
    printf("Thanks for playing with me. See you soon! \n");
    return 0;
}