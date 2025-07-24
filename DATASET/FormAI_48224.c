//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>

void tower_of_hanoi(int n, char from, char to, char temp) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return;
    }
    tower_of_hanoi(n-1, from, temp, to);
    printf("Move disk %d from rod %c to rod %c\n", n, from, to);
    tower_of_hanoi(n-1, temp, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The steps to solve the Tower of Hanoi problem are:\n");
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}