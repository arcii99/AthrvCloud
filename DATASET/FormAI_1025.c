//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Shape-shifting network topology mapper program

typedef enum {
    NODE,
    HUB,
    SWITCH,
    ROUTER,
} device_t;

typedef struct {
    char name[20];
    device_t type;
    int num_ports;
    int *link_ids;
} device_info_t;

typedef struct {
    int id;
    char name[20];
} link_t;

typedef struct {
    device_info_t *devices;
    int num_devices;
    link_t *links;
    int num_links;
} topology_t;

void print_topology(topology_t *topo)
{
    int i, j;
    device_info_t *device;
    link_t *link;

    printf("Topology:\n");

    for (i = 0; i < topo->num_devices; i++)
    {
        device = &topo->devices[i];

        printf("- Device: %s (%s)\n", device->name, device->type == NODE ? "NODE" :
                                      device->type == HUB ? "HUB" :
                                          device->type == SWITCH ? "SWITCH" :
                                              device->type == ROUTER ? "ROUTER" : "UNKNOWN");

        for (j = 0; j < device->num_ports; j++)
        {
            if (device->link_ids[j] != -1)
            {
                link = &topo->links[device->link_ids[j]];

                printf("  - Port %d: %s\n", j + 1, link->name);
            }
            else
            {
                printf("  - Port %d: UNUSED\n", j + 1);
            }
        }
    }

    printf("\n");
}

int main()
{
    topology_t topology = {0};
    int i, j;
    device_info_t device;
    link_t link;

    // Create devices
    device_info_t devices[] = {
        {"Node 1", NODE, 1, (int []){-1}},
        {"Hub 1", HUB, 8, (int []){-1, -1, -1, -1, -1, -1, -1, -1}},
        {"Switch 1", SWITCH, 24, (int []){-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                                         -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                                         -1, -1, -1, -1}},
        {"Router 1", ROUTER, 2, (int []){-1, -1}},
        {"Node 2", NODE, 1, (int []){-1}},
    };
    topology.devices = devices;
    topology.num_devices = sizeof(devices) / sizeof(devices[0]);

    // Create links
    link_t links[] = {
        {0, "Link 1"},
        {1, "Link 2"},
        {2, "Link 3"},
        {3, "Link 4"},
        {4, "Link 5"},
        {5, "Link 6"},
        {6, "Link 7"},
        {7, "Link 8"},
        {8, "Link 9"},
        {9, "Link 10"},
        {10, "Link 11"},
        {11, "Link 12"},
        {12, "Link 13"},
        {13, "Link 14"},
        {14, "Link 15"},
        {15, "Link 16"},
        {16, "Link 17"},
        {17, "Link 18"},
        {18, "Link 19"},
        {19, "Link 20"},
        {20, "Link 21"},
        {21, "Link 22"},
        {22, "Link 23"},
        {23, "Link 24"}
    };
    topology.links = links;
    topology.num_links = sizeof(links) / sizeof(links[0]);

    // Connect devices
    topology.devices[0].link_ids[0] = 0;         // Node 1 - Link 1
    topology.devices[1].link_ids[0] = 0;         // Hub 1 - Link 1
    topology.devices[1].link_ids[1] = 1;         // Hub 1 - Link 2
    topology.devices[1].link_ids[2] = 2;         // Hub 1 - Link 3
    topology.devices[1].link_ids[3] = 3;         // Hub 1 - Link 4
    topology.devices[1].link_ids[4] = 4;         // Hub 1 - Link 5
    topology.devices[1].link_ids[5] = 5;         // Hub 1 - Link 6
    topology.devices[1].link_ids[6] = 6;         // Hub 1 - Link 7
    topology.devices[1].link_ids[7] = 7;         // Hub 1 - Link 8
    topology.devices[2].link_ids[0] = 8;         // Switch 1 - Link 9
    topology.devices[2].link_ids[1] = 9;         // Switch 1 - Link 10
    topology.devices[2].link_ids[2] = 10;        // Switch 1 - Link 11
    topology.devices[2].link_ids[3] = 11;        // Switch 1 - Link 12
    topology.devices[2].link_ids[4] = 12;        // Switch 1 - Link 13
    topology.devices[2].link_ids[5] = 13;        // Switch 1 - Link 14
    topology.devices[2].link_ids[6] = 14;        // Switch 1 - Link 15
    topology.devices[2].link_ids[7] = 15;        // Switch 1 - Link 16
    topology.devices[2].link_ids[8] = 16;        // Switch 1 - Link 17
    topology.devices[2].link_ids[9] = 17;        // Switch 1 - Link 18
    topology.devices[2].link_ids[10] = 18;       // Switch 1 - Link 19
    topology.devices[2].link_ids[11] = 19;       // Switch 1 - Link 20
    topology.devices[2].link_ids[12] = 20;       // Switch 1 - Link 21
    topology.devices[2].link_ids[13] = 21;       // Switch 1 - Link 22
    topology.devices[2].link_ids[14] = 22;       // Switch 1 - Link 23
    topology.devices[2].link_ids[15] = 23;       // Switch 1 - Link 24
    topology.devices[3].link_ids[0] = 2;         // Router 1 - Link 3
    topology.devices[3].link_ids[1] = 8;         // Router 1 - Link 9
    topology.devices[4].link_ids[0] = 16;        // Node 2 - Link 17

    // Print topology
    print_topology(&topology);

    return 0;
}