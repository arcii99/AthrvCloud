//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>

void fibonacci(int num)
{
    int i, t1 = 0, t2 = 1, nextTerm;
    
    printf("Fibonacci Sequence:\n");
 
    for (i = 1; i <= num; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}

void visualize(int num)
{
    int i, j, t1 = 0, t2 = 1, nextTerm;
    char symbol[] = {'*', '.', 'x', '+', '-', 'o', '0'};
    int symbolCount = sizeof(symbol) / sizeof(symbol[0]);

    printf("\nFibonacci Visualization:\n");

    for (i = 1; i <= num; ++i) {
        for (j = 0; j < t1; ++j) {
            printf("%c ", symbol[j % symbolCount]);
        }
        
        printf("\n");      
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}

int main()
{
    int num;
    
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    
    fibonacci(num);
    visualize(num);

    return 0;
}