//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: imaginative
#include <stdio.h>

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if(n == 1) {
        printf("\nMove disk 1 from %c to %c", source, destination);
        return;
    }
    towerOfHanoi(n-1, source, auxiliary, destination);
    printf("\nMove disk %d from %c to %c", n, source, destination);
    towerOfHanoi(n-1, auxiliary, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}