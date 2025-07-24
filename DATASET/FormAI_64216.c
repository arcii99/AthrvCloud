//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Enter an integer n to find prime numbers between 2 and n: ");
    int n;
    scanf("%d", &n);
    
    bool isPrime[n+1];
    for(int i=0; i<n+1; i++)
        isPrime[i] = true;
    
    for(int p=2; p*p<=n; p++){
        if(isPrime[p] == true){
            for(int i=p*p; i<=n; i+=p)
                isPrime[i] = false;
        }
    }
    
    printf("Prime numbers between 2 and %d are: ", n);
    for(int i=2; i<=n; i++){
        if(isPrime[i] == true)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}