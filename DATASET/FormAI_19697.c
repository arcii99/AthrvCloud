//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ada Lovelace
#include<stdio.h>

// Function to move disks between rods
void towerOfHanoi(int n, char from, char to, char aux)
{
    if(n == 1) // if only one disk, move it from 'from' to 'to'
    {
        printf("\n Move disk 1 from rod %c to rod %c", from, to);
        return;
    }

    towerOfHanoi(n-1, from, aux, to); // step one - move n-1 disks from 'from' to 'aux'
    printf("\n Move disk %d from rod %c to rod %c", n, from, to);
    towerOfHanoi(n-1, aux, to, from); // step three - move n-1 disks from 'aux' to 'to'
}

int main()
{
    int n = 4; // number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // function call
    return 0;
}