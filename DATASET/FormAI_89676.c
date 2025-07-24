//FormAI DATASET v1.0 Category: Physics simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int seconds = 0;
    float distance, speed, acceleration;

    printf("Welcome to the Physics Simulation Show!\n");
    printf("Our first act features a car accelerating from 0 to 60 mph in record time!\n");
    printf("=========================\n\n");

    acceleration = 9.8; // m/sec^2
    distance = 402.336; // meters (1/4 mile)
    speed = 0; // m/sec

    while (speed < 26.8224) { // 0-60 mph (0-26.8224 m/s)
        printf("Seconds: %d | Speed: %0.2f m/s | Distance: %0.2f meters\n", seconds, speed, distance);
        speed += acceleration;
        distance += speed;
        seconds++;
    }

    printf("=========================\n\n");
    printf("Wow! That was fast!\n");
    printf("Our next act features a cannon shooting a projectile into the air!\n");
    printf("=========================\n\n");

    float angle, time, height, range;

    printf("What angle would you like to fire the cannon at? (in degrees)\n");
    scanf("%f", &angle);

    angle = angle * M_PI / 180.0;
    height = 0;
    speed = 200.0; // m/sec

    time = (2.0 * speed * sin(angle)) / acceleration;
    range = speed * cos(angle) * time;

    printf("=========================\n\n");
    printf("Here are the results of our cannon simulation:\n");
    printf("Initial Velocity: %0.2f m/s\n", speed);
    printf("Angle: %0.2f degrees\n", angle * 180.0 / M_PI);
    printf("Time of Flight: %0.2f seconds\n", time);
    printf("Range: %0.2f meters\n", range);
    printf("Maximum Height: %0.2f meters\n", pow(speed * sin(angle),2)/(2*acceleration));
    printf("\n");

    printf("=========================\n\n");
    printf("What an amazing show! Thank you for joining us for this Physics Simulation!\n");

    return 0;
}