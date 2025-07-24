//FormAI DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>

// Function to check if a number is prime or not
int isPrime(int num){
    int i;
    for(i=2; i<num; i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    printf("*** Prime Number Detector ***\n");
    
    int num, i=1;
    while(i){
        printf("\nEnter a number (Enter 0 to exit): ");
        scanf("%d", &num);
        
        if(num == 0){
            i = 0;
        }else if(isPrime(num)){
            printf("%d is a prime number!\n", num);
        }else{
            printf("%d is not a prime number!\n", num);
        }
    }
    
    printf("\nThank you for using this program.\n");
    
    return 0;
}