//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: minimalist
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

// Function to calculate the distance between two coordinates in kilometers
float distance(float latitude1, float longitude1, float latitude2, float longitude2)
{
    float d, x, y;

    latitude1 *= PI/180;
    longitude1 *= PI/180;
    latitude2 *= PI/180;
    longitude2 *= PI/180;

    x = (longitude2 - longitude1) * cos((latitude1 + latitude2)/2);
    y = latitude2 - latitude1;

    d = sqrt(x*x + y*y) * 6371; // 6371 is the radius of Earth in kilometers

    return d;
}

int main()
{
    float lat1, long1, lat2, long2;

    printf("Enter the latitude and longitude of your current location (in decimal form):\n");
    scanf("%f %f", &lat1, &long1);

    printf("Enter the latitude and longitude of the destination (in decimal form):\n");
    scanf("%f %f", &lat2, &long2);

    float dist = distance(lat1, long1, lat2, long2);

    printf("Distance between your current location and destination is %.2f kilometers.\n", dist);

    return 0;
}