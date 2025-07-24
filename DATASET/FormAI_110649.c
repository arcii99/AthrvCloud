//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>

void move(char frompeg, char topeg)
{
    printf("Move disk from %c to %c\n", frompeg, topeg);
}

void towers(int num, char frompeg, char topeg, char auxpeg)
{
    if (num == 1)
    {
        move(frompeg, topeg);
        return;
     }
     towers(num - 1, frompeg, auxpeg, topeg);
     move(frompeg, topeg);
     towers(num - 1, auxpeg, topeg, frompeg);
}

int main()
{
    int num;
    printf("Enter the number of disks: ");
    scanf("%d", &num);
    printf("The moves are:\n");
    towers(num, 'A', 'C', 'B');
    return 0;
}