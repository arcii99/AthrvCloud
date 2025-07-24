//FormAI DATASET v1.0 Category: Smart home automation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Global Constants
#define MAX_DEVICES          50
#define MAX_DEVICE_NAME_LEN   20
#define MAX_DEVICE_TYPE_LEN   20

//Structure Definitions
typedef struct {
    char device_name[MAX_DEVICE_NAME_LEN];
    char device_type[MAX_DEVICE_TYPE_LEN];
    int status;
} device_t;

//Function Declarations
int read_input(char *input);
void initialize_devices(device_t *devices, int num_devices);
void print_devices(device_t *devices, int num_devices);
int get_device_index(char *device_name, device_t *devices, int num_devices);
void toggle_device(char *device_name, device_t *devices, int num_devices);
void update_device_status(char *device_name, int new_status, device_t *devices, int num_devices);

//Main Function
int main() {

    device_t devices[MAX_DEVICES];
    int num_devices = 3;

    //initialize devices
    initialize_devices(devices, num_devices);

    //print initial state of devices
    printf("Initial State of Devices:\n");
    print_devices(devices, num_devices);

    //read input from user
    char input[20];
    while(read_input(input)) {
        //parse input and act accordingly
        if(strcmp(input, "status") == 0) {
            print_devices(devices, num_devices);
        } else if(strncmp(input, "toggle ", 7) == 0) {
            //toggle device
            char device_name[MAX_DEVICE_NAME_LEN];
            sscanf(input, "toggle %s", device_name);
            toggle_device(device_name, devices, num_devices);
            print_devices(devices, num_devices);
        } else if(strncmp(input, "update ", 7) == 0) {
            //update device status
            char device_name[MAX_DEVICE_NAME_LEN];
            int new_status;
            sscanf(input, "update %s %d", device_name, &new_status);
            update_device_status(device_name, new_status, devices, num_devices);
            print_devices(devices, num_devices);
        } else {
            printf("Invalid command! Try again.\n");
        }
    }

    return 0;
}

//Function Definitions

//Reads input from user and removes trailing newline character
int read_input(char *input) {
    printf("Enter command: ");
    if(fgets(input, 20, stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        return 1;
    }
    return 0;
}

//Initializes the state of the devices
void initialize_devices(device_t *devices, int num_devices) {
    for(int i = 0; i < num_devices; i++) {
        if(i == 0) {
            strcpy(devices[i].device_name, "light");
            strcpy(devices[i].device_type, "switch");
            devices[i].status = 0;
        }
        else if(i == 1) {
            strcpy(devices[i].device_name, "fan");
            strcpy(devices[i].device_type, "switch");
            devices[i].status = 0;
        }
        else if(i == 2) {
            strcpy(devices[i].device_name, "temperature");
            strcpy(devices[i].device_type, "sensor");
            devices[i].status = 25;
        }
    }
}

//Prints the current state of devices
void print_devices(device_t *devices, int num_devices) {
    printf("Device Status:\n");
    printf("%-12s%-12s%s\n", "Device Name", "Device Type", "Status");
    for(int i = 0; i < num_devices; i++) {
        if(strcmp(devices[i].device_type, "switch") == 0) {
            printf("%-12s%-12s%s\n", devices[i].device_name, devices[i].device_type, devices[i].status ? "ON" : "OFF");
        } else {
            printf("%-12s%-12s%d\n", devices[i].device_name, devices[i].device_type, devices[i].status);
        }
    }
}

//Returns the index of the device
int get_device_index(char *device_name, device_t *devices, int num_devices) {
    for(int i = 0; i < num_devices; i++) {
        if(strcmp(devices[i].device_name, device_name) == 0) {
            return i;
        }
    }
    return -1;
}

//Toggles the state of switch device
void toggle_device(char *device_name, device_t *devices, int num_devices) {
    int idx = get_device_index(device_name, devices, num_devices);
    if(idx >= 0 && strcmp(devices[idx].device_type, "switch") == 0) {
        devices[idx].status = !devices[idx].status;
    }
}

//Updates the status of the device
void update_device_status(char *device_name, int new_status, device_t *devices, int num_devices) {
    int idx = get_device_index(device_name, devices, num_devices);
    if(idx >= 0) {
        devices[idx].status = new_status;
    }
}