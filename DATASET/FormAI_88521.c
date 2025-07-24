//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

//Function prototype
void towerOfHanoi(int, char, char, char);

int main()
{
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if(num_disks<1)
    {
        printf("Number of disks should be at least 1 \n");
        exit(0);
    }
    printf("Here are the steps to solve the Tower of Hanoi problem with %d disks.\n", num_disks);

    towerOfHanoi(num_disks, 'A', 'B', 'C');   //Function call
    return 0;
}

void towerOfHanoi(int num, char from_rod, char to_rod, char aux_rod)
{
    if(num == 1)
    {
        printf("Move disk 1 from rod %c to rod %c \n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(num-1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c \n", num, from_rod, to_rod);
    towerOfHanoi(num-1, aux_rod, to_rod, from_rod);
}