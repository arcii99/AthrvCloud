//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: innovative
#include <stdio.h>
#define MAX 1000   // maximum limit of prime number list

int main()
{
    int i, j, flag, n = 2;
    int primes[MAX];   // array to store prime numbers

    primes[0] = 2;   // 2 is the first prime number
    printf("%d\n",primes[0]);

    for(i = 3; i <= MAX; i++)
    {
        flag = 1;
        for(j = 2; j <= i/2; j++)
        {
            if(i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            primes[n] = i;
            n++;
            printf("%d\n",i);
        }
    }
    return 0;
}