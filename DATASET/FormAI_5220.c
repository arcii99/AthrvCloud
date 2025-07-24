//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Cryptic
#include<stdio.h>
#define bool int
#define true 1
#define false 0

bool isPrime(int num) {
    if(num <= 1) 
        return false;
        
    for(int i = 2; i < num; i++)
        if(num % i == 0)
            return false;
    return true;
}

int main() {

    printf("Enter a number: ");
    int limit;
    scanf("%d", &limit);

    if( limit < 2 ){
        printf("Prime numbers start at 2.\n");
        return 0;
    }

    printf("2 ");

    for(int num=3; num<=limit; num+=2){
        if(isPrime(num))
            printf("%d ", num);
    }

    printf("\n");
    return 0;
}