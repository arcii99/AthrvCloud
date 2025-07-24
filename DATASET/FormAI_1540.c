//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int isPrime(int n);

int main(void){
    int i,n,count = 0;
    printf("Welcome to the post-apocalyptic prime number generator program!\n");
    printf("Enter the maximum number to generate prime numbers: ");
    scanf("%d", &n);
    srand(time(NULL));
    for(i = 2; i < n; i++){
        if(isPrime(i)){
            printf("%d ", i);
            count++;
            if(count % 10 == 0) printf("\n");
            //Artificially delay output
            usleep(rand() % (50000) + 50000);
        }
    }
    printf("\n%d prime numbers have been generated up to a maximum of %d\n", count, n);
    return 0;
}

int isPrime(int n){
    if(n <= 1) return 0;
    int i;
    for(i = 2; i < n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}