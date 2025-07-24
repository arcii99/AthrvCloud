//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include<stdio.h>

/* This is a program to solve the classic Tower of Hanoi problem using recursion. */
/* This program takes the number of disks as input from the user and prints the steps to solve the problem. */

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
    if (n == 1) 
    { 
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod); 
        return; 
    } 
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod); 
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod); 
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod); 
} 

int main() 
{ 
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\n");

    printf("Solving Tower of Hanoi problem with %d disks...\n\n", n); 

    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\nSolved!\n");
    return 0; 
}