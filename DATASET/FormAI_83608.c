//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Claude Shannon
#include<stdio.h>

int isPrime(int num){
    int i;
    if(num < 2) return 0;

    for(i = 2; i <= num/2; i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n, count = 0, curr_num = 2, i;
    printf("Enter the value of n to generate first n prime numbers: ");
    scanf("%d", &n);

    printf("The first %d prime numbers are:\n", n);
    while(count < n){
        if(isPrime(curr_num)){
            count++;
            printf("%d ", curr_num);
        }
        curr_num++; 
    }
    return 0;
}