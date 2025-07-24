//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Function prototype
void towerOfHanoi(int n, char source, char target, char auxiliary);

int main()
{
    int n;
    
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    if(n > 0){
        towerOfHanoi(n, 'A', 'C', 'B');
    } else {
        printf("Invalid input. The number of disks must be greater than 0.\n");
    }
    
    return 0;
}

void towerOfHanoi(int n, char source, char target, char auxiliary)
{
    if(n == 1){
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    
    towerOfHanoi(n-1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    towerOfHanoi(n-1, auxiliary, target, source);
}