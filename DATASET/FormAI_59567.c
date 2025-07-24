//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>

int is_prime(int num){
    int i;
    for(i =2; i<num; i++){
        if(num % i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int num, i, range;
    
    printf("Enter the range of prime numbers to generate: ");
    scanf("%d", &range);
    
    for(num = 2; num <= range; num++){
        if(is_prime(num)==1){
            printf("%d is a prime number.\n", num);
        }
    }
    return 0;
}