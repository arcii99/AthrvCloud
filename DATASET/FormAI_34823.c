//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int prevNum = 0;
    int curNum = 1;
    int nextNum;
    int maxNum;

    printf("Enter the maximum number of the sequence: ");
    scanf("%d", &maxNum);

    printf("The Fibonacci Sequence up to %d is:\n", maxNum);

    while(curNum <= maxNum)
    {
        nextNum = prevNum + curNum;
        prevNum = curNum;
        curNum = nextNum;

        // print the current number with medieval styling
        printf("%d: ", curNum);
        for(int i = 0; i < curNum; i++)
        {
            if(i % 10 == 0) // line break every 10 characters
            {
                printf("\n  ");
            }
            if(i % 2 == 0) // print "X" on even indices
            {
                printf("X");
            }
            else // print "O" on odd indices
            {
                printf("O");
            }
        }
        printf("\n");
    }

    return 0;
}