//FormAI DATASET v1.0 Category: System boot optimizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

struct boot {
    int time_taken_to_boot;
    int number_of_processes_running;
    int ram_usage;
};

void optimize_boot(struct boot *device) {
    // The optimizer function takes in a pointer to the 'boot' struct and optimizes the device's boot process
    if (device->time_taken_to_boot > 30) {
        device->time_taken_to_boot -= 20;
    } else {
        device->time_taken_to_boot -= 10;
    }

    if (device->number_of_processes_running > 20) {
        device->number_of_processes_running -= 10;
    } else {
        device->number_of_processes_running -= 5;
    }

    if (device->ram_usage > 70) {
        device->ram_usage -= 20;
    } else {
        device->ram_usage -= 10;
    }
}

int main() {
    // Creating a new boot struct
    struct boot my_device = {40, 30, 80};

    printf("Before optimization:\n");
    printf("Time taken to boot: %d seconds\n", my_device.time_taken_to_boot);
    printf("Number of processes running: %d\n", my_device.number_of_processes_running);
    printf("RAM usage: %d%%\n", my_device.ram_usage);

    // Optimizing the boot process
    optimize_boot(&my_device);

    printf("\nAfter optimization:\n");
    printf("Time taken to boot: %d seconds\n", my_device.time_taken_to_boot);
    printf("Number of processes running: %d\n", my_device.number_of_processes_running);
    printf("RAM usage: %d%%\n", my_device.ram_usage);

    return 0;
}