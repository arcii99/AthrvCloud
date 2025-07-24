//FormAI DATASET v1.0 Category: Math exercise ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double calculate_hypotenuse(double side_a, double side_b);
double convert_degrees_to_radians(double degree);

int main()
{
    double side_a = 5.0;
    double side_b = 7.0;
    double hypotenuse = calculate_hypotenuse(side_a, side_b);
    printf("The hypotenuse of a right triangle with sides %.2lf and %.2lf is %.2lf\n", side_a, side_b, hypotenuse);

    double degree = 30.0;
    double radians = convert_degrees_to_radians(degree);
    printf("%.2lf degrees is equal to %.4lf radians\n", degree, radians);

    double x = 2.5;
    double sin_x = sin(x);
    double cos_x = cos(x);
    double tan_x = tan(x);
    printf("The values of sin(%.2lf), cos(%.2lf) and tan(%.2lf) are %.4lf, %.4lf, and %.4lf respectively\n", x, x, x, sin_x, cos_x, tan_x);

    double y = -10.0;
    double absolute_y = fabs(y);
    double square_root_y = sqrt(absolute_y);
    printf("The absolute value of %.2lf is %.2lf and the square root of its absolute value is %.2lf\n", y, absolute_y, square_root_y);

    double z = 3.14159;
    double power_of_z = pow(z, 3);
    printf("%.5lf raised to the power of 3 is equal to %.5lf\n", z, power_of_z);

    return 0;
}

double calculate_hypotenuse(double side_a, double side_b)
{
    double sum_of_squares = pow(side_a, 2) + pow(side_b, 2);
    double hypotenuse = sqrt(sum_of_squares);
    return hypotenuse;
}

double convert_degrees_to_radians(double degree)
{
    double radians = degree * M_PI / 180.0;
    return radians;
}