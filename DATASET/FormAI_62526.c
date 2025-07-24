//FormAI DATASET v1.0 Category: Educational ; Style: realistic
#include <stdio.h>

int main(){
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if(num % 2 == 0){
        printf("%d is even.\n", num);
    } else{
        printf("%d is odd.\n", num);
    }
    
    printf("The prime factors of %d are: ", num);
    
    for(int i = 2; i <= num; i++){
        while(num % i == 0){
            printf("%d ", i);
            num /= i;
        }
    }
    
    return 0;
}