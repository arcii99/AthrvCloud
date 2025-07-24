//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: active
#include <stdio.h>

void move_disk(char from, char to, int disk) {
    printf("Move disk %d from %c to %c\n", disk, from, to);
}

void tower_of_hanoi(int n, char from, char to, char temp) {
    if (n == 1) {
        move_disk(from, to, n);
        return;
    }
    
    tower_of_hanoi(n-1, from, temp, to);
    move_disk(from, to, n);
    tower_of_hanoi(n-1, temp, to, from);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    
    tower_of_hanoi(n, 'A', 'C', 'B');
    
    return 0;
}