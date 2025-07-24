//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include <stdio.h>

/* A surrealistic approach to solving the Tower of Hanoi problem */

void move(int n, char from_rod, char to_rod, char aux_rod) {
    if(n == 1) {
        printf("Moving the one and only disk from %c to %c\n", from_rod, to_rod);
        return;
    }
    if(n == 0) {
        printf("There is nothing to move!\n");
        return;
    }
    if(n < 0) {
        printf("You can't move negative number of disks, that's just absurd!\n");
        return;
    }
    move(n-1, from_rod, aux_rod, to_rod);
    printf("Moving disk %d from %c to %c\n", n, from_rod, to_rod);
    if(n % 2 == 0) {
        printf("Performing a surrealistic twist!\n");
        printf("Problem just got easier, mission accomplished!\n");
    }
    move(n-1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Welcome to the surrealistic Tower of Hanoi solver!\n");
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\n");
    move(n, 'A', 'B', 'C');
    printf("Surrealism at its finest!\n");
    return 0;
}