//FormAI DATASET v1.0 Category: Recursive ; Style: modular
#include<stdio.h>

//Factorial function
int factorial(int num){
    if(num==0){
        return 1;
    }
    else{
        return num * factorial(num-1);
    }
}

//Fibonacci function
int fibonacci(int num){
    if(num == 0 || num == 1){
        return num;
    }
    else{
        return fibonacci(num-1) + fibonacci(num-2);
    }
}

//Main function
int main(){
    int choice;
    printf("1. Calculate Factorial\n2. Calculate Fibonacci Series\nEnter your choice:");
    scanf("%d", &choice);

    if(choice == 1){
        int num;
        printf("Enter a number:");
        scanf("%d", &num);
        int result = factorial(num);
        printf("Factorial of %d is %d\n", num, result);
    }
    else if(choice == 2){
        int num;
        printf("Enter the number of terms in Fibonacci Series:");
        scanf("%d", &num);
        for(int i=0; i<num; i++){
            printf("%d ", fibonacci(i));
        }
    }
    else{
        printf("Invalid Choice\n");
    }
    return 0;
}