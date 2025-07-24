//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

struct GPS_Location {
    double latitude;
    double longitude;
};

double deg2rad(double deg) {
    return deg * (PI / 180);
}

double rad2deg(double rad) {
    return rad * (180 / PI);
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double r = 6371; // Earth's radius in km
    double dLat = deg2rad(lat2 - lat1);
    double dLon = deg2rad(lon2 - lon1);

    double a = sin(dLat / 2) * sin(dLat / 2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * sin(dLon / 2) * sin(dLon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = r * c; // Distance in km

    return distance;
}

double bearing(double lat1, double lon1, double lat2, double lon2) {
    double dLon = deg2rad(lon2 - lon1);
    double y = sin(dLon) * cos(deg2rad(lat2));
    double x = cos(deg2rad(lat1)) * sin(deg2rad(lat2)) - sin(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(dLon);

    double brng = atan2(y, x);
    brng = rad2deg(brng);
    return fmod((brng + 360), 360);
}

int main() {
    struct GPS_Location location1, location2;
    double distanceTravelled = 0.0, totalDistance = 0.0, bearingAngle;
    int choice;

    printf("Enter your current GPS location's latitude and longitude: ");
    scanf("%lf %lf", &location1.latitude, &location1.longitude);

    printf("Enter your destination GPS location's latitude and longitude: ");
    scanf("%lf %lf", &location2.latitude, &location2.longitude);

    // Calculate the initial bearing
    bearingAngle = bearing(location1.latitude, location1.longitude, location2.latitude, location2.longitude);

    // Loop until user reaches destination
    do {
        printf("\nOptions:\n");
        printf("1 - Travel 1 km forward\n");
        printf("2 - Turn left\n");
        printf("3 - Turn right\n");
        printf("4 - Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Move 1 km forward in the current direction
                double lat1 = deg2rad(location1.latitude);
                double lon1 = deg2rad(location1.longitude);
                double brng = deg2rad(bearingAngle);
                double d = 1; // Distance to travel in km

                double lat2 = asin(sin(lat1) * cos(d / 6371) + cos(lat1) * sin(d / 6371) * cos(brng));
                double lon2 = lon1 + atan2(sin(brng) * sin(d / 6371) * cos(lat1), cos(d / 6371) - sin(lat1) * sin(lat2));

                location1.latitude = rad2deg(lat2);
                location1.longitude = rad2deg(lon2);

                // Calculate the distance travelled
                distanceTravelled += distance(location1.latitude, location1.longitude, location2.latitude, location2.longitude);

                // Check if user has reached destination
                if(distanceTravelled >= totalDistance) {
                    printf("Congratulations, you have reached your destination!\n");
                } else {
                    printf("Distance to destination: %.2f km\n", totalDistance - distanceTravelled);
                }
                break;
            case 2:
                // Turn left
                bearingAngle -= 90;
                if(bearingAngle < 0) {
                    bearingAngle += 360;
                }
                printf("Turning left, current bearing angle: %.2f\n", bearingAngle);
                break;
            case 3:
                // Turn right
                bearingAngle += 90;
                if(bearingAngle >= 360) {
                    bearingAngle -= 360;
                }
                printf("Turning right, current bearing angle: %.2f\n", bearingAngle);
                break;
            case 4:
                // Quit program
                printf("Thank you for using our GPS navigation simulation program!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while(1); // Loop indefinitely until user exits program

    return 0;
}