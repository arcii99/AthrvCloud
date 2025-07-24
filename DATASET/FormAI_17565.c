//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the functions
void takeOff();
void land();
void moveForward(int distance);
void moveBackward(int distance);
void moveRight(int distance);
void moveLeft(int distance);
void moveUp(int distance);
void moveDown(int distance);

// Main Function
int main()
{
    // Drone Information
    char droneName[30] = "My First Drone";
    int droneId = 12345;

    // Adding Decentralized Features
    char features[10][30] = {"AutoPilot", "GPS Tracking", "Obstacle Detection System", "Flight Log", "Emergency Shutdown", "Live Video Streaming", "Mobile App Integration", "Increased Range", "Long Battery Life", "High Speed"};

    // Printing the Drone Information and Features
    printf("Welcome to %s. The ID of the Drone is %d.\n", droneName, droneId);
    printf("This drone has the following features:\n");
    for(int i=0; i<10; i++)
    {
        printf("%d. %s\n", i+1, features[i]);
    }

    // Performing some Drone Actions
    printf("\nLet's take off the drone...\n");
    takeOff();

    printf("\nNow move the drone forward by 50 metres...\n");
    moveForward(50);

    printf("\nNow move the drone right by 20 metres...\n");
    moveRight(20);

    printf("\nNow move the drone up by 10 metres...\n");
    moveUp(10);

    printf("\nNow move the drone backward by 30 metres...\n");
    moveBackward(30);

    printf("\nNow move the drone left by 15 metres...\n");
    moveLeft(15);

    printf("\nNow move the drone down by 5 metres...\n");
    moveDown(5);

    // Landing the Drone
    printf("\nLanding the drone...\n");
    land();

    return 0;
}

// Defining the Functions

void takeOff()
{
    printf("The drone has taken off.\n");
}

void land()
{
    printf("The drone has landed.\n");
}

void moveForward(int distance)
{
    printf("The drone moved forward by %d metres.\n", distance);
}

void moveBackward(int distance)
{
    printf("The drone moved backward by %d metres.\n", distance);
}

void moveRight(int distance)
{
    printf("The drone moved right by %d metres.\n", distance);
}

void moveLeft(int distance)
{
    printf("The drone moved left by %d metres.\n", distance);
}

void moveUp(int distance)
{
    printf("The drone moved up by %d metres.\n", distance);
}

void moveDown(int distance)
{
    printf("The drone moved down by %d metres.\n", distance);
}