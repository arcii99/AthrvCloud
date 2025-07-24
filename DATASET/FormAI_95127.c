//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: minimalist
#include <stdio.h>

void move(int n, char from, char to, char aux) {
    if(n == 1) {
        printf("Move disk from %c to %c\n", from, to);
        return;
    }
    move(n - 1, from, aux, to);
    printf("Move disk from %c to %c\n", from, to);
    move(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    move(n, 'A', 'C', 'B');
    
    return 0;
}