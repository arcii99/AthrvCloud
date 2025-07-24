//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: sophisticated
#include<stdio.h>
#include<math.h>

int main(){
    
    int choice;
    float num1, num2, result;
    
    //Menu for user
    printf("Welcome to the Scientific Calculator\n");
    printf("Please select an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Power (^)\n");
    printf("6. Square Root (√)\n");
    printf("7. Sine (sin)\n");
    printf("8. Cosine (cos)\n");
    printf("9. Tangent (tan)\n");
    printf("10. Natural Logarithm (ln)\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    
    //For Addition, Subtraction, Multiplication and Division
    if(choice>=1 && choice<=4){
        printf("Enter two numbers: ");
        scanf("%f %f",&num1,&num2);
        
        switch(choice){
            case 1:
                result = num1+num2;
                printf("Result = %.2f",result);
                break;
            case 2:
                result = num1-num2;
                printf("Result = %.2f",result);
                break;
            case 3:
                result = num1*num2;
                printf("Result = %.2f",result);
                break;
            case 4:
                //Denominator cannot be 0
                if(num2==0){
                    printf("Denominator cannot be 0");
                    break;
                }
                result = num1/num2;
                printf("Result = %.2f",result);
                break;
        }
    }
    //For Power
    else if(choice==5){
        printf("Enter the base: ");
        scanf("%f",&num1);
        printf("Enter the exponent: ");
        scanf("%f",&num2);
        
        result = pow(num1,num2);
        printf("Result = %.2f",result);
    }
    //For Square Root
    else if(choice==6){
        printf("Enter a number: ");
        scanf("%f",&num1);
        
        result = sqrt(num1);
        printf("Result = %.2f",result);
    }
    //For Sine, Cosine and Tangent
    else if(choice>=7 && choice<=9){
        printf("Enter the angle in degrees: ");
        scanf("%f",&num1);
        num1 = num1*(3.14159265/180.0); //Conversion to radians
        
        switch(choice){
            case 7:
                result = sin(num1);
                printf("Result = %.2f",result);
                break;
            case 8:
                result = cos(num1);
                printf("Result = %.2f",result);
                break;
            case 9:
                result = tan(num1);
                printf("Result = %.2f",result);
                break;
        }
    }
    //For Natural Logarithm
    else if(choice==10){
        printf("Enter a number: ");
        scanf("%f",&num1);
        
        //Number cannot be negative or 0
        if(num1<=0){
            printf("Number must be positive");
        }
        else{
            result = log(num1);
            printf("Result = %.2f",result);
        }
    }
    //If choice is invalid
    else{
        printf("Invalid choice");
    }

    return 0;
}