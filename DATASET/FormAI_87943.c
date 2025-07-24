//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: funny
#include <stdio.h>

void move(char start, char end, char temp, int n) 
{
    if (n == 0) 
    {
        return;
    }
    printf("Moving %d disk(s) from Tower %c to Tower %c using Tower %c\n", n, start, end, temp);
    move(start, temp, end, n - 1);
    move(temp, end, start, n - 1);
}

int main() 
{
    int numDisks;
    printf("Welcome to the Tower of Hanoi game! How many disks would you like to play with? ");
    scanf("%d", &numDisks);
    if (numDisks <= 0) 
    {
        printf("Invalid input! Please enter a positive integer.\n");
        return 1;
    }
    printf("Okay, let's start!\n");
    move('A', 'C', 'B', numDisks);
    printf("Congratulations, you won the game! Thanks for playing.\n");
    return 0;
}