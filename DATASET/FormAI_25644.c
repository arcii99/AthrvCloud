//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: secure
#include <stdio.h>

int is_prime(int num){
    if(num < 2 ) return 0;
    if(num == 2 || num == 3) return 1;
    if(num % 2 == 0 || num % 3 == 0) return 0;

    int i; 
    for(i = 5; i*i <= num; i+=6){
        if(num % i == 0 || num % (i+2) == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int num, i, cnt = 0;

    printf("Enter a number to generate prime numbers up to: ");
    scanf("%d", &num);

    printf("Prime numbers up to %d:\n", num);

    for(i = 2; i <= num; i++){
        if(is_prime(i)){
            printf("%d ", i);
            cnt++;
        }
    }
    printf("\nTotal prime numbers generated: %d\n", cnt);
    return 0;
}