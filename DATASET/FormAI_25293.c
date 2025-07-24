//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Defining a structure for the GPS coordinates
typedef struct {
    double latitude;
    double longitude;
} gpsCoordinates;

//Function to generate a random GPS coordinate
gpsCoordinates generateGPS() {
    gpsCoordinates gps;

    gps.latitude = (rand() % 180 - 90) + ((double) rand() / RAND_MAX);
    gps.longitude = (rand() % 360 - 180) + ((double) rand() / RAND_MAX);

    return gps;
}

//Function to calculate the distance between two GPS coordinates
double distance(gpsCoordinates a, gpsCoordinates b) {
    double distance, x, y;

    x = sin((b.latitude - a.latitude) / 2);
    y = sin((b.longitude - a.longitude) / 2);

    distance = 2 * asin(sqrt(x * x + cos(a.latitude) * cos(b.latitude) * y * y));

    distance = distance * 6371;

    return distance;
}

//Function to simulate GPS Navigation
void navigate(gpsCoordinates a, gpsCoordinates b) {
    double dist = distance(a, b);

    printf("Starting point: %.10f, %.10f \n", a.latitude, a.longitude);
    printf("Destination: %.10f, %.10f \n", b.latitude, b.longitude);
    printf("Total Distance: %.2f km \n\n", dist);

    //Simulation Loop
    gpsCoordinates current = a;
    double remainingDist = dist;
    int turn = 0;

    while (remainingDist > 0.01) {
        //Calculate a new GPS coordinate in the direction of destination
        double angle = atan2(sin(b.longitude - current.longitude) * cos(b.latitude),
                            cos(current.latitude) * sin(b.latitude)
                            - sin(current.latitude) * cos(b.latitude) * cos(b.longitude - current.longitude));
        double newLat = asin(sin(current.latitude) * cos(remainingDist / 6371)
                        + cos(current.latitude) * sin(remainingDist / 6371) * cos(angle));
        double newLon = fmod(current.longitude - asin(sin(angle) * sin(remainingDist / 6371) / cos(newLat)) + M_PI, 2 * M_PI) - M_PI;

        gpsCoordinates nextCoord = {newLat, newLon};

        //Print turn-by-turn navigation instructions
        if (turn == 0) {
            printf("Start driving from current location towards destination");
        } else {
            double turnAngle = fmod(atan2(sin(nextCoord.longitude - current.longitude) * cos(nextCoord.latitude),
                                        cos(current.latitude) * sin(nextCoord.latitude)
                                        - sin(current.latitude) * cos(nextCoord.latitude) * cos(nextCoord.longitude - current.longitude))
                                        - angle + 3 * M_PI, 2 * M_PI) - M_PI;
            if (turnAngle > 0.2618 && turnAngle < 1.0472) {
                printf("In %.2f km, turn slight right \n", remainingDist);
            } else if (turnAngle >= 1.0472 && turnAngle < 1.8326) {
                printf("In %.2f km, turn right \n", remainingDist);
            } else if (turnAngle >= 1.8326 && turnAngle < 2.618) {
                printf("In %.2f km, turn sharp right \n", remainingDist);
            } else if (turnAngle >= 2.618 && turnAngle < 3.1416) {
                printf("In %.2f km, make a U-turn \n", remainingDist);
            } else if (turnAngle < -0.2618 && turnAngle > -1.0472) {
                printf("In %.2f km, turn slight left \n", remainingDist);
            } else if (turnAngle <= -1.0472 && turnAngle > -1.8326) {
                printf("In %.2f km, turn left \n", remainingDist);
            } else if (turnAngle <= -1.8326 && turnAngle > -2.618) {
                printf("In %.2f km, turn sharp left \n", remainingDist);
            }
        }

        //Update Current Location
        remainingDist -= distance(current, nextCoord);
        current = nextCoord;
        turn++;
    }

    printf("Arrived at destination! \n");
}

int main() {
    srand(time(0));
    gpsCoordinates locationA = generateGPS();
    gpsCoordinates locationB = generateGPS();

    navigate(locationA, locationB);

    return 0;
}