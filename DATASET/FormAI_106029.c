//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: romantic
#include<stdio.h>
#include<math.h>

int is_prime(int num){
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int limit;
    printf("Enter the limit up to which prime numbers are to be found: ");
    scanf("%d", &limit);
    printf("Prime Numbers up to %d:\n", limit);

    for(int i = 2; i <= limit; i++){
        if(is_prime(i)){
            printf("%d ", i);
        }
    }

    return 0;
}