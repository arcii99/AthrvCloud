//FormAI DATASET v1.0 Category: Benchmarking ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    long int num, i, j;
    double time_spent = 0.0;
    clock_t begin, end;

    printf("Welcome to my benchmark program!\n");
    printf("Please enter an integer value to calculate prime numbers upto: ");
    scanf("%ld", &num);

    printf("Calculating prime numbers upto %ld...\n", num);

    begin = clock();
    for(i=2; i<=num; i++)
    {
        for(j=2; j<i; j++)
        {
            if(i%j==0)
            {
                break;
            }
        }

        if(j==i)
        {
            printf("%ld\n", i);
        }
    }
    end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Total time taken for benchmarking: %f seconds.\n", time_spent);

    return 0;
}