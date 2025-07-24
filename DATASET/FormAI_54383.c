//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the Network Topology Mapper program!\n");
    printf("This program is going to map your network and show you all the connected devices.\n");

    printf("Whoops! Seems like we don't have any devices connected to this network. Nothing to map here, folks!\n");
    printf("But don't worry, the program is still running!\n");

    char response[100];

    printf("Would you like to simulate some devices for the program to map? (Y/N)\n");
    scanf("%s", response);

    if (response[0] == 'Y' || response[0] == 'y') {
        printf("Great choice! Let's add some devices!\n");

        printf("How many devices would you like to simulate?\n");
        int num_devices;
        scanf("%d", &num_devices);

        printf("Creating %d devices...\n", num_devices);

        char device_names[num_devices][20];

        for (int i = 0; i < num_devices; i++) {
            printf("Enter name for device #%d: ", i+1);
            scanf("%s", device_names[i]);
            printf("Device %s created successfully!\n", device_names[i]);
        }

        printf("Now we need to connect the devices. This part can get messy, so brace for impact!\n");

        int device_connections[num_devices][num_devices];

        for (int i = 0; i < num_devices; i++) {
            for (int j = 0; j < num_devices; j++) {
                if (i == j) {
                    device_connections[i][j] = 0;
                } else {
                    printf("Is %s connected to %s? (Y/N)\n", device_names[i], device_names[j]);
                    scanf("%s", response);

                    if (response[0] == 'Y' || response[0] == 'y') {
                        device_connections[i][j] = 1;
                        printf("Connection between %s and %s established!\n", device_names[i], device_names[j]);
                    } else {
                        device_connections[i][j] = 0;
                    }
                }
            }
        }

        printf("All devices connected successfully! Now let's see the map:");

        for (int i = 0; i < num_devices; i++) {
            printf("%s: ", device_names[i]);

            for (int j = 0; j < num_devices; j++) {
                if (device_connections[i][j] == 1) {
                    printf("%s ", device_names[j]);
                }
            }
            printf("\n");
        }

    } else {
        printf("Maybe next time, then. Bye!\n");
    }

    return 0;
}