//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include<stdio.h>
#include<time.h>

int main()
{
    int i;
    double time_spent;
    clock_t start, end;

    start = clock();

    //Your Internet Speed Testing Code Goes Here

    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time elapsed: %f seconds", time_spent);

    return 0;
}