//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n, char source, char destination, char intermediate)
{
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, intermediate, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, intermediate, destination, source);
}

int main()
{
    int n;
    printf("Welcome to the Tower of Hanoi game!\n");
    printf("How many disks would you like to play with? (minimum 3): ");
    scanf("%d", &n);
    if (n < 3) {
        printf("Invalid input! Please enter a number greater than or equal to 3.\n");
        return 1;
    }
    printf("\nYou have chosen to play with %d disks.\n", n);
    printf("Here are the moves you need to make to win the game:\n\n");
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\nCongratulations! You have successfully completed the Tower of Hanoi game with %d disks!\n", n);
    return 0;
}