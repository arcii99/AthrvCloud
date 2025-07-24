//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: intelligent
#include <stdio.h>

void move(int n, char source, char dest, char temp) {
    if(n == 1) {
        printf("\nMove disk 1 from %c to %c", source, dest);
        return;
    }
    move(n - 1, source, temp, dest);
    printf("\nMove disk %d from %c to %c", n, source, dest);
    move(n - 1, temp, dest, source);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("Tower of Hanoi solution for %d disks:\n", n);
    move(n, 'A', 'C', 'B');
    return 0;
}