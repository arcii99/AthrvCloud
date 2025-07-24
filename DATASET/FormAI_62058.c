//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: excited
#include <stdio.h>

int moves = 0;

void tower_of_hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        moves++;
        printf("\nMove disk 1 from rod %c to rod %c", A, C);
        return;
    }
    
    tower_of_hanoi(n-1, A, C, B);
    moves++;
    printf("\nMove disk %d from rod %c to rod %c", n, A, C);
    tower_of_hanoi(n-1, B, A, C);
}

int main()
{
    int n;
    
    printf("Welcome to Tower of Hanoi!\n");
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    tower_of_hanoi(n, 'A', 'B', 'C');
    
    printf("\n\nHurray!! You have completed the Tower of Hanoi puzzle in %d moves!", moves);
    printf("\nThank you for playing :)");
    
    return 0;
}