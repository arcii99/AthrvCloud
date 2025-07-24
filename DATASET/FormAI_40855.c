//FormAI DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for different rooms
#define BEDROOM 1
#define LIVING_ROOM 2
#define KITCHEN 3
#define BATHROOM 4

// Define constants for different devices
#define LIGHTS 1
#define FAN 2
#define AC 3
#define TV 4

// Function prototypes
void initializeDevices(bool devices[], int size);
void printRoomMenu();
void printDeviceMenu();
void toggleDevice(bool devices[], int device);
void controlRoom(bool devices[], int room);

int main()
{
    bool devices[4][5]; // 2D array to store device status for each room
    int choice, room;

    initializeDevices(&devices[0][0], 20);

    while (true) {
        printf("\n\nSMART HOME AUTOMATION SYSTEM\n");
        printf("1. Control Room\n");
        printf("2. Quit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printRoomMenu();
            printf("Enter room number: ");
            scanf("%d", &room);
            controlRoom(&devices[room - 1][0], room);
            break;
        case 2:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid option. Try again.\n");
        }
    }
}

void initializeDevices(bool devices[], int size)
{
    for (int i = 0; i < size; i++) {
        devices[i] = false; // All devices are initially turned off
    }
}

void printRoomMenu()
{
    printf("\nROOMS\n");
    printf("1. Bedroom\n");
    printf("2. Living Room\n");
    printf("3. Kitchen\n");
    printf("4. Bathroom\n");
}

void printDeviceMenu()
{
    printf("\nDEVICES\n");
    printf("1. Lights\n");
    printf("2. Fan\n");
    printf("3. AC\n");
    printf("4. TV\n");
}

void toggleDevice(bool devices[], int device)
{
    devices[device - 1] = !devices[device - 1]; // Toggle device status
}

void controlRoom(bool devices[], int room)
{
    int choice;

    while (true) {
        printf("\n\nROOM %d\n", room);
        printf("1. Lights\n");
        printf("2. Fan\n");
        printf("3. AC\n");
        printf("4. TV\n");
        printf("5. Quit Room %d\n", room);
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            toggleDevice(devices, LIGHTS);
            printf("Lights are now %s.\n", devices[LIGHTS - 1] ? "on" : "off");
            break;
        case 2:
            toggleDevice(devices, FAN);
            printf("Fan is now %s.\n", devices[FAN - 1] ? "on" : "off");
            break;
        case 3:
            toggleDevice(devices, AC);
            printf("AC is now %s.\n", devices[AC - 1] ? "on" : "off");
            break;
        case 4:
            toggleDevice(devices, TV);
            printf("TV is now %s.\n", devices[TV - 1] ? "on" : "off");
            break;
        case 5:
            printf("Exiting Room %d...\n", room);
            return;
        default:
            printf("Invalid option. Try again.\n");
        }
    }
}