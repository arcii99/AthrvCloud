//FormAI DATASET v1.0 Category: Error handling ; Style: mathematical
/* Mathematical Error Handling Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main() {
    double rad, deg, result;
    int choice;
    
    printf("Enter 1 to convert radians to degrees\n");
    printf("Enter 2 to convert degrees to radians\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter the value in radians: ");
            scanf("%lf", &rad);
            deg = rad * 180 / PI;
            result = sin(deg);
            if(isnan(result)){
                printf("Error: The value entered is not a number\n");
                exit(0);
            }
            printf("The value in degrees is: %lf\n", deg);
            printf("The sine of %lf degrees is: %lf\n", deg, result);
            break;
        case 2:
            printf("Enter the value in degrees: ");
            scanf("%lf", &deg);
            rad = deg * PI / 180;
            result = log(rad);      
            if(isinf(result)){
                printf("Error: The value entered results in an infinite log\n");
                exit(0);
            }
            printf("The value in radians is: %lf\n", rad);
            printf("The natural logarithm of %lf is: %lf\n", rad, result);
            break;
        default:
            printf("Error: Invalid choice entered\n");
            break;
    }
    
    return 0;
}