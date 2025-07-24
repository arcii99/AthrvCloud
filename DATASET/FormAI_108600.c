//FormAI DATASET v1.0 Category: Smart home automation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define MAX_DEVICE_NAME_LENGTH 20

/* Device struct to keep track of device information */
typedef struct {
    char name[MAX_DEVICE_NAME_LENGTH];
    int state;
} Device;

/* Smart home automation program */
int main(void)
{
    Device devices[MAX_DEVICES];
    int num_devices = 0;
    int i;
    char input[50];

    /* Main loop */
    while (1) {
        printf("Enter command (ADD, TURNON, TURNOFF, STATUS, or QUIT): ");
        fgets(input, 50, stdin);

        /* Remove newline character from input */
        input[strcspn(input, "\n")] = 0;

        /* ADD command */
        if (strcmp(input, "ADD") == 0) {
            /* Check if maximum number of devices already reached */
            if (num_devices == MAX_DEVICES) {
                printf("Maximum number of devices reached.\n");
            }
            else {
                printf("Enter device name: ");
                fgets(devices[num_devices].name, MAX_DEVICE_NAME_LENGTH, stdin);

                /* Remove newline character from device name */
                devices[num_devices].name[strcspn(devices[num_devices].name, "\n")] = 0;

                devices[num_devices].state = 0;
                num_devices++;
            }
        }
        /* TURNON command */
        else if (strcmp(input, "TURNON") == 0) {
            printf("Enter device name: ");
            fgets(input, MAX_DEVICE_NAME_LENGTH, stdin);

            /* Remove newline character from input */
            input[strcspn(input, "\n")] = 0;

            /* Find device with matching name */
            for (i = 0; i < num_devices; i++) {
                if (strcmp(devices[i].name, input) == 0) {
                    devices[i].state = 1;
                    printf("%s turned on.\n", devices[i].name);
                    break;
                }
            }

            /* Device not found */
            if (i == num_devices) {
                printf("Device not found.\n");
            }
        }
        /* TURNOFF command */
        else if (strcmp(input, "TURNOFF") == 0) {
            printf("Enter device name: ");
            fgets(input, MAX_DEVICE_NAME_LENGTH, stdin);

            /* Remove newline character from input */
            input[strcspn(input, "\n")] = 0;

            /* Find device with matching name */
            for (i = 0; i < num_devices; i++) {
                if (strcmp(devices[i].name, input) == 0) {
                    devices[i].state = 0;
                    printf("%s turned off.\n", devices[i].name);
                    break;
                }
            }

            /* Device not found */
            if (i == num_devices) {
                printf("Device not found.\n");
            }
        }
        /* STATUS command */
        else if (strcmp(input, "STATUS") == 0) {
            for (i = 0; i < num_devices; i++) {
                printf("%s is %s.\n", devices[i].name, devices[i].state ? "on" : "off");
            }
        }
        /* QUIT command */
        else if (strcmp(input, "QUIT") == 0) {
            break;
        }
        /* Invalid command */
        else {
            printf("Invalid command.\n");
        }

        /* Delay before next input */
        sleep(1);
    }

    return 0;
}