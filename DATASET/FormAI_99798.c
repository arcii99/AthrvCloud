//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float add(float num1, float num2){
    return num1+num2;
}
float subtract(float num1, float num2){
    return num1-num2;
}
float multiply(float num1, float num2){
    return num1*num2;
}
float divide(float num1, float num2){
    if(num2==0){
        printf("Divide by zero is not possible\n");
        return NAN;
    }
    else
        return num1/num2;
}
float power(float num, float power){
    return pow(num,power);
}
float factorial(float num){
    int fact=1;
    for(int i=1;i<=num;i++){
        fact=fact*i;
    }
    return fact;
}

int main(){
    int choice;
    float num1,num2,result;
    
    printf("Choose an operation:\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Power\n6. Factorial\n");
    scanf("%d",&choice);
    
    switch(choice){
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%f%f",&num1,&num2);
            result = add(num1,num2);
            printf("%f + %f = %f\n",num1,num2,result);
            break;
        
        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%f%f",&num1,&num2);
            result = subtract(num1,num2);
            printf("%f - %f = %f\n",num1,num2,result);
            break;
            
        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%f%f",&num1,&num2);
            result = multiply(num1,num2);
            printf("%f * %f = %f\n",num1,num2,result);
            break;
            
        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%f%f",&num1,&num2);
            result = divide(num1,num2);
            printf("%f / %f = %f\n",num1,num2,result);
            break;
            
        case 5:
            printf("Enter a number and its power: ");
            scanf("%f%f",&num1,&num2);
            result = power(num1,num2);
            printf("%f^%f = %f\n",num1,num2,result);
            break;
            
        case 6:
            printf("Enter a number to calculate its factorial: ");
            scanf("%f",&num1);
            result = factorial(num1);
            printf("%f! = %f\n",num1,result);
            break;
            
        default:
            printf("Invalid choice\n");
    }
    
    return 0;
}