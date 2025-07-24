//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Linus Torvalds
#include <stdio.h>

void hanoi(char source, char destination, char aux, int n) {
    if (n == 0) {
        return;
    }

    hanoi(source, aux, destination, n-1);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    hanoi(aux, destination, source, n-1);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Sorry, the number of disks cannot be negative.\n");
        return 1;
    }

    printf("\nInstructions:\n");
    hanoi('A', 'C', 'B', n);

    return 0;
}