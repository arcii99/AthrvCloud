//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>

void towersofHanoi(int discs, char frompeg, char topeg, char auxpeg)
{
    if (discs == 1)
    {
        printf("\nMove disk 1 from peg %c to peg %c", frompeg, topeg);
        return;
    }
    towersofHanoi(discs - 1, frompeg, auxpeg, topeg);
    printf("\nMove disk %d from peg %c to peg %c", discs, frompeg, topeg);
    towersofHanoi(discs - 1, auxpeg, topeg, frompeg);
}

int main()
{
    int num;
    printf("Enter the number of discs: ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are:\n\n");
    towersofHanoi(num, 'A', 'C', 'B');
    printf("\n");
    return 0;
}