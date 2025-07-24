//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000
#define ITER 1000

int main()
{
    int i,j;
    double sum=0.0;
    double a[N],b[N];

    // generate random numbers between 0 and 1
    srand((unsigned int)time(NULL));
    for(i=0;i<N;i++)
    {
        a[i]=((double)rand()/RAND_MAX);
        b[i]=((double)rand()/RAND_MAX);
    }

    // multiply vectors and time the operation
    clock_t start=clock();
    for(j=0;j<ITER;j++)
    {
        sum=0.0;
        for(i=0;i<N;i++)
        {
            sum+=a[i]*b[i];
        }
    }
    clock_t end=clock();

    // print results
    printf("Multiplication took %lf seconds\n",((double)(end-start))/CLOCKS_PER_SEC);
    printf("Result: %lf\n",sum);

    return 0;
}