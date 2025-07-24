//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: thoughtful
#include <stdio.h>

int isPrime(int num){
    if(num == 2 || num == 3)
        return 1;
    if(num == 1 || num % 2 == 0)
        return 0;
    for(int i = 3; i * i <= num; i += 2){
        if(num % i == 0)
            return 0;
    }
    return 1;
}

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Prime numbers less than or equal to %d are:\n", num);
    for(int i = 1; i <= num; i++){
        if(isPrime(i))
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}