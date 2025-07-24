//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: random
#include<stdio.h>

int main(){
    int num, i, j;
    printf("Enter a number to generate prime numbers upto: ");
    scanf("%d", &num);
    int primes[num];
    int counter = 0;
    //generating prime numbers
    for(i=2; i<=num; i++){
        int flag = 1;
        for(j=2; j<=i/2; j++){
            if(i%j == 0){
                flag = 0;
                break;
            }
        }
        if(flag){
            primes[counter++] = i;
        }
    }
    
    //printing prime numbers
    printf("Prime Numbers upto %d:\n", num);
    for(i=0; i<counter; i++){
        printf("%d ", primes[i]);
    }
    printf("\n");
    
    return 0;
}