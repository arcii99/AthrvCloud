//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: creative
#include <stdio.h>

// Define the vehicle struct
typedef struct {
    int speed;
    int direction;
    int batteryLevel;
} Vehicle;

// Define the remote control struct
typedef struct {
    int channel;
    Vehicle* vehiclePtr;
} RemoteControl;

// Define the functions needed to interact with the vehicle
void driveForward(Vehicle* v) {
    printf("Driving forward at speed %d\n", v->speed);
}

void turnLeft(Vehicle* v) {
    printf("Turning left at speed %d\n", v->speed/2);
}

void turnRight(Vehicle* v) {
    printf("Turning right at speed %d\n", v->speed/2);
}

void stopVehicle(Vehicle* v) {
    printf("Vehicle stopped at speed 0\n");
    v->speed = 0;
}

// Define the functions needed to interact with the remote control
void changeChannel(RemoteControl* rc, int newChannel) {
    rc->channel = newChannel;
    printf("Remote control channel changed to %d\n", rc->channel);
}

void increaseSpeed(RemoteControl* rc) {
    rc->vehiclePtr->speed += 10;
    printf("Speed increased to %d\n", rc->vehiclePtr->speed);
}

void decreaseSpeed(RemoteControl* rc) {
    rc->vehiclePtr->speed -= 10;
    printf("Speed decreased to %d\n", rc->vehiclePtr->speed);
}

void turnVehicle(RemoteControl* rc, int direction) {
    rc->vehiclePtr->direction = direction;
    if(direction == -1) {
        turnLeft(rc->vehiclePtr);
    } else if(direction == 1) {
        turnRight(rc->vehiclePtr);
    }
}

void checkBatteryLevel(RemoteControl* rc) {
    printf("Battery level: %d\n", rc->vehiclePtr->batteryLevel);
}

// Main function to simulate remote control vehicle interactions
int main() {
    // Create the vehicle and initialize its properties
    Vehicle myVehicle = {20, 0, 100};

    // Create the remote control and link it to the vehicle
    RemoteControl myRemoteControl = {1, &myVehicle};

    // Test the functions
    printf("Vehicle speed: %d\n", myVehicle.speed); // Expected output: 20
    
    increaseSpeed(&myRemoteControl); // Expected output: Speed increased to 30
    decreaseSpeed(&myRemoteControl); // Expected output: Speed decreased to 20
    
    turnVehicle(&myRemoteControl, -1); // Expected output: Turning left at speed 10
    turnVehicle(&myRemoteControl, 1); // Expected output: Turning right at speed 10
    
    stopVehicle(&myVehicle); // Expected output: Vehicle stopped at speed 0
    
    checkBatteryLevel(&myRemoteControl); // Expected output: Battery level: 100

    return 0;
}