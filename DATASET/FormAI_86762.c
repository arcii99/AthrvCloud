//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265358979323846

int main() {
    float start_latitude, start_longitude, end_latitude, end_longitude;
    printf("Enter the start latitude and longitude values: ");
    scanf("%f %f", &start_latitude, &start_longitude);
    printf("Enter the end latitude and longitude values: ");
    scanf("%f %f", &end_latitude, &end_longitude);

    float diff_latitude = (end_latitude - start_latitude) * PI / 180;
    float diff_longitude = (end_longitude - start_longitude) * PI / 180;
    float a = pow(sin(diff_latitude/2), 2) + cos(start_latitude*PI/180) * cos(end_latitude*PI/180) * pow(sin(diff_longitude/2), 2);
    float c = 2 * atan2(sqrt(a), sqrt(1-a));
    float distance = 6371.01 * c;

    printf("The distance between the two points is: %f km.\n", distance);

    return 0;
}