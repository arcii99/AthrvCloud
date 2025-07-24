//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: futuristic
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void tower_of_hanoi(int n, char from_rod[], char to_rod[], char aux_rod[])
{
    if (n == 1)
    {
        printf(" Move disk 1 from rod %s to rod %s\n", from_rod, to_rod);
        sleep(1); // simulation of disk transfer time in sec
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf(" Move disk %d from rod %s to rod %s\n", n, from_rod, to_rod);
    sleep(1);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n = 5; // number of disks
    printf("Welcome to the futuristic Tower of Hanoi problem!\n\n");
    printf("There are %d disks on the source rod and they need to be transferred to the destination rod.\n", n);
    printf("But watch out, the rods are equipped with artificial intelligence and they can move the disks themselves!\n");
    printf("The AI will try to minimize the number of moves made to transfer all the disks.\n");
    printf("Are you ready to start? Let's go!\n\n");
    sleep(2); // waiting for user to read the instructions
    
    tower_of_hanoi(n, "Source", "Destination", "Auxiliary");
    printf("\nAll disks have been successfully transferred!\n");
    sleep(1);
    
    printf("\nThe AI has learned from this experience and is now capable of solving the problem for any number of disks!\n");
    printf("Try changing the value of n in the code and see for yourself.\n");
    return 0;
}