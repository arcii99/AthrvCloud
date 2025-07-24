//FormAI DATASET v1.0 Category: Scientific ; Style: creative
#include<stdio.h>

//function to calculate factorial of a number
int factorial(int num){
    
    if(num==0) return 1;
    else return num*factorial(num-1);
}

int main(){
    int num;
    
    printf("Enter a positive integer: ");
    scanf("%d",&num);
    
    //check if the input is positive integer
    if(num<0){
        printf("Invalid input! Please enter a positive integer.\n");
    }
    else{
        int fact = factorial(num);
        printf("The factorial of %d is %d.\n",num,fact);
        
        //check if the factorial is greater than 100000
        if(fact>100000){
            printf("Wow! %d is a big number.\n",fact);
        }
        else if(fact<=100000&&fact>10000){
            printf("%d is a large number,\n",fact);
        }
        else{
            printf("%d is not too big.\n",fact);
        }
        
        //display the factors of the number
        printf("The factors of %d are:",num);
        for(int i=1;i<=num;i++){
            if(num%i==0){
                printf(" %d",i);
            }
        }
    }
    return 0;
}