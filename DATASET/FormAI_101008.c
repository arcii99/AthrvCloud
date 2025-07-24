//FormAI DATASET v1.0 Category: Data validation ; Style: complex
#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    printf("Enter a positive integer: ");
    scanf("%d",&num);
    if(num < 0){
        printf("Invalid input. Please enter a positive integer.\n");
        exit(EXIT_FAILURE);
    }
    int i,flag=0;
    for(i=2;i<=num/2;++i){
        if(num%i==0){
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("%d is a prime number.\n",num);
    }
    else{
        printf("%d is not a prime number.\n",num);
    }
    return 0;
}