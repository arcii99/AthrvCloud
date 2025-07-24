//FormAI DATASET v1.0 Category: Smart home automation ; Style: future-proof
#include <stdio.h>
#include <string.h>

#define NUM_ROOMS 3
#define NUM_DEVICES 4

// A struct to represent a smart device.
// Each device is associated with a room and
// has a name and status (on or off).
typedef struct {
    char name[50];
    char room[50];
    int status;
} Device;

// A struct to represent a smart home.
// A home has a name and a list of devices.
typedef struct {
    char name[50];
    Device devices[NUM_ROOMS][NUM_DEVICES];
} Home;

// Function to toggle the status of a device.
void toggleDevice(Device *device) {
    if (device->status == 0) {
        device->status = 1;
    } else {
        device->status = 0;
    }
}

int main() {
    // Create a new smart home.
    Home myHome;
    strcpy(myHome.name, "My Smart Home");

    // Add some devices to the kitchen.
    Device *kitchenDevices = myHome.devices[0];
    strcpy(kitchenDevices[0].name, "Fridge");
    strcpy(kitchenDevices[0].room, "Kitchen");
    kitchenDevices[0].status = 1;

    strcpy(kitchenDevices[1].name, "Oven");
    strcpy(kitchenDevices[1].room, "Kitchen");
    kitchenDevices[1].status = 0;

    // Add some devices to the living room.
    Device *livingRoomDevices = myHome.devices[1];
    strcpy(livingRoomDevices[0].name, "TV");
    strcpy(livingRoomDevices[0].room, "Living Room");
    livingRoomDevices[0].status = 1;

    strcpy(livingRoomDevices[1].name, "Lights");
    strcpy(livingRoomDevices[1].room, "Living Room");
    livingRoomDevices[1].status = 1;

    // Add some devices to the bedroom.
    Device *bedroomDevices = myHome.devices[2];
    strcpy(bedroomDevices[0].name, "Fan");
    strcpy(bedroomDevices[0].room, "Bedroom");
    bedroomDevices[0].status = 0;

    strcpy(bedroomDevices[1].name, "Lights");
    strcpy(bedroomDevices[1].room, "Bedroom");
    bedroomDevices[1].status = 1;

    // Allow the user to control the devices.
    while (1) {
        // Print out the current status of each device.
        printf("Current status:\n");
        for (int i = 0; i < NUM_ROOMS; i++) {
            Device *devices = myHome.devices[i];
            for (int j = 0; j < NUM_DEVICES; j++) {
                if (strlen(devices[j].name) > 0) {
                    printf("- %s in %s: %s\n", devices[j].name,
                           devices[j].room, devices[j].status ? "ON" : "OFF");
                }
            }
        }

        // Allow the user to select a device to control.
        printf("Enter the name of the device to control, or 'quit' to exit: ");
        char input[50];
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Find the device and toggle its status.
        for (int i = 0; i < NUM_ROOMS; i++) {
            Device *devices = myHome.devices[i];
            for (int j = 0; j < NUM_DEVICES; j++) {
                if (strcmp(devices[j].name, input) == 0) {
                    toggleDevice(&devices[j]);
                }
            }
        }
    }

    return 0;
}