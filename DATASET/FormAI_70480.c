//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include<stdio.h>

int main()
{
    printf("Welcome to the Mind-Bending Tower of Hanoi problem example program!\n");
    printf("This program will show you how to solve the Tower of Hanoi problem using recursion!\n\n");
    printf("Enter the number of disks in the Tower of Hanoi (it must be greater than or equal to 1): ");
    int n;
    scanf("%d", &n);
    while(n < 1)
    {
        printf("The number of disks must be greater than or equal to 1. Please enter again: ");
        scanf("%d", &n);
    }
    printf("\nHere's how to solve the Tower of Hanoi problem with %d disks:\n\n", n);
    solveTowerOfHanoi(n, 'A', 'B', 'C');
    printf("\nWell Done! Thank you for using our mind-bending Tower of Hanoi problem example program!\n");
    return 0;
}

void solveTowerOfHanoi(int n, char fromRod, char toRod, char auxRod)
{
  if (n == 1) 
  {
    printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
    return;
  }
  printf("Please Think Carefully, focus on the task and follow the solution step by step to move %d disks from rod %c to rod %c\n\n", n, fromRod, toRod);
  solveTowerOfHanoi(n-1, fromRod, auxRod, toRod);
  printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);
  solveTowerOfHanoi(n-1, auxRod, toRod, fromRod);
}