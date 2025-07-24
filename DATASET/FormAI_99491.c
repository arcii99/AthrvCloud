//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: protected
#include <stdio.h>

void move(int n, char source, char auxiliary, char target);

int main()
{
    int disks;
    
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    
    printf("\nInstructions to solve the Tower of Hanoi Problem with %d disks:\n", disks);
    move(disks, 'A', 'B', 'C');
    
    return 0;
}

void move(int n, char source, char auxiliary, char target)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from rod %c to rod %c", source, target);
        return;
    }
    
    move(n-1, source, target, auxiliary);
    printf("\nMove disk %d from rod %c to rod %c", n, source, target);
    move(n-1, auxiliary, source, target);
}