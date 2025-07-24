//FormAI DATASET v1.0 Category: Smart home automation ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_DEVICES 10

typedef struct {
    char name[20];
    int status;
} Device;

int main() {

    Device devices[MAX_DEVICES];
    int device_count = 0;

    while(1) {
        printf("Enter a device name (or type 'exit' to end): ");
        char input[20];
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        if(strcmp(input, "exit") == 0) {
            break;
        }

        // Check if device already exists
        int found = 0;
        for(int i = 0; i < device_count; i++) {
            if(strcmp(devices[i].name, input) == 0) {
                printf("Device already exists.\n");
                found = 1;
                break;
            }
        }

        if(!found) {
            // Add new device
            Device new_device;
            strcpy(new_device.name, input);
            new_device.status = 0;
            devices[device_count] = new_device;
            device_count++;

            printf("Device added.\n");
        }
    }

    // Device shapeshifting
    int choice;
    do {
        printf("Select a device to shapeshift (0 to exit):\n");
        for(int i = 0; i < device_count; i++) {
            printf("%d. %s\n", i+1, devices[i].name);
        }
        scanf("%d", &choice);
        getchar(); // Remove newline character from input buffer

        if(choice < 1 || choice > device_count) {
            printf("Invalid choice.\n");
            continue;
        }

        Device* device = &devices[choice-1];

        printf("What would you like to change?\n");
        printf("1. Name\n");
        printf("2. Status\n");
        printf("3. Both\n");

        scanf("%d", &choice);
        getchar(); // Remove newline character from input buffer

        switch(choice) {
            case 1:
                printf("Enter new device name: ");
                char new_name[20];
                fgets(new_name, 20, stdin);
                new_name[strcspn(new_name, "\n")] = '\0'; // Remove newline character
                strcpy(device->name, new_name);
                printf("Device name updated.\n");
                break;
            case 2:
                printf("Enter new device status (0 for off, 1 for on): ");
                int new_status;
                scanf("%d", &new_status);
                getchar(); // Remove newline character from input buffer
                device->status = new_status;
                printf("Device status updated.\n");
                break;
            case 3:
                printf("Enter new device name: ");
                char new_name_both[20];
                fgets(new_name_both, 20, stdin);
                new_name_both[strcspn(new_name_both, "\n")] = '\0'; // Remove newline character
                strcpy(device->name, new_name_both);

                printf("Enter new device status (0 for off, 1 for on): ");
                int new_status_both;
                scanf("%d", &new_status_both);
                getchar(); // Remove newline character from input buffer
                device->status = new_status_both;

                printf("Device name and status updated.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

    } while(choice != 0);

    printf("Goodbye!\n");

    return 0;
}