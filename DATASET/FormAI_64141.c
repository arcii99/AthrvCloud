//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void move(int, int, char, char, char);

int main()
{
    int numDiscs;
    
    printf("Welcome to the Tower of Hanoi!\n");
    printf("Please enter the number of discs: ");
    scanf("%d", &numDiscs);
    
    system("clear"); // clears terminal screen
    
    printf("Ready to start?\n");
    printf("Get ready...\n");
    printf("3...\n");
    printf("2...\n");
    printf("1...\n");
    printf("GOOOOOOOOOOOOOOOOOOOOOOO!\n");
    
    move(numDiscs, 1, 'A', 'B', 'C'); // call recursive function to solve
    
    printf("Congratulations, you did it!\n");
    
    return 0;
}

void move(int numDiscs, int currentDisc, char source, char destination, char spare)
{
    if(numDiscs == 1) // base case
    {
        printf("Move disc %d from %c to %c\n", currentDisc, source, destination);
        return;
    }
    
    move(numDiscs-1, currentDisc+1, source, spare, destination); // move n-1 discs to spare
    printf("Move disc %d from %c to %c\n", currentDisc, source, destination); // move current disc to destination
    move(numDiscs-1, currentDisc+1, spare, destination, source); // move n-1 discs to destination
}