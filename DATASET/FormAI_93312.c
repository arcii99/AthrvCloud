//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265358979323846

double degreeToRadian(double degree) {
    return (degree * PI) / 180;
}

struct Coordinate {
    double latitude;
    double longitude;
};

void navigate(struct Coordinate presentCoordinate, struct Coordinate destinationCoordinate){
    double R = 6371; //earth's radius in kilometers
    double presentLatRadians = degreeToRadian(presentCoordinate.latitude);
    double presentLongRadians = degreeToRadian(presentCoordinate.longitude);
    double destLatRadians = degreeToRadian(destinationCoordinate.latitude);
    double destLongRadians = degreeToRadian(destinationCoordinate.longitude);
    double dLat = destLatRadians - presentLatRadians;
    double dLong = destLongRadians - presentLongRadians;

    double a = pow(sin(dLat / 2),2) + cos(presentLatRadians) * cos(destLatRadians) * pow(sin(dLong / 2),2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = R * c;

    printf("You are %.2lf kilometers away from the destination.\n",distance);
}

int main() {
    struct Coordinate presentCoordinate = {25.123, -78.456};
    struct Coordinate destinationCoordinate = {30.789, -76.345};

    navigate(presentCoordinate, destinationCoordinate);

    return 0;
}