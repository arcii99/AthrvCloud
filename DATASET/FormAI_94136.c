//FormAI DATASET v1.0 Category: Smart home automation ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_DEVICE_NAME_LEN 20

typedef enum {
    OFF,
    ON
} State;

typedef struct {
    char name[MAX_DEVICE_NAME_LEN];
    State state;
} Device;

Device devices[MAX_DEVICES];
int num_devices = 0;

void add_device(char* name) {
    if (num_devices == MAX_DEVICES) {
        printf("Cannot add more devices\n");
        return;
    }
    Device new_device;
    strcpy(new_device.name, name);
    new_device.state = OFF;
    devices[num_devices] = new_device;
    num_devices++;
    printf("Device %s added successfully\n", name);
}

void remove_device(char* name) {
    int index = -1;
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Cannot find device %s\n", name);
        return;
    }
    for (int i = index; i < num_devices - 1; i++) {
        devices[i] = devices[i+1];
    }
    num_devices--;
    printf("Device %s removed successfully\n", name);
}

void print_devices() {
    for (int i = 0; i < num_devices; i++) {
        printf("%d. '%s' - %s\n", i+1, devices[i].name, (devices[i].state == ON) ? "ON" : "OFF");
    }
}

void switch_device(char* name, State state) {
    int index = -1;
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Cannot find device %s\n", name);
        return;
    }
    devices[index].state = state;
    printf("Device %s switched %s\n", name, (state == ON) ? "ON" : "OFF");
}

int main() {
    add_device("Light Bulb");
    add_device("Thermostat");
    add_device("TV");
    print_devices();
    switch_device("Light Bulb", ON);
    switch_device("Thermostat", ON);
    print_devices();
    remove_device("TV");
    print_devices();
    return 0;
}