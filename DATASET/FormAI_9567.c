//FormAI DATASET v1.0 Category: Arithmetic ; Style: scientific
#include <stdio.h>
#include <math.h>

int main()
{
    // Declare variables
    int a, b, c;
    float alpha, beta, gamma, delta;

    // Set initial values
    a = 20;
    b = 5;
    c = 10;

    // Calculate angles using trigonometry functions
    alpha = atan((float)b / a);
    beta = atan((float)c / b);
    gamma = M_PI - alpha - beta;

    // Calculate the area of the triangle using Heron's formula
    float s = (float)(a + b + c) / 2;
    delta = sqrt(s * (s - a) * (s - b) * (s - c));

    // Print results
    printf("Angle alpha: %.2f\n", alpha / M_PI * 180);
    printf("Angle beta: %.2f\n", beta / M_PI * 180);
    printf("Angle gamma: %.2f\n", gamma / M_PI * 180);
    printf("Area of the triangle: %.2f\n", delta);

    return 0;
}