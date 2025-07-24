//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: careful
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num)   // function to check if number is prime
{
    if(num < 2){
        return false;
    }
    else{
        for(int i = 2; i <= num/2; i++){
            if(num%i == 0){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, count = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    
    for(int i = 2; count < n; i++){  // loop to generate n prime numbers
        if(is_prime(i)){
            printf("%d ", i);
            count++;
        }
    }
    return 0;
}