//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    char choice;
    float number, num1, num2, result;
    int ch, n;
      
        printf("\n\t--------------SCIENTIFIC CALCULATOR--------------\n\n");
        printf("Enter 1 for Addition\nEnter 2 for Subtraction\nEnter 3 for Multiplication\nEnter 4 for Division\n");
        printf("Enter 5 for Power Function\nEnter 6 for Square Root Function\nEnter 7 for Logarithmic Function\nEnter 8 for Trigonometric Function\nEnter 9 for Exit\n\n");
        
        printf("Enter Your Choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1: 
                printf("\nEnter First Number: ");
                scanf("%f",&num1);
                printf("Enter Second Number: ");
                scanf("%f",&num2);
                result = num1 + num2;
                printf("\n\nThe Sum of %.2f and %.2f is %.2f",num1,num2,result);
                break;

            case 2: 
                printf("\nEnter First Number: ");
                scanf("%f",&num1);
                printf("Enter Second Number: ");
                scanf("%f",&num2);
                result = num1 - num2;
                printf("\n\nThe Difference of %.2f and %.2f is %.2f",num1,num2,result);
                break;

            case 3: 
                printf("\nEnter First Number: ");
                scanf("%f",&num1);
                printf("Enter Second Number: ");
                scanf("%f",&num2);
                result = num1 * num2;
                printf("\n\nThe Product of %.2f and %.2f is %.2f",num1,num2,result);
                break;

            case 4: 
                printf("\nEnter First Number: ");
                scanf("%f",&num1);
                printf("Enter Second Number: ");
                scanf("%f",&num2);
                result = num1 / num2;
                printf("\n\nThe Division of %.2f and %.2f is %.2f",num1,num2,result);
                break;

            case 5: 
                printf("\nEnter a Number: ");
                scanf("%f",&num1);
                printf("Enter the Power: ");
                scanf("%f",&num2);
                result = pow(num1,num2);
                printf("\n\nThe Result of %.2f Raised to the Power of %.2f is %.2f",num1,num2,result);
                break;

            case 6: 
                printf("\nEnter a Number: ");
                scanf("%f",&num1);
                result = sqrt(num1);
                printf("\n\nThe Square Root of %.2f is %.2f",num1,result);
                break;

            case 7: 
                printf("\nEnter a Number: ");
                scanf("%f",&num1);
                result = log(num1);
                printf("\n\nThe Natural Logarithm of %.2f is %.2f",num1,result);
                break;

            case 8: 
                printf("\nEnter 1 for Sine\nEnter 2 for Cosine\nEnter 3 for Tangent\n");
                printf("Enter Your Choice: ");
                scanf("%d",&n);

                switch(n){
                    case 1:
                        printf("\nEnter a Number in Degrees: ");
                        scanf("%f",&num1);
                        result = sin(num1*(M_PI/180));
                        printf("\n\nThe Sine of %.2f Degree is %.2f",num1,result);
                        break;

                    case 2:
                        printf("\nEnter a Number in Degrees: ");
                        scanf("%f",&num1);
                        result = cos(num1*(M_PI/180));
                        printf("\n\nThe Cosine of %.2f Degree is %.2f",num1,result);
                        break;

                    case 3:
                        printf("\nEnter a Number in Degrees: ");
                        scanf("%f",&num1);
                        result = tan(num1*(M_PI/180));
                        printf("\n\nThe Tangent of %.2f Degree is %.2f",num1,result);
                        break;

                    default:
                        printf("\n\nInvalid Input!");
                        break;
                }
                break;

            case 9:
                printf("\n\nGoodbye!");
                exit(0);
                break;

            default: 
                printf("\n\nInvalid Input!");
                break;
        }

        printf("\n\nDo You Want to Continue? (y/n): ");
        scanf(" %c",&choice);

        if(choice=='y' || choice=='Y'){
            printf("\n");
            main();
        }
        else{
            printf("\n\nGoodbye!");
            exit(0);
        }
      
    return 0;
}