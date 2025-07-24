//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
#include<stdio.h>
#include<math.h>

void addition();
void subtraction();
void multiplication();
void division();
void modulus();
void square();
void cube();
void power();
void factorial();
void power_a();
void log_a();
void sine();
void cosine();
void tangent();
void cotangent();
void secant();
void cosecant();

int main(){
    int choice;
    do{
        printf("\n\n\t\tSCIENTIFIC CALCULATOR\n\n");
        printf("1. Addition \n");
        printf("2. Subtraction \n");
        printf("3. Multiplication \n");
        printf("4. Division \n");
        printf("5. Modulus \n");
        printf("6. Square \n");
        printf("7. Cube \n");
        printf("8. Power \n");
        printf("9. Factorial \n");
        printf("10. Power of any number \n");
        printf("11. Logarithm \n");
        printf("12. Sine \n");
        printf("13. Cosine \n");
        printf("14. Tangent \n");
        printf("15. Cotangent \n");
        printf("16. Secant \n");
        printf("17. Cosecant \n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: addition();
                    break;

            case 2: subtraction();
                    break;
                    
            case 3: multiplication();
                    break;
                    
            case 4: division();
                    break;
                    
            case 5: modulus();
                    break;
                    
            case 6: square();
                    break;
                    
            case 7: cube();
                    break;
                    
            case 8: power();
                    break;
                    
            case 9: factorial();
                    break;
                    
            case 10: power_a();
                     break;
                     
            case 11: log_a();
                     break;
                     
            case 12: sine();
                     break;
                     
            case 13: cosine();
                     break;
                     
            case 14: tangent();
                     break;
                     
            case 15: cotangent();
                     break;
                     
            case 16: secant();
                     break;
                     
            case 17: cosecant();
                     break;
                     
            default:printf("Invalid choice");
                    break;
        }
    }while(choice!=0);

    return 0;
}

void addition(){
    float x,y,result;
    printf("\nEnter two numbers: ");
    scanf("%f %f",&x,&y);
    result = x + y;
    printf("The result is: %.2f",result);
}

void subtraction(){
    float x,y,result;
    printf("\nEnter two numbers: ");
    scanf("%f %f",&x,&y);
    result = x - y;
    printf("The result is: %.2f",result);
}

void multiplication(){
    float x,y,result;
    printf("\nEnter two numbers: ");
    scanf("%f %f",&x,&y);
    result = x * y;
    printf("The result is: %.2f",result);
}

void division(){
    float x,y,result;
    printf("\nEnter two numbers: ");
    scanf("%f %f",&x,&y);

    if(y==0){
        printf("Division by zero is not possible");
    }
    else{
        result = x / y;
        printf("The result is: %.2f",result);
    }
}

void modulus(){
    int x,y,result;
    printf("\nEnter two numbers: ");
    scanf("%d %d",&x,&y);

    if(y==0){
        printf("Division by zero is not possible");
    }
    else{
        result = x % y;
        printf("The result is: %d",result);
    }
}

void square(){
    float x,result;
    printf("\nEnter a number: ");
    scanf("%f",&x);
    result = pow(x,2);
    printf("The result is: %.2f",result);
}

void cube(){
    float x,result;
    printf("\nEnter a number: ");
    scanf("%f",&x);
    result = pow(x,3);
    printf("The result is: %.2f",result);
}

void power(){
    float x,y,result;
    printf("\nEnter the base number: ");
    scanf("%f",&x);
    printf("Enter the exponent: ");
    scanf("%f",&y);
    result = pow(x,y);
    printf("The result is: %.2f",result);
}

void factorial(){
    int x,i;
    unsigned long long fact=1;
    printf("\nEnter a number: ");
    scanf("%d",&x);

    if(x<0){
        printf("Factorial of negative number is not possible");
    }
    else{
        for(i=1;i<=x;i++){
            fact = fact * i;
        }
        printf("The factorial of %d is %llu",x,fact);
    }
}

void power_a(){
    float x,y,result;
    printf("\nEnter the number: ");
    scanf("%f",&x);
    printf("Enter the power: ");
    scanf("%f",&y);

    result = pow(x,1/y);

    printf("The answer is: %.2f",result);
}

void log_a(){
    float x,result;
    printf("\nEnter a number: ");
    scanf("%f",&x);

    if(x<=0){
        printf("Logarithm of non-positive number is not possible");
    }
    else{
        result = log10(x);
        printf("The logarithm of %f with base 10 is: %.2f",x,result);
    }
}

void sine(){
    float x,result;
    printf("\nEnter an angle in degrees: ");
    scanf("%f",&x);

    result = sin(x*(3.14159265359/180));

    printf("The sine of %.2f degrees is: %.2f",x,result);
}

void cosine(){
    float x,result;
    printf("\nEnter an angle in degrees: ");
    scanf("%f",&x);

    result = cos(x*(3.14159265359/180));

    printf("The cosine of %.2f degrees is: %.2f",x,result);
}

void tangent(){
    float x,result;
    printf("\nEnter an angle in degrees: ");
    scanf("%f",&x);

    result = tan(x*(3.14159265359/180));

    printf("The tangent of %.2f degrees is: %.2f",x,result);
}

void cotangent(){
    float x,result;
    printf("\nEnter an angle in degrees: ");
    scanf("%f",&x);

    result = 1/tan(x*(3.14159265359/180));

    printf("The cotangent of %.2f degrees is: %.2f",x,result);
}

void secant(){
    float x,result;
    printf("\nEnter an angle in degrees: ");
    scanf("%f",&x);

    result = 1/cos(x*(3.14159265359/180));

    printf("The secant of %.2f degrees is: %.2f",x,result);
}

void cosecant(){
    float x,result;
    printf("\nEnter an angle in degrees: ");
    scanf("%f",&x);

    result = 1/sin(x*(3.14159265359/180));

    printf("The cosecant of %.2f degrees is: %.2f",x,result);
}