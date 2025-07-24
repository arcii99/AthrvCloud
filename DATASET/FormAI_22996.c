//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>

// Function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char source, char destination, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    towerOfHanoi(n-1, source, aux, destination);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    towerOfHanoi(n-1, aux, destination, source);
}
 
int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}