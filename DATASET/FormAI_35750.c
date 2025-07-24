//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int is_prime(int num){
    if(num == 2){
        return 1;
    }

    if(num < 2 || num % 2 == 0){
        return 0;
    }

    for(int i=3; i*i<=num; i+=2){
        if(num%i == 0){
            return 0;
        }
    }

    return 1;
}

int main(){
    srand(time(0));
    int prime_list[50];
    int count = 0;
    int num = rand()%100 + 1;
    printf("Random number generated: %d\n", num);

    while(count < 50){
        if(is_prime(num)){
            prime_list[count] = num;
            count++;
            printf("Prime number found: %d\n", num);
        }
        num++;
    }

    printf("50 prime numbers generated: ");
    for(int i=0; i<50; i++){
        printf("%d ", prime_list[i]);
    }

    printf("\n");

    return 0;
}