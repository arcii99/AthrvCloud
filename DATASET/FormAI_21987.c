//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>

int num_discs = 0;

void hanoi(int num_discs, char start, char end, char aux)
{
    if(num_discs == 1)
    {
        printf("Move Disc 1 from %c to %c\n", start, end);
        return;
    }
    
    hanoi(num_discs-1, start, aux, end);
    printf("Move Disc %d from %c to %c\n", num_discs, start, end);
    hanoi(num_discs-1, aux, end, start);
}

int main()
{
    printf("Welcome to the Tower of Hanoi program!\n");
    printf("Please enter the number of discs you would like to play with: ");
    scanf("%d", &num_discs);
    
    if(num_discs < 1)
    {
        printf("Error: Number of discs must be greater than 0.\n");
        exit(1);
    }
    
    printf("\n");
    hanoi(num_discs, 'A', 'C', 'B');
    printf("\nCongratulations! You have successfully solved the puzzle.\n");
    return 0;
}