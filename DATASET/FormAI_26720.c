//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: medieval
#include <stdio.h>
#include <math.h>

int is_prime(int num){
    int i, flag=1;
    for(i=2; i<=sqrt(num); i++){
        if(num%i == 0){
            flag=0;
            break;
        }
    }
    return flag;
}

int main(){
    int n, i, j, count=0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("\n\nThe prime numbers between 1 and %d are:\n\n", n);
    for(i=2; i<=n; i++){
        if(is_prime(i)){
            count++;
            printf("#%d: ", count);
            for(j=0; j<i; j++){
                printf("*");
            }
            printf("\n\n");
        }
    }
    return 0;
}