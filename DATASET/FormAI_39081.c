//FormAI DATASET v1.0 Category: System boot optimizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int bootTime = 0, numServices = 0, numPrograms = 0;
    float bootSpeed = 0.0;

    printf("Welcome to the C System boot optimizer program!\n\n");

    // Obtain user input for boot time
    printf("Please enter the current boot time (in seconds): ");
    scanf("%d", &bootTime);

    // Obtain user input for number of services running during boot
    printf("Please enter the number of services running during boot: ");
    scanf("%d", &numServices);

    // Obtain user input for number of programs running during boot
    printf("Please enter the number of programs running during boot: ");
    scanf("%d", &numPrograms);

    // Calculate boot speed based on user inputs
    bootSpeed = (numServices + numPrograms) / (float)bootTime;

    printf("\nBased on your inputs, your current boot speed is: %.2f programs/services per second\n\n", bootSpeed);

    // Offer suggestions to optimize boot time based on boot speed
    if (bootSpeed >= 2.0) {
        printf("Here are some suggestions to optimize your boot time:\n");
        printf("- Disable unnecessary programs and services from starting during boot\n");
        printf("- Use a solid-state drive (SSD) instead of a traditional hard drive for faster read/write times\n");
    }
    else if (bootSpeed >= 1.0) {
        printf("Here are some suggestions to improve your boot time:\n");
        printf("- Disable unnecessary programs and services from starting during boot\n");
        printf("- Consider upgrading to an SSD to further improve boot speed\n");
    }
    else {
        printf("Your boot speed is already quite optimized! Here are some tips to maintain optimal performance:\n");
        printf("- Perform regular maintenance, such as disk cleanup and defragmentation\n");
        printf("- Keep your system up-to-date with the latest drivers and security patches\n");
    }

    return 0;
}