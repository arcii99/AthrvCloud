//FormAI DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>

/* A program to calculate the height and weight of a person
   using arithmetic operations */

int main() {
    int age, height, weight, height_sq;
    float bmi;

    printf("Welcome to the BMI Calculator!\n");
    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your height in inches: ");
    scanf("%d", &height);

    printf("Please enter your weight in pounds: ");
    scanf("%d", &weight);

    // Calculate BMI
    height_sq = height * height;
    bmi = (float) weight / (float) height_sq * 703;

    // Output results
    printf("At %d years old,\n", age);
    printf("with a height of %d inches,\n", height);
    printf("and a weight of %d pounds,\n", weight);
    printf("your BMI is %.2f.\n", bmi);

    // Determine health status based on BMI
    if (bmi < 18.5) {
        printf("You are underweight.\n");
    } else if (bmi < 25) {
        printf("You are of normal weight.\n");
    } else if (bmi < 30) {
        printf("You are overweight.\n");
    } else {
        printf("You are obese.\n");
    }

    return 0;
}