//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include<stdio.h>

//Function to check prime number
int isPrime(int num){
    int i;
    for(i=2;i<num;i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n, i, cnt = 0;
    printf("How many prime numbers you want to generate: ");
    scanf("%d",&n);
    printf("The first %d prime numbers are:\n",n);
    for(i=2;;i++){
        if(isPrime(i)){
            printf("%d ",i);
            cnt++;
        }
        if(cnt==n){
            break;
        }
    }
    return 0;
}