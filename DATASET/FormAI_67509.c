//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include<stdio.h>
#include<math.h>

int main(){

    float num1, num2, result;
    int option;
    char confirm;

    printf("Scientific Calculator\n");
    printf("---------------------\n");

    do{
        printf("\nEnter two numbers: ");
        scanf("%f%f", &num1, &num2);

        printf("\nSelect an operation to perform: \n\n");
        printf("1 - Add\n");
        printf("2 - Subtract\n");
        printf("3 - Multiply\n");
        printf("4 - Divide\n");
        printf("5 - Power\n");
        printf("6 - Square Root\n");
        printf("7 - Sine\n");
        printf("8 - Cosine\n");
        printf("9 - Tangent\n");
        printf("10 - Logarithm\n\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                result = num1 + num2;
                printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("\n%.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("\n%.2f x %.2f = %.2f\n", num1, num2, result);
                break;
            case 4:
                if(num2 == 0){
                    printf("\nError! Division by zero.\n");
                }
                else{
                    result = num1 / num2;
                    printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;
            case 5:
                result = pow(num1, num2);
                printf("\n%.2f raised to the power of %.2f = %.2f\n", num1, num2, result);
                break;
            case 6:
                if(num1 < 0){
                    printf("\nError! Cannot find square root of a negative number.\n");
                }
                else{
                    result = sqrt(num1);
                    printf("\nSquare root of %.2f = %.2f\n", num1, result);
                }
                break;
            case 7:
                result = sin(num1);
                printf("\nSine of %.2f = %.2f\n", num1, result);
                break;
            case 8:
                result = cos(num1);
                printf("\nCosine of %.2f = %.2f\n", num1, result);
                break;
            case 9:
                result = tan(num1);
                printf("\nTangent of %.2f = %.2f\n", num1, result);
                break;
            case 10:
                if(num1 <= 0){
                    printf("\nError! Cannot find logarithm of a negative or zero number.\n");
                }
                else{
                    result = log10(num1);
                    printf("\nLogarithm of %.2f = %.2f\n", num1, result);
                }
                break;
            default:
                printf("\nError! Invalid choice.\n");
                break;
        }

        printf("\nDo you want to perform another calculation? (Y/N): ");
        scanf("%c", &confirm);
        scanf("%c", &confirm);
        
    }while(confirm == 'Y' || confirm == 'y');

    return 0;
}