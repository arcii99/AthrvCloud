//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 100

void fibonacci(int num)
{
    int prev = 0, curr = 1, next, i;
    system("clear");
    printf("\n\n\n\n\n\n\n");

    for(i=0; i<=num; i++)
    {
        printf("%d%s\n", curr, (i%5==0)?"\t":"");
        next = curr + prev;
        prev = curr;
        curr = next;
    }

    sleep(5);
    system("clear");
    printf("\n\n\n\n\n\n\n");
    printf("%s\n", "WELCOME TO THE SURREALIST FIBONACCI WORLD!");
}

int main()
{
    int num;

    printf("%s", "Enter the number of terms to generate the Fibonacci sequence: ");
    scanf("%d", &num);

    fibonacci(num);
    return 0;
}