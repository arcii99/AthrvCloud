//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: visionary
#include <stdio.h>

void hanoi(int n, char start_rod, char end_rod, char mid_rod);

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    hanoi(n, 'A', 'B', 'C');
    return 0;
}

void hanoi(int n, char start_rod, char end_rod, char mid_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", start_rod, end_rod);
        return;
    }
    
    hanoi(n-1, start_rod, mid_rod, end_rod);
    
    printf("Move disk %d from rod %c to rod %c\n", n, start_rod, end_rod);
    
    hanoi(n-1, mid_rod, end_rod, start_rod);
}