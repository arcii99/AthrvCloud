//FormAI DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>

int main() {
    printf("Welcome to the Math Exercise Program!\n\n");
    printf("Let's practice some equations to improve our math skills!\n\n");
    printf("In this exercise, we will calculate the area of a trapezoid with the given height, base1 and base2 values.\n\n");
    
    float height, base1, base2, area;
    
    printf("Please enter the height of the trapezoid: ");
    scanf("%f", &height);
    
    printf("Please enter the length of base1: ");
    scanf("%f", &base1);
    
    printf("Please enter the length of base2: ");
    scanf("%f", &base2);
    
    area = (base1 + base2) * height / 2;
    
    printf("\nBy applying the formula of finding the area of a trapezoid, we get:\n\n");
    printf("Area = (base1 + base2) * height / 2 = (%.2f + %.2f) * %.2f / 2 = %.2f\n\n", base1, base2, height, area);
    
    printf("Excellent! You solved this math equation correctly.\n");
    
    return 0;
}