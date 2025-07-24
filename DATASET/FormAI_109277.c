//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

void move_tower(int n, char from_rod, char to_rod, char aux_rod, int count) 
{
    //exit recursion if the disk count is zero
    if (n == 0) 
        return;
    
    //recursive function call to move the disk from the first tower to the second tower
    move_tower(n-1, from_rod, aux_rod, to_rod, ++count);
    
    //print message to indicate the movement of the disks
    printf("\nStep %d: Move disk %d from %c to %c", count, n, from_rod, to_rod);
    
    //recursive function call to move the disk from the auxiliary tower to the second tower
    move_tower(n-1, aux_rod, to_rod, from_rod, ++count);
}

int main() 
{
    printf("Welcome to the paranoid Tower of Hanoi problem program!\n");
    printf("Please enter the number of disks in the first rod: ");
    
    int n;
    scanf("%d", &n);
    int count = 0; // variable to keep track of the number of movements
    
    //check if the number of disks is greater than 0
    if(n > 0)
    {
        //start the recursion to move the disks from the first rod to the second rod using the third rod as an intermediary
        move_tower(n, 'A', 'C', 'B', count);
        
        printf("\nCongratulations! All the disks have been moved from the first rod to the second rod using the third rod as an intermediary.\n");
    }
    else
    {
        printf("\nInvalid input. The number of disks should be greater than 0. Please re-run the program.\n");
    }
    
    return 0;
}