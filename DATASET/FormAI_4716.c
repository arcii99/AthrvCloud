//FormAI DATASET v1.0 Category: Game ; Style: protected
#include <stdio.h>

// Function to check if a number is prime
int is_prime(int num){
    int i;
    
    // Checking for factors from 2 to halfway point of num
    for(i = 2; i <= num/2; i++){
        if(num % i == 0){
            return 0; // Not prime
        }
    }
    
    return 1; // Prime
}

int main(){
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    // Checking if number is prime
    if(is_prime(num)){
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }
    
    return 0;
}