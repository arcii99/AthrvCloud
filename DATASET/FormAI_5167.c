//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: real-life
#include <stdio.h>

void fibonacci(int num)
{
    int prev_num = 0, next_num = 1, temp;
    
    for(int i=0; i<num; i++)
    {
        printf("%d ", prev_num);
        temp = prev_num + next_num;
        prev_num = next_num;
        next_num = temp;
    }
}

int main()
{
    int num;
    printf("Welcome to Fibonacci Sequence Visualizer.\n");
    printf("How many Fibonacci numbers would you like to see? ");
    scanf("%d", &num);
    printf("Here is the Fibonacci sequence up to %d:\n", num);
    fibonacci(num);
    printf("\nThank you for using Fibonacci Sequence Visualizer!\n");
    return 0;
}