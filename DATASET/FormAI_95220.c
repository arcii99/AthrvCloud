//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>
#include <stdbool.h>

bool prime_checker(int num){
    if(num<2) return false;
    if(num==2) return true;
    if(num%2==0) return false;
    for(int i=3;i*i<=num;i+=2){
        if(num%i==0) return false;
    }
    return true;
}

int main(){
    int n, count=0;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    printf("Here are the first %d prime numbers:\n", n);
    for(int i=2;count<n;i++){
        if(prime_checker(i)==true){
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
    return 0;
}