//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: detailed
#include <stdio.h>
void towerOfHanoi(int n, char source, char temp, char dest) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }
    towerOfHanoi(n-1, source, dest, temp);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    towerOfHanoi(n-1, temp, source, dest);
}
int main() {
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}