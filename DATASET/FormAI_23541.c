//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void addition(float a, float b){ //Function for addition operation
    printf("> %.2f + %.2f = %.2f\n",a,b,a+b);
}
void substraction(float a, float b){ //Function for substraction operation
    printf("> %.2f - %.2f = %.2f\n",a,b,a-b);
}
void multiplication(float a, float b){ //Function for multiplication operation
    printf("> %.2f x %.2f = %.2f\n",a,b,a*b);
}
void division(float a, float b){ //Function for division operation
    if(b==0){
        printf("> Error: cannot divide by 0\n");
    }else{
        printf("> %.2f / %.2f = %.2f\n",a,b,a/b);
    }
}
void power(float base, float exponent){ //Function for power operation
    printf("> %.2f ^ %.2f = %.2f\n",base,exponent,pow(base,exponent));
}
void modulus(float a, float b){ //Function for modulus operation
    if(b==0){
        printf("> Error: cannot divide by 0\n");
    }else{
        printf("> %.2f mod %.2f = %.2f\n",a,b,a-floor(a/b)*b);
    }
}

int main() {
    float a,b;
    char operator;
    printf("█████████████████████████████████\n");
    printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n");
    printf("█░█░░░░░░░░░░█░░░░░░░░░░░█░░░░░░░█\n");
    printf("█░░░░░░░░░░░░█░░░░░░░░░░░█░░░░░░░█\n");
    printf("█░░░░░░░░░░░░█░░░░░░░░░░░█░░░░░░░█\n");
    printf("█░█░░░░░░░░░░█░░░░░░░░░░░█░░░░░░░█\n");
    printf("█░░░░░░░░░░░░█░░░░░░░░░░░█░░░░░░░█\n");
    printf("█░░░░░░░░░░░░█░░░░░░░░░░░█░░░░░░░█\n");
    printf("█░░░░░░░░░░░░█░░░░░░░░░░░█░░░░░░░█\n");
    printf("█░█░░░░░░░░░░█░░░░░░░░░░░█░░░░░░░█\n");
    printf("█░░░░░░░░░░░░█░░░░░░░░░░░█░░░░░░░█\n");
    printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n");
    printf("█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n");
    printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n");
    printf("█████████████████████████████████\n");
    printf("\n");

    printf("Enter the operation you want to perform (+,-,*,/,^,%): ");
    scanf("%c",&operator);

    if(operator=='+' || operator=='-' || operator=='*' || operator=='/' || operator=='^' || operator=='%'){ //Checking for valid operator
        printf("Enter 1st Number: ");
        scanf("%f",&a);
        printf("Enter 2nd Number: ");
        scanf("%f",&b);

        switch(operator){
            case '+':
                addition(a,b);
                break;
            case '-':
                substraction(a,b);
                break; 
            case '*':
                multiplication(a,b);
                break; 
            case '/':
                division(a,b);
                break;
            case '^':
                power(a,b);
                break; 
            case '%':
                modulus(a,b);
                break;
        }
    }
    else{
        printf("Error: Invalid Operator!\n");
    }
    return 0;
}