//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: rigorous
#include<stdio.h>

void tower_of_hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", A, C);
        return;
    }
    tower_of_hanoi(n - 1, A, C, B);
    printf("Move disk %d from rod %c to rod %c\n", n, A, C);
    tower_of_hanoi(n - 1, B, A, C);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if(n<=0) {
        printf("Invalid input");
        return 0; 
    }
    printf("The steps to move %d disks from rod A to rod C are as follows:\n", n);
    tower_of_hanoi(n, 'A', 'B', 'C');
    return 0;
}