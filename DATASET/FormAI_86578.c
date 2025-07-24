//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

//Function to move disk from source to destination
void moveDisk(char source, char dest)
{
    printf("Move disk from %c to %c\n",source,dest);
}

//Function to solve Tower of Hanoi problem
void towerOfHanoi(int num, char source, char aux, char dest)
{
    if(num == 1)
    {
        moveDisk(source, dest);
        return;
    }
    towerOfHanoi(num-1, source, dest, aux);
    moveDisk(source, dest);
    towerOfHanoi(num-1, aux, source, dest);
}

int main()
{
    int num = 3; //Number of disks
    printf("The steps to be taken in order to solve the Tower of Hanoi problem with %d disks are:\n",num);
    towerOfHanoi(num, 'A', 'B', 'C'); //Calling the function
    return 0;
}