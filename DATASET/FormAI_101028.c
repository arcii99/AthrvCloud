//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: cheerful
#include <stdio.h>

// Define a function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }
    
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main()
{
    int n;
    printf("Welcome to the Tower of Hanoi game!\n\n");
    printf("How many disks do you want to play with? ");
    scanf("%d", &n);
    printf("\n");
    
    // Call the Tower of Hanoi function and start playing the game
    towerOfHanoi(n, 'A', 'C', 'B');
    
    printf("\nCongratulations! You have completed the Tower of Hanoi game.\n");
    return 0;
}