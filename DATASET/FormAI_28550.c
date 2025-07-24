//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: light-weight
#include <stdio.h>

// function to calculate the distance between two points
float distance(float lat1, float lon1, float lat2, float lon2) {
    float R = 6371; // radius of the earth in km
    float dLat = (lat2 - lat1) * (3.141592653589793 / 180);
    float dLon = (lon2 - lon1) * (3.141592653589793 / 180);
    float a = sin(dLat / 2) * sin(dLat / 2) +
              cos(lat1 * (3.141592653589793 / 180)) * cos(lat2 * (3.141592653589793 / 180)) *
              sin(dLon / 2) * sin(dLon / 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    float d = R * c;
    return d;
}

int main() {
    float lat1, lon1, lat2, lon2;
    printf("Enter the latitude and longitude of the first point (in degrees):\n");
    scanf("%f%f", &lat1, &lon1);
    printf("Enter the latitude and longitude of the second point (in degrees):\n");
    scanf("%f%f", &lat2, &lon2);

    float dist = distance(lat1, lon1, lat2, lon2);
    printf("The distance between the two points is %f km.\n", dist);

    return 0;
}