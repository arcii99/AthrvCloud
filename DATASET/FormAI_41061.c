//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>

int isPrime(int num) { //function to check if number is prime or not
    int flag = 1; //set flag to true
    for(int i=2;i<num/2;i++) { 
        if(num%i == 0) { //if number is divisible by any other number except 1 and num, set flag to false
            flag = 0;
            break;
        }   
    }
    return flag;
}

int main() {
    int n, count = 0; //count will keep track of number of prime numbers found
    printf("Enter a positive integer n: ");
    scanf("%d", &n);
    printf("The prime numbers between 1 and %d are:\n", n);
    for(int i=2;i<=n;i++) { //loop from 2 to n
        if(isPrime(i)) { //if number is prime, print it and increment count
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal number of prime numbers found: %d", count);
    return 0;
}