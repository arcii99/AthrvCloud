//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: post-apocalyptic
#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char aux)
{
    if(n==1)
    {
        printf("Move Disk 1 from %c to %c\n", from, to);
    }
    else
    {
        towerOfHanoi(n-1, from, aux, to);
        printf("Move Disk %d from %c to %c\n", n, from, to);
        towerOfHanoi(n-1, aux, to, from);
    }
}

int main()
{
    int numDisks = 3;
    printf("Welcome to the Tower of Hanoi Game in a post-apocalyptic world!\n");
    printf("The world as we know it has been destroyed, and all that remains is rubble and chaos.\n");
    printf("However, there are still survivors trying to make it through, and you are one of them.\n");
    printf("You have been given the task of moving %d disks from one tower to another.\n", numDisks);
    printf("The disks are represented by numbers, with the smallest disk being 1 and the largest being %d.\n", numDisks);
    printf("You can only move one disk at a time, and you cannot place a larger disk on top of a smaller one.\n");
    printf("Your survival depends on completing this task - good luck!\n");

    towerOfHanoi(numDisks, 'A', 'C', 'B');

    printf("Congratulations! You have successfully completed the Tower of Hanoi game in the post-apocalyptic world!\n");
    printf("You have proven that you have the skills to survive in this new world.\n");
    printf("With this new confidence, you can take on any challenge that comes your way.\n");

    return 0;
}