//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function prototype
void Tower_of_Hanoi(int, char, char, char);

// Main Function
int main()
{
    int n, steps;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    steps = pow(2, n) - 1;
    printf("\nThe minimum number of steps required to solve Tower of Hanoi puzzle with %d disks is %d\n\n", n, steps);
    printf("Following are the steps you need to follow:\n\n");
    Tower_of_Hanoi(n, 'A', 'C', 'B');
    return 0;
}

// Function Body
void Tower_of_Hanoi(int n, char S, char D, char T)
{
    if(n == 1)
    {
        printf("Step %d: Move disk %d from %c pole to %c pole\n", n, n, S, D);
        return;
    }
    Tower_of_Hanoi(n-1, S, T, D);
    printf("Step %d: Move disk %d from %c pole to %c pole\n", n, n, S, D);
    Tower_of_Hanoi(n-1, T, D, S);
}