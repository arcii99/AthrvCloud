//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: careful
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

// Function prototypes
double calculateSin(double degrees);
double calculateCos(double degrees);
double calculateTan(double degrees);
double calculateLog(double base, double number);

int main() {
    int choice;
    double value1, value2;
    char operator;
    
    printf("Welcome to the Scientific Calculator!\n");
    
    do {
        printf("\nWhat do you want to do?\n");
        printf("1. Calculate sin\n");
        printf("2. Calculate cos\n");
        printf("3. Calculate tan\n");
        printf("4. Calculate logarithm\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the angle in degrees: ");
                scanf("%lf", &value1);
                printf("The sin of %.2lf degrees is: %.2lf\n", value1, calculateSin(value1));
                break;
                
            case 2:
                printf("Enter the angle in degrees: ");
                scanf("%lf", &value1);
                printf("The cos of %.2lf degrees is: %.2lf\n", value1, calculateCos(value1));
                break;
                
            case 3:
                printf("Enter the angle in degrees: ");
                scanf("%lf", &value1);
                printf("The tan of %.2lf degrees is: %.2lf\n", value1, calculateTan(value1));
                break;
                
            case 4:
                printf("Enter the base: ");
                scanf("%lf", &value1);
                printf("Enter the number: ");
                scanf("%lf", &value2);
                printf("The logarithm of %.2lf to the base %.2lf is: %.2lf\n", value2, value1, calculateLog(value1, value2));
                break;
                
            case 5:
                printf("Thank you for using the Scientific Calculator!\n");
                break;
                
            default:
                printf("Invalid choice\n");
        }
        
    } while(choice != 5);
    
    return 0;
}

double calculateSin(double degrees) {
    return sin(degrees * PI/180);
}

double calculateCos(double degrees) {
    return cos(degrees * PI/180);
}

double calculateTan(double degrees) {
    return tan(degrees * PI/180);
}

double calculateLog(double base, double number) {
    return log(number) / log(base);
}