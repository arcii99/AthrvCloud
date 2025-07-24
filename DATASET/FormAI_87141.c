//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: creative
#include <stdio.h>
#include <math.h>

// Defining functions
void calculateDistance(float lat1, float long1, float lat2, float long2, float *distance, float *finalHeading);
float degToRad(float deg);
float radToDeg(float rad);

// Main Function
int main() {
    float lat1, long1, lat2, long2, distance, finalHeading;

    //Longitude and latitude of starting point
    lat1 = 23.3505;
    long1 = 85.3308;

    //Longitude and latitude of ending point
    lat2 = 18.5204;
    long2 = 73.8567;

    //Function call to calculate distance and final heading
    calculateDistance(lat1, long1, lat2, long2, &distance, &finalHeading);  

    printf("The total distance between the two points is %.2f km\n", distance);
    printf("The final heading from initial point to ending point is %.2f degrees", finalHeading);

    return 0;
}

// Function to convert degrees to radians
float degToRad(float deg) {
    return deg * (M_PI/180);
}

// Function to convert radians to degrees
float radToDeg(float rad) {
    return rad * (180/M_PI);
}

// Function to calculate distance and final heading
void calculateDistance(float lat1, float long1, float lat2, float long2, float *distance, float *finalHeading) {

    float R = 6371; // Radius of earth in km

    // Converting latitude and longitude to radians
    lat1 = degToRad(lat1);
    long1 = degToRad(long1);
    lat2 = degToRad(lat2);
    long2 = degToRad(long2);

    // Calculating distance between two points using Haversine formula
    float dLat = lat2 - lat1;
    float dLong = long2 - long1;
    float a = sin(dLat/2)*sin(dLat/2) + cos(lat1)*cos(lat2)*sin(dLong/2)*sin(dLong/2);
    float c = 2 * atan2(sqrt(a),sqrt(1-a));
    *distance = R * c;

    // Calculating final bearing in degrees using Vincenty's formulae
    float y = sin(long2 - long1) * cos(lat2);
    float x = cos(lat1)*sin(lat2) - sin(lat1)*cos(lat2)*cos(long2-long1);
    *finalHeading = radToDeg(atan2(y, x));

    *finalHeading = fmod((*finalHeading + 360), 360); // Adjusting final heading within 0-360 range
}