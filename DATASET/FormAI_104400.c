//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: standalone
#include <stdio.h>

void move(int n, char origin, char buffer, char destination) {
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n", origin, destination);
    } else {
        move(n-1, origin, destination, buffer);
        printf("Move disk %d from %c to %c\n", n, origin, destination);
        move(n-1, buffer, origin, destination);
    }
}

int main() {
    int n;
    char origin = 'A', buffer = 'B', destination = 'C';
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    move(n, origin, buffer, destination);
    return 0;
}