//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: unmistakable
#include<stdio.h>

int main()
{
    int n, i, flag;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Prime numbers between 1 and %d are: ", n);

    for(i=2; i<=n; i++)
    {
        flag = 0;

        for(int j=2; j<=i/2; j++)
        {
            if(i%j == 0)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0 && i != 1)
            printf("%d ", i);
    }

    return 0;
}