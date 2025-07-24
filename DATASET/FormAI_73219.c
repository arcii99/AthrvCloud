//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Linus Torvalds
#include <stdio.h>
void hanoi(int n, char x, char y, char z) {
    if (n == 1) {
        printf("\nMove disk 1 from rod %c to rod %c", x, y);
        return;
    }
    hanoi(n-1, x, z, y);
    printf("\nMove disk %d from rod %c to rod %c", n, x, y);
    hanoi(n-1, z, y, x);
}
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}