//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 256
#define MAX_DEVICES 100

typedef struct Device {
    char name[MAX_STRING_LENGTH];
    char ip_address[MAX_STRING_LENGTH];
    char mac_address[MAX_STRING_LENGTH];
    struct Device *connections[MAX_DEVICES];
} Device;

int main() {
    Device devices[MAX_DEVICES];

    // Simulate devices and connections
    Device switch1 = {"Switch 1", "192.168.0.1", "", {}};
    Device switch2 = {"Switch 2", "192.168.0.2", "", {}};
    Device router1 = {"Router 1", "192.168.0.3", "", {}};
    Device pc1 = {"PC 1", "192.168.0.4", "11:22:33:44:55:66", {&switch1, &router1}};
    Device pc2 = {"PC 2", "192.168.0.5", "", {&switch2, &router1}};
    Device server1 = {"Server 1", "192.168.0.6", "AA:BB:CC:DD:EE:FF", {&switch1}};

    devices[0] = switch1;
    devices[1] = switch2;
    devices[2] = router1;
    devices[3] = pc1;
    devices[4] = pc2;
    devices[5] = server1;

    // Map network topology
    printf("Network Topology:\n");
    for (int i = 0; i < MAX_DEVICES; i++) {
        if (devices[i].name[0] != '\0') {
            printf("%s [%s]\n", devices[i].name, devices[i].ip_address);
            for (int j = 0; j < MAX_DEVICES; j++) {
                if (devices[i].connections[j] != NULL) {
                    printf("  --> %s [%s]\n", devices[i].connections[j]->name, devices[i].connections[j]->ip_address);
                }
            }
        }
    }

    return 0;
}