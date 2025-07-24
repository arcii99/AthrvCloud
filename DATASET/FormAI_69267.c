//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char start, char end, char temp) {
    if (n == 0) { //base case
        return;
    }
    
    hanoi(n-1, start, temp, end);
    printf("Move disk %d from rod %c to rod %c\n", n, start, end);
    hanoi(n-1, temp, end, start);
}

int main() {
    printf("Welcome to the Tower of Hanoi puzzle!\n");
    printf("In this game, there are three rods labeled A, B, and C.\n");
    printf("There are n disks numbered from 1 to n on rod A with decreasing size.\n");
    printf("The goal is to move all the disks from rod A to rod C without placing a disk on top of a smaller disk.\n");
    printf("Enter the number of disks you want to play with: ");
    
    int n;
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid input! Please enter a positive number.\n");
        return 1;
    }
    
    hanoi(n, 'A', 'C', 'B');
    
    printf("Congratulations! You have solved the puzzle!\n");
    return 0;
}