//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n){
    if(n == 2 || n == 3)
        return true;
    if(n == 1 || n % 2 == 0)
        return false;
    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0)
            return false;
    }
    return true;
}

int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("The first %d prime numbers are: ", n);

    int num = 2, count = 0;
    while(count < n){
        if(isPrime(num)){
            printf("%d ", num);
            count++;
        }
        num++;
    }

    return 0;
}