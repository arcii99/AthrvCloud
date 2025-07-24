//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Function to check if a number is prime or not
int isPrime(int n) {
    if(n<=1) return 0;
    if(n==2 || n==3) return 1;
    if(n%2==0 || n%3==0) return 0;
    for(int i=5;i*i<=n;i+=6) {
        if(n%i==0 || n%(i+2)==0) {
            return 0;
        }
    }
    return 1;
}

//Function to generate prime numbers
void generatePrimeNumbers(int n) {
    printf("The prime numbers between 1 and %d are:\n",n);
    for(int i=2;i<=n;i++) {
        if(isPrime(i)) 
            printf("%d ",i);
    }
}

//Main function
int main() {
    int n;
    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d",&n);
    generatePrimeNumbers(n);
    return 0;
}