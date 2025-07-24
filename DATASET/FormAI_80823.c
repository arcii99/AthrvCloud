//FormAI DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>

/* define the available rooms */
#define LIVING_ROOM 1
#define KITCHEN 2
#define BEDROOM 3

/* define the available appliances */
#define LIGHTS 1
#define THERMOSTAT 2
#define LOCKS 3

/* define maximum number of rooms and appliances */
#define MAX_ROOMS 10
#define MAX_APPLIANCES 10

/* data structure to hold room information */
typedef struct {
    int roomId;
    char roomName[20];
    int numAppliances;
    int appliances[MAX_APPLIANCES];
} Room;

/* data structure to hold appliance information */
typedef struct {
    int applianceId;
    char applianceName[20];
    int status;
} Appliance;

/* define the available actions */
#define TURN_ON 1
#define TURN_OFF 2

int main() {
    /* initialize the rooms */
    Room rooms[MAX_ROOMS];
    int numRooms = 3;

    rooms[0].roomId = LIVING_ROOM;
    strcpy(rooms[0].roomName, "Living Room");
    rooms[0].numAppliances = 2;
    rooms[0].appliances[0] = LIGHTS;
    rooms[0].appliances[1] = THERMOSTAT;

    rooms[1].roomId = KITCHEN;
    strcpy(rooms[1].roomName, "Kitchen");
    rooms[1].numAppliances = 1;
    rooms[1].appliances[0] = LIGHTS;

    rooms[2].roomId = BEDROOM;
    strcpy(rooms[2].roomName, "Bedroom");
    rooms[2].numAppliances = 2;
    rooms[2].appliances[0] = LIGHTS;
    rooms[2].appliances[1] = LOCKS;

    /* initialize the appliances */
    Appliance appliances[MAX_APPLIANCES];
    int numAppliances = 3;

    appliances[0].applianceId = LIGHTS;
    strcpy(appliances[0].applianceName, "Lights");
    appliances[0].status = TURN_OFF;

    appliances[1].applianceId = THERMOSTAT;
    strcpy(appliances[1].applianceName, "Thermostat");
    appliances[1].status = TURN_OFF;

    appliances[2].applianceId = LOCKS;
    strcpy(appliances[2].applianceName, "Locks");
    appliances[2].status = TURN_ON;

    /* start the home automation loop */
    char input[20];

    while (1) {
        printf("Enter room name: ");
        scanf("%s", input);

        /* find the room based on name */
        int roomId = -1;
        for (int i = 0; i < numRooms; i++) {
            if (strcmp(rooms[i].roomName, input) == 0) {
                roomId = rooms[i].roomId;
                break;
            }
        }

        if (roomId == -1) {
            printf("Error: Invalid room name\n");
            continue;
        }

        printf("Enter appliance name: ");
        scanf("%s", input);

        /* find the appliance based on name */
        int applianceId = -1;
        for (int i = 0; i < numAppliances; i++) {
            if (strcmp(appliances[i].applianceName, input) == 0) {
                applianceId = appliances[i].applianceId;
                break;
            }
        }

        if (applianceId == -1) {
            printf("Error: Invalid appliance name\n");
            continue;
        }

        printf("Enter action (1- turn on, 2- turn off): ");
        int action;
        scanf("%d", &action);

        if (action != TURN_ON && action != TURN_OFF) {
            printf("Error: Invalid action\n");
            continue;
        }

        /* update the appliance status */
        for (int i = 0; i < numRooms; i++) {
            if (rooms[i].roomId == roomId) {
                for (int j = 0; j < rooms[i].numAppliances; j++) {
                    if (rooms[i].appliances[j] == applianceId) {
                        appliances[applianceId-1].status = action;
                        printf("%s in %s has been turned %s\n", appliances[applianceId-1].applianceName, rooms[i].roomName, action == TURN_ON ? "on" : "off");
                        break;
                    }
                }
                break;
            }
        }
    }

    return 0;
}