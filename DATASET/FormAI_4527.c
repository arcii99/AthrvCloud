//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: statistical
#include <stdio.h>
#include <math.h>

int tower_of_hanoi(int n, char begin, char end, char aux) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", begin, end);
        return 1;
    } else {
        int count = 0;
        count += tower_of_hanoi(n - 1, begin, aux, end);
        printf("Move disk %d from rod %c to rod %c\n", n, begin, end);
        count++;
        count += tower_of_hanoi(n - 1, aux, end, begin);
        return count;
    }
}

int main() {
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    printf("\n");
    int min_moves = pow(2, disks) - 1;
    printf("Minimum number of moves required to solve the problem with %d disks is %d.\n\n", disks, min_moves);
    int count = tower_of_hanoi(disks, 'A', 'C', 'B');
    printf("\nTotal number of moves required to solve the problem with %d disks is %d.\n", disks, count);
    return 0;
}