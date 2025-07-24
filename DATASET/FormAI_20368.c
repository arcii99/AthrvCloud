//FormAI DATASET v1.0 Category: Educational ; Style: peaceful
#include <stdio.h>

int main() {
   /* Declare variables */
    int num1, num2, num3;
    float avg;
    
    /* Input three numbers from the user */
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    printf("Enter the third number: ");
    scanf("%d", &num3);
    
    /* Calculate the average of the three numbers */
    avg = (num1 + num2 + num3) / 3.0;
    
    /* Print the average */
    printf("The average of %d, %d, and %d is: %.2f\n", num1, num2, num3, avg);
    
    /* Check which number is the maximum */
    if (num1 >= num2 && num1 >= num3) {
        printf("%d is the maximum number\n", num1);
    } else if (num2 >= num1 && num2 >= num3) {
        printf("%d is the maximum number\n", num2);
    } else {
        printf("%d is the maximum number\n", num3);
    }
    
    /* Check which number is the minimum */
    if (num1 <= num2 && num1 <= num3) {
        printf("%d is the minimum number\n", num1);
    } else if (num2 <= num1 && num2 <= num3) {
        printf("%d is the minimum number\n", num2);
    } else {
        printf("%d is the minimum number\n", num3);
    }
    
    return 0;
}