//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: calm
#include<stdio.h>

int main(){
    int n;
    printf("Enter the range: ");
    scanf("%d", &n);
    int prime_numbers[n+1];
    for(int i=2; i<=n; i++){
        prime_numbers[i] = 1; //assign all indexes in array to 1
    }
    for(int i=2; i*i<=n; i++){
        if(prime_numbers[i] == 1){
            for(int j=i*i; j<=n; j+=i){
                prime_numbers[j] = 0; //mark multiples of prime as 0 (not prime)
            }
        }
    }
    printf("Prime numbers within given range:\n");
    for(int i=2; i<=n; i++){
        if(prime_numbers[i] == 1){
            printf("%d ", i);
        }
    }
    return 0;
}