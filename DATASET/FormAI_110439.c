//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: lively
#include<stdio.h>
#include<math.h>

#define pi 3.14159265358979323846

float toRadians(float angle)
{
    return (angle*pi)/180;
}

float distance(float lat1, float lat2, float lon1, float lon2)
{
    float R = 6371; // Radius of the earth in km
    float dLat = toRadians(lat2-lat1);
    float dLon = toRadians(lon2-lon1);
    float a = sin(dLat/2) * sin(dLat/2) +
            cos(toRadians(lat1)) * cos(toRadians(lat2)) *
            sin(dLon/2) * sin(dLon/2);
    float c = 2 * atan2(sqrt(a), sqrt(1-a));
    float d = R * c; // Distance in km
    return d;
}

void calculateDirection(float x1, float x2, float y1, float y2)
{
    float lat1, lat2, lon1, lon2, angle;
    lat1 = x1;
    lat2 = x2;
    lon1 = y1;
    lon2 = y2;
    angle = atan2(sin(lon2-lon1)*cos(lat2), cos(lat1)*sin(lat2)-sin(lat1)*cos(lat2)*cos(lon2-lon1));
    angle = toRadians(angle);
    angle = angle*(180/pi);
    if(angle < 0){
        angle+=360;
    }
    printf("Turn %.2f degrees %s\n", fabs(angle), (angle>180?"right":"left"));
}

int main()
{
    float lat1 = 51.5074, lon1 = -0.1278; // Starting point, London
    float lat2 = 41.3851, lon2 = 2.1734; // Destination, Barcelona
    float d = distance(lat1, lat2, lon1, lon2);
    int time = ceil(d * 2); // In hours
    printf("Total distance: %.2f km\n", d);
    printf("Estimated time of arrival: %i hours\n", time);
    printf("Directions:\n");
    calculateDirection(lat1, lat2, lon1, lon2);
    return 0;
}