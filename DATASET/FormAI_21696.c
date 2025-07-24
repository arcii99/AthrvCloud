//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n, char start, char dest, char temp);

int main()
{
    int n = 3; // number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // calling towerOfHanoi function
    
    return 0;
}

void towerOfHanoi(int n, char start, char dest, char temp)
{
    if(n==1) // base case
    {
        printf("Move disk 1 from tower %c to tower %c\n", start, dest);
        return;
    }
    
    towerOfHanoi(n-1, start, temp, dest); // move n-1 disks from start to temp
    printf("Move disk %d from tower %c to tower %c\n", n, start, dest); // move nth disk from start to dest
    towerOfHanoi(n-1, temp, dest, start); // move n-1 disks from temp to dest
}