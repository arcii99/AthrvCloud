//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: artistic
#include <stdio.h>

void moveDisk(int, char, char, char); // function prototype

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    moveDisk(n, 'A', 'C', 'B'); // function call

    return 0;
}

void moveDisk(int n, char source, char destination, char auxiliary)
{
    if(n == 1) // base case
    {
        printf("\nMove disk 1 from rod %c to rod %c", source, destination);
        return;
    }

    moveDisk(n-1, source, auxiliary, destination); // recursive call
    printf("\nMove disk %d from rod %c to rod %c", n, source, destination);
    moveDisk(n-1, auxiliary, destination, source); // recursive call
}