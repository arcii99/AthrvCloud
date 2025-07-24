//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: grateful
#include<stdio.h>
#include<math.h>

int main(){

    printf("*********** Scientific Calculator ***********\n\n");

    printf("Select Operation: \n");
    printf("1. Addition \n");
    printf("2. Subtraction \n");
    printf("3. Multiplication \n");
    printf("4. Division \n");
    printf("5. Power \n");
    printf("6. Logarithm \n");
    printf("7. Square Root \n");
    printf("8. Trigonometry \n");
    printf("9. Clear Input \n");
    printf("10. Exit \n");

    int choice;
    float num1, num2;
    float result;

    printf("\nEnter the operation number: ");
    scanf("%d", &choice);

    switch(choice){

        case 1:
            printf("\nEnter the two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("The sum of %.2f and %.2f is: %.2f", num1, num2, result);
            break;

        case 2:
            printf("\nEnter the two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("The difference of %.2f and %.2f is: %.2f", num1, num2, result);
            break;

        case 3:
            printf("\nEnter the two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("The product of %.2f and %.2f is: %.2f", num1, num2, result);
            break;

        case 4:
            printf("\nEnter the two numbers: ");
            scanf("%f %f", &num1, &num2);
            if(num2 == 0){
                printf("Invalid Input! Division by zero is undefined.");
            }
            else{
                result = num1 / num2;
                printf("The quotient of %.2f and %.2f is: %.2f", num1, num2, result);
            }
            break;

        case 5:
            printf("\nEnter the base number: ");
            scanf("%f", &num1);
            printf("Enter the exponent: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("The power of %.2f raised to %.2f is: %.2f", num1, num2, result);
            break;

        case 6:
            printf("\nEnter the number: ");
            scanf("%f", &num1);
            result = log10(num1);
            printf("The logarithm of %.2f is: %.2f", num1, result);
            break;

        case 7:
            printf("\nEnter the number: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("The square root of %.2f is: %.2f", num1, result);
            break;

        case 8:
            printf("\nSelect a Trigonometric Function: \n");
            printf("1. sin \n");
            printf("2. cos \n");
            printf("3. tan \n");
            printf("4. cosec \n");
            printf("5. sec \n");
            printf("6. cot \n");

            int trig_choice;
            float deg_angle, rad_angle;

            printf("\nEnter the Trigonometric Function Number: ");
            scanf("%d", &trig_choice);

            printf("Enter the Angle in Degrees: ");
            scanf("%f", &deg_angle);

            rad_angle = deg_angle * (M_PI/180); //convert degree to radians
            
            switch(trig_choice){

                case 1:
                    result = sin(rad_angle);
                    printf("The sin of %.2f degrees is: %.2f", deg_angle, result);
                    break;

                case 2:
                    result = cos(rad_angle);
                    printf("The cos of %.2f degrees is: %.2f", deg_angle, result);
                    break;

                case 3:
                    result = tan(rad_angle);
                    printf("The tan of %.2f degrees is: %.2f", deg_angle, result);
                    break;

                case 4:
                    if(sin(rad_angle) == 0){
                        printf("Invalid Input! cosec of %.2f degrees is undefined.", deg_angle);
                    }
                    else{
                        result = 1/sin(rad_angle);
                        printf("The cosec of %.2f degrees is: %.2f", deg_angle, result);
                    }
                    break;

                case 5:
                    if(cos(rad_angle) == 0){
                        printf("Invalid Input! sec of %.2f degrees is undefined.", deg_angle);
                    }
                    else{
                        result = 1/cos(rad_angle);
                        printf("The sec of %.2f degrees is: %.2f", deg_angle, result);
                    }
                    break;

                case 6:
                    if(tan(rad_angle) == 0){
                        printf("Invalid Input! cot of %.2f degrees is undefined.", deg_angle);
                    }
                    else{
                        result = 1/tan(rad_angle);
                        printf("The cot of %.2f degrees is: %.2f", deg_angle, result);
                    }
                    break;

                default:
                    printf("Invalid Input! Please Select from 1 to 6.");
                    break;
            }
            break;

        case 9:
            printf("\nInput Cleared!\n");
            break;

        case 10:
            printf("\nThank you for using this Calculator!\n");
            return 0;

        default:
            printf("Invalid Input! Please Select from 1 to 10.");
            break;
    }

    return 0;
}