//FormAI DATASET v1.0 Category: Scientific ; Style: expert-level
#include<stdio.h>
#include<math.h>

// Function to calculate the hypotenuse of a right triangle
double calculate_hypotenuse(double a, double b);

int main() {
    double a, b;
    printf("Enter the value of a: ");
    scanf("%lf", &a);
    printf("Enter the value of b: ");
    scanf("%lf", &b);

    double c = calculate_hypotenuse(a, b);
    printf("The length of the hypotenuse is %.2f\n", c);
    return 0;
}

double calculate_hypotenuse(double a, double b) {
    double c = sqrt(a * a + b * b);
    return c;
}