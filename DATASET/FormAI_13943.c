//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include<stdio.h>
#include<math.h>

/* The Scientific Calculator Function Declaration */
float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);
float power(float, float);
float root(float);
float sine(float);
float cosine(float);
float tangent(float);

// Menu function to display all the Scientific Calculator operations
void display_menu()
{
    printf("\n");
    printf("  Select an operation from the menu below: \n");
    printf("  1. Addition (+)\n");
    printf("  2. Subtraction (-)\n");
    printf("  3. Multiplication (*)\n");
    printf("  4. Division (/)\n");
    printf("  5. Power function (^)\n");
    printf("  6. Root function (sqrt)\n");
    printf("  7. Sine function (sin)\n");
    printf("  8. Cosine function (cos)\n");
    printf("  9. Tangent function (tan)\n");
    printf("  10. Quit\n\n");
}

// Main Function
int main()
{
    int choice;
    float num1, num2, result;

    printf("Welcome to the Scientific Calculator!\n\n");

    // Displaying the menu
    display_menu();

    // Looping through until user chooses to quit
    do 
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter num1: ");
                scanf("%f", &num1);

                printf("Enter num2: ");
                scanf("%f", &num2);

                result = add(num1, num2);

                printf("%.2f + %.2f = %.2f\n", num1, num2, result);
                break;

            case 2:
                printf("Enter num1: ");
                scanf("%f", &num1);
                
                printf("Enter num2: ");
                scanf("%f", &num2);

                result = subtract(num1, num2);

                printf("%.2f - %.2f = %.2f\n", num1, num2, result);
                break;

            case 3:
                printf("Enter num1: ");
                scanf("%f", &num1);
                
                printf("Enter num2: ");
                scanf("%f", &num2);

                result = multiply(num1, num2);

                printf("%.2f * %.2f = %.2f\n", num1, num2, result);             
                break;

            case 4:
                printf("Enter num1: ");
                scanf("%f", &num1);
                
                printf("Enter num2: ");
                scanf("%f", &num2);

                result = divide(num1, num2);

                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
                break;

            case 5:
                printf("Enter base: ");
                scanf("%f", &num1);
                
                printf("Enter exponent: ");
                scanf("%f", &num2);

                result = power(num1, num2);

                printf("%.2f ^ %.2f = %.2f\n", num1, num2, result);              
                break;

            case 6:
                printf("Enter num1: ");
                scanf("%f", &num1);

                result = root(num1);

                printf("sqrt(%.2f) = %.2f\n", num1, result);
                break;

            case 7:
                printf("Enter angle in degrees: ");
                scanf("%f", &num1);

                result = sine(num1);

                printf("sin(%.2f) = %.2f\n", num1, result);
                break;

            case 8:
                printf("Enter angle in degrees: ");
                scanf("%f", &num1);

                result = cosine(num1);

                printf("cos(%.2f) = %.2f\n", num1, result);
                break;

            case 9:
                printf("Enter angle in degrees: ");
                scanf("%f", &num1);

                result = tangent(num1);

                printf("tan(%.2f) = %.2f\n", num1, result);
                break;

            case 10:
                printf("Exiting the program...");
                break;

            default:
                printf("Invalid input. Please choose a number between 1 and 10.\n");       
        }
    } while (choice != 10);

    return 0;
}

/* The Scientific Calculator Function Definitions */

// Function to perform addition
float add(float num1, float num2)
{
    return num1 + num2;
}

// Function to perform subtraction
float subtract(float num1, float num2)
{
    return num1 - num2;
}

// Function to perform multiplication
float multiply(float num1, float num2)
{
    return num1 * num2;
}

// Function to perform division
float divide(float num1, float num2)
{
    return num1 / num2;
}

// Function to perform power function
float power(float base, float exponent)
{
    return pow(base, exponent);
}

// Function to perform root function
float root(float num1)
{
    return sqrt(num1);
}

// Function to perform sine function
float sine(float angle)
{
    float radians = angle * (M_PI / 180);

    return sin(radians);
}

// Function to perform cosine function
float cosine(float angle)
{
    float radians = angle * (M_PI / 180);

    return cos(radians);
}

// Function to perform tangent function
float tangent(float angle)
{
    float radians = angle * (M_PI / 180);

    return tan(radians);
}