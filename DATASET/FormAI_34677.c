//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: ephemeral
#include <stdio.h>

int main() {

    int num, prime, i, j, flag;

    printf("Enter a positive integer: ");
    scanf("%d",&num);

    printf("The prime numbers between 1 and %d are:\n",num);

    for(i=2; i<=num; i++)
    {
        flag = 0;
        for(j=2; j<=i/2; j++)
        {
            if(i%j==0)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0 && i!=1)
            printf("%d ", i);
    }
    
    printf("\n");

    return 0;
}