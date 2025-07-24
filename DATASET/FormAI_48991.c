//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: innovative
#include <stdio.h>
#include <stdbool.h>

typedef enum { LEFT, RIGHT, FORWARD, BACKWARD } Direction;
typedef struct { int x, y; } Position;
typedef struct { int battery; bool isConnected; } RemoteControl;

RemoteControl remote = { 100, false };

void connectRemote() {
    remote.isConnected = true;
}

void disconnectRemote() {
    remote.isConnected = false;
}

void moveVehicle(Direction dir, int distance) {
    if (remote.isConnected && remote.battery > 0) {
        if (dir == LEFT) {
            printf("Moving left %d meters\n", distance);
            remote.battery -= distance * 2;
        } else if (dir == RIGHT) {
            printf("Moving right %d meters\n", distance);
            remote.battery -= distance * 2;
        } else if (dir == FORWARD) {
            printf("Moving forward %d meters\n", distance);
            remote.battery -= distance * 3;
        } else if (dir == BACKWARD) {
            printf("Moving backward %d meters\n", distance);
            remote.battery -= distance * 3;
        } else {
            printf("Invalid direction entered\n");
        }
        printf("Battery level: %d%%\n", remote.battery);

        if (remote.battery < 10) {
            printf("Low battery! Please recharge\n");
        }
    } else {
        printf("No remote connected or battery dead\n");
    }
}

void printPosition(Position pos) {
    printf("Vehicle position: (%d,%d)\n", pos.x, pos.y);
}

int main() {
    Position carPos = { 0, 0 };

    connectRemote();

    moveVehicle(RIGHT, 5);
    carPos.x += 5;

    moveVehicle(FORWARD, 10);
    carPos.y += 10;

    moveVehicle(LEFT, 3);
    carPos.x -= 3;

    moveVehicle(BACKWARD, 15);
    carPos.y -= 15;

    printPosition(carPos);

    disconnectRemote();

    return 0;
}