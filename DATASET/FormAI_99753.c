//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: retro
#include<stdio.h>
#include<math.h>

int main(){
    int option;
    float number,result;  // Initializing variables
    printf("\t\t Retro Scientific Calculator \n\n");
    printf("\tChoose an Operation:\n");
    printf("\t1) Square root\n");
    printf("\t2) Exponential\n");
    printf("\t3) Sine\n");
    printf("\t4) Cosine\n");
    printf("\t5) Tangent\n");
    printf("\t6) Logarithm\n");
    printf("\t7) Natural Logarithm\n");
    printf("\t8) Power\n\n");

    printf("\tEnter your choice (1-8): ");
    scanf("%d",&option);

    switch(option){

        case 1: 
            printf("\tEnter number: ");
            scanf("%f",&number);   // Taking input
            result= sqrt(number);  // Performing square root operation
            printf("\tSquare root of %.2f is: %.2f\n",number,result);  // Displaying result
            break;

        case 2:
            printf("\tEnter number: ");
            scanf("%f",&number);
            result= exp(number);  // Performing exponential operation
            printf("\tExponential of %.2f is: %.2f\n",number,result);
            break;

        case 3:
            printf("\tEnter angle in degrees: ");
            scanf("%f",&number);
            result= sin(number*(3.141592/180));  // Performing sine operation(convert to radians)
            printf("\tSine of %.2f degrees is: %.2f\n",number,result);
            break;

        case 4:
            printf("\tEnter angle in degrees: ");
            scanf("%f",&number);
            result= cos(number*(3.141592/180));  // Performing cosine operation(convert to radians)
            printf("\tCosine of %.2f degrees is: %.2f\n",number,result);
            break;

        case 5:
            printf("\tEnter angle in degrees: ");
            scanf("%f",&number);
            result= tan(number*(3.141592/180));  // Performing tangent operation(convert to radians)
            printf("\tTangent of %.2f degrees is: %.2f\n",number,result);
            break;

        case 6:
            printf("\tEnter number: ");
            scanf("%f",&number);
            result= log10(number);  // Performing logarithm operation
            printf("\tLogarithm of %.2f is: %.2f\n",number,result);
            break;

        case 7:
            printf("\tEnter number: ");
            scanf("%f",&number);
            result= log(number);  // Performing natural logarithm operation
            printf("\tNatural Logarithm of %.2f is: %.2f\n",number,result);
            break;

        case 8:
            float power;
            printf("\tEnter number: ");
            scanf("%f",&number);
            printf("\tEnter power: ");
            scanf("%f",&power);
            result= pow(number,power); // Performing power operation
            printf("\t%.2f raised to the power of %.2f is: %.2f\n",number,power,result);
            break;

        default:
            printf("\tInvalid choice!\n");
    }

    return 0; // End of program
}