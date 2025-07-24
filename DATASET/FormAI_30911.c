//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: secure
#include <stdio.h>
#include <stdbool.h>

// Define the maximum speed of the remote control vehicle
#define MAX_SPEED 100

// Define the minimum speed of the remote control vehicle
#define MIN_SPEED 0

// Define the initial speed of the remote control vehicle
#define INITIAL_SPEED 50

// Define the initial direction of the remote control vehicle
#define INITIAL_DIRECTION 'F'

// Define the maximum angle of the remote control vehicle
#define MAX_ANGLE 180

// Define the minimum angle of the remote control vehicle
#define MIN_ANGLE -180

// Define the initial angle of the remote control vehicle
#define INITIAL_ANGLE 0

// Define the maximum distance of the remote control vehicle
#define MAX_DISTANCE 100

// Define the minimum distance of the remote control vehicle
#define MIN_DISTANCE 0

// Define the initial distance of the remote control vehicle
#define INITIAL_DISTANCE 0

// Define the maximum battery life of the remote control vehicle
#define MAX_BATTERY_LIFE 100

// Define the minimum battery life of the remote control vehicle
#define MIN_BATTERY_LIFE 0

// Define the initial battery life of the remote control vehicle
#define INITIAL_BATTERY_LIFE 100

// Structure to store the properties of the remote control vehicle
typedef struct 
{
    int speed;
    char direction;
    int angle;
    int distance;
    int batteryLife;
} RemoteControlVehicle;

// Function to initialize the remote control vehicle with default properties
void initializeVehicle(RemoteControlVehicle *vehicle)
{
    vehicle->speed = INITIAL_SPEED;
    vehicle->direction = INITIAL_DIRECTION;
    vehicle->angle = INITIAL_ANGLE;
    vehicle->distance = INITIAL_DISTANCE;
    vehicle->batteryLife = INITIAL_BATTERY_LIFE;
}

// Function to set the speed of the remote control vehicle
bool setSpeed(RemoteControlVehicle *vehicle, int speed)
{
    if (speed < MIN_SPEED || speed > MAX_SPEED)
    {
        return false;
    }

    vehicle->speed = speed;
    return true;
}

// Function to set the direction of the remote control vehicle
bool setDirection(RemoteControlVehicle *vehicle, char direction)
{
    if (direction != 'F' && direction != 'B' && direction != 'L' && direction != 'R')
    {
        return false;
    }

    vehicle->direction = direction;
    return true;
}

// Function to set the angle of the remote control vehicle
bool setAngle(RemoteControlVehicle *vehicle, int angle)
{
    if (angle < MIN_ANGLE || angle > MAX_ANGLE)
    {
        return false;
    }

    vehicle->angle = angle;
    return true;
}

// Function to move the remote control vehicle with the current speed and direction
void moveVehicle(RemoteControlVehicle *vehicle)
{
    switch (vehicle->direction)
    {
        case 'F':
            vehicle->distance += vehicle->speed;
            break;
        case 'B':
            vehicle->distance -= vehicle->speed;
            break;
        case 'L':
            vehicle->angle -= vehicle->speed / 5;
            break;
        case 'R':
            vehicle->angle += vehicle->speed / 5;
            break;
    }

    if (vehicle->distance < MIN_DISTANCE || vehicle->distance > MAX_DISTANCE)
    {
        vehicle->distance = INITIAL_DISTANCE;
    }

    if (vehicle->angle < MIN_ANGLE || vehicle->angle > MAX_ANGLE)
    {
        vehicle->angle = INITIAL_ANGLE;
    }

    vehicle->batteryLife -= vehicle->speed / 10;

    if (vehicle->batteryLife < MIN_BATTERY_LIFE)
    {
        vehicle->batteryLife = MIN_BATTERY_LIFE;
    }
}

// Function to display the status of the remote control vehicle
void displayStatus(RemoteControlVehicle *vehicle)
{
    printf("Speed: %d\n", vehicle->speed);
    printf("Direction: %c\n", vehicle->direction);
    printf("Angle: %d\n", vehicle->angle);
    printf("Distance: %d\n", vehicle->distance);
    printf("Battery Life: %d\n", vehicle->batteryLife);
}

int main()
{
    RemoteControlVehicle vehicle;
    initializeVehicle(&vehicle);

    setSpeed(&vehicle, 75);
    setDirection(&vehicle, 'F');
    setAngle(&vehicle, 45);

    displayStatus(&vehicle);

    moveVehicle(&vehicle);

    displayStatus(&vehicle);

    return 0;
}