//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DISTANCE 100.0  // Maximum distance the drone can fly
#define MAX_TILT_ANGLE 30.0  // Maximum tilt angle of the remote control in degrees

// Function to convert degrees to radians
float toRadians(float angleInDegrees) {
    return angleInDegrees * M_PI / 180.0;
}

// Function to calculate the distance between two coordinates
float calcDistance(float lat1, float lon1, float lat2, float lon2) {
    float dLat = toRadians(lat2 - lat1);
    float dLon = toRadians(lon2 - lon1);
    float a = sin(dLat / 2) * sin(dLat / 2) +
              cos(toRadians(lat1)) * cos(toRadians(lat2)) *
              sin(dLon / 2) * sin(dLon / 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    float distance = 6371 * c;  // 6371 is the radius of the earth in km
    return distance * 1000;  // Convert to meters
}

// Function to calculate the angle between two coordinates
float calcAngle(float lat1, float lon1, float lat2, float lon2) {
    float y = sin(toRadians(lon2 - lon1)) * cos(toRadians(lat2));
    float x = cos(toRadians(lat1)) * sin(toRadians(lat2)) - 
              sin(toRadians(lat1)) * cos(toRadians(lat2)) * cos(toRadians(lon2 - lon1));
    float angleInDegrees = atan2(y, x) * 180 / M_PI;
    return angleInDegrees;
}

int main() {
    float droneLat = 45.0;
    float droneLon = 120.0;
    float remoteLat = 44.0;
    float remoteLon = 121.0;
    float distance = calcDistance(droneLat, droneLon, remoteLat, remoteLon);
    float angle = calcAngle(droneLat, droneLon, remoteLat, remoteLon);
    printf("Distance to remote control: %.2fm\n", distance);
    printf("Angle to remote control: %.2f degrees\n", angle);
    float tiltAngle = 0.0;
    if (distance > MAX_DISTANCE) {
        printf("Warning: Drone is out of range\n");
        tiltAngle = MAX_TILT_ANGLE;
    }
    else if (angle > MAX_TILT_ANGLE) {
        printf("Warning: Drone is tilting too much\n");
        tiltAngle = MAX_TILT_ANGLE;
    }
    else {
        tiltAngle = angle;
    }
    printf("Tilt angle of remote control: %.2f degrees\n", tiltAngle);
    // Code to send tilt angle to drone and make it move
    return 0;
}