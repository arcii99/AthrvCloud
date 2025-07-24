//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define pi 3.141592653589793

int main() {
    // coordinates for starting and ending points
    double x_start, y_start, x_end, y_end;
    printf("Enter the x-coordinate of the starting point: ");
    scanf("%lf", &x_start);
    printf("Enter the y-coordinate of the starting point: ");
    scanf("%lf", &y_start);
    printf("Enter the x-coordinate of the ending point: ");
    scanf("%lf", &x_end);
    printf("Enter the y-coordinate of the ending point: ");
    scanf("%lf", &y_end);

    // convert degrees to radians
    double lat_start = x_start * pi / 180.0;
    double long_start = y_start * pi / 180.0;
    double lat_end = x_end * pi / 180.0;
    double long_end = y_end * pi / 180.0;

    // calculate the distance between the two points
    double a = pow(sin((lat_end - lat_start) / 2), 2) +
               cos(lat_start) * cos(lat_end) * pow(sin((long_end - long_start) / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = 6371 * c;

    // print the distance between the two points
    printf("The distance between the two points is %.2lf km.\n", d);

    return 0;
}