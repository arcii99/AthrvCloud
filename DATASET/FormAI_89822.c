//FormAI DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <math.h>

int main() {
    int num, option;
    float result;
    
    printf("Welcome to the Math Exercise Program\n");
    
    do {
        printf("\nChoose an option below:\n");
        printf("1. Calculate the square root of a number\n");
        printf("2. Calculate the power value of a number\n");
        printf("3. Exit the program\n");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                result = sqrt(num);
                printf("The square root of %d is %.2f\n", num, result);
                break;
            
            case 2:
                int power;
                printf("Enter a number: ");
                scanf("%d", &num);
                printf("Enter a power value: ");
                scanf("%d", &power);
                result = pow(num, power);
                printf("%d to the power of %d is %.2f\n", num, power, result);
                break;
                
            case 3:
                printf("Exiting the program...\n");
                break;
                
            default:
                printf("Invalid option. Please choose again.\n");
        }
        
    } while (option != 3);
    
    return 0;
}