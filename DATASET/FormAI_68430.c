//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Defining the structure of network device
struct network_device {
    char name[30];
    int speed;
    int reliability;
};

// Function to generate random device speed and reliability level
void generate_device(struct network_device *device) {
    int max_speed = 15;
    int max_reliability = 10;

    device->speed = rand() % max_speed + 1;
    device->reliability = rand() % max_reliability + 1;
}

// Function to display device information
void display_device(struct network_device device) {
    printf("%s (speed: %d, reliability: %d)\n", device.name, device.speed, device.reliability);
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random numbers

    // Defining the network devices and initializing their names
    struct network_device devices[5];
    strcpy(devices[0].name, "Gateway Router");
    strcpy(devices[1].name, "Firewall");
    strcpy(devices[2].name, "Load Balancer");
    strcpy(devices[3].name, "Switch");
    strcpy(devices[4].name, "Server");

    // Generating random device speed and reliability level
    for (int i=0; i<5; i++) {
        generate_device(&devices[i]);
    }

    // Displaying the initial network device information
    printf("Initial network device status:\n");
    for (int i=0; i<5; i++) {
        display_device(devices[i]);
    }
    printf("\n");

    // Checking the network quality of service (QoS) based on speed and reliability level
    printf("Checking network QoS:\n");
    for (int i=0; i<5; i++) {
        if (devices[i].speed < 5 || devices[i].reliability < 3) {
            printf("%s is causing network issues!\n", devices[i].name);
        }
    }

    return 0;
}