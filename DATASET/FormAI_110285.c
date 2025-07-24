//FormAI DATASET v1.0 Category: Recursive ; Style: light-weight
#include <stdio.h>
 
//Recursive function to calculate the factorial of a number
int factorial(int num){
    if(num==1)
        return 1;
    else
        return num*factorial(num-1);
}
 
//Recursive function to calculate the fibonacci series of a number
int fibonacci(int num){
    if(num<=1)
        return num;
    else
        return fibonacci(num-1)+fibonacci(num-2);
}
 
int main(){
    int num, choice;
    printf("Enter a number: ");
    scanf("%d",&num);
    printf("Enter 1 to find factorial or 2 to find fibonacci series : ");
    scanf("%d",&choice);
 
    switch(choice){
        case 1: printf("Factorial of %d is %d\n",num,factorial(num));
                break;
        case 2: printf("Fibonacci series of %d is ",num);
                for(int i=0;i<num;i++)
                    printf("%d ",fibonacci(i));
                printf("\n");
                break;
        default: printf("Invalid choice\n");
    }
    return 0;
}