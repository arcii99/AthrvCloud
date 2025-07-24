//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXCOMMANDS 10
#define MAXLEN 20
#define MAXDRONES 5

struct Drone {
    int id;
    int battery; // 0 - 100% charged
    float x,y,z; //coordinates
};

void initialize(struct Drone* drones) {
    for(int i=0;i<MAXDRONES;i++) {
        drones[i].id = i+1;
        drones[i].battery = 100;
        drones[i].x = 0;
        drones[i].y = 0;
        drones[i].z = 0;
    }
}

int validateDroneId(int id) {
    if(id<1 || id>MAXDRONES) {
        printf("Invalid Drone ID. Please enter between 1 to %d\n",MAXDRONES);
        return 0;
    }
    return 1;
}

int validateCommand(char* command) {
    if(strcmp(command,"TAKEOFF")==0 || strcmp(command,"LAND")==0 ||
        strcmp(command,"UP")==0 || strcmp(command,"DOWN")==0 ||
        strcmp(command,"LEFT")==0 || strcmp(command,"RIGHT")==0 ||
        strcmp(command,"FORWARD")==0 || strcmp(command,"BACKWARD")==0) {
        return 1;
    }
    printf("Invalid Command. Please enter a valid command.\n");
    return 0;
}

void performCommand(struct Drone* drone, char* command, int value) {
    if(strcmp(command,"TAKEOFF")==0) {
        printf("Drone %d takes off\n",drone->id);
    } else if(strcmp(command,"LAND")==0) {
        printf("Drone %d lands\n",drone->id);
    } else if(strcmp(command,"UP")==0) {
        drone->z += value;
        printf("Drone %d moves up to height %0.2f metres\n",drone->id, drone->z);
    } else if(strcmp(command,"DOWN")==0) {
        if(drone->z-value < 0) {
            printf("Drone %d cannot go below surface level. Please re-enter a valid value.\n",drone->id);
            return;
        }
        drone->z -= value;
        printf("Drone %d moves down to height %0.2f metres\n",drone->id, drone->z);
    } else if(strcmp(command,"LEFT")==0) {
        drone->x -= value;
        printf("Drone %d moves left to coordinate X=%0.2f metres\n",drone->id, drone->x);
    } else if(strcmp(command,"RIGHT")==0) {
        drone->x += value;
        printf("Drone %d moves right to coordinate X=%0.2f metres\n",drone->id, drone->x);
    } else if(strcmp(command,"FORWARD")==0) {
        drone->y += value;
        printf("Drone %d moves forward to coordinate Y=%0.2f metres\n",drone->id, drone->y);
    } else if(strcmp(command,"BACKWARD")==0) {
        drone->y -= value;
        printf("Drone %d moves back to coordinate Y=%0.2f metres\n",drone->id, drone->y);
    }
    drone->battery -= 1;
    printf("Current battery level: %d%%\n",drone->battery);
}

int main() {
    struct Drone drones[MAXDRONES];
    char commands[MAXCOMMANDS][MAXLEN];
    int values[MAXCOMMANDS];
    int numCommands = 0;
    int selectedDrone;

    initialize(drones); // initialize drones with default values

    while(1) {
        printf("\nEnter Drone ID [1-%d]: ",MAXDRONES);
        scanf("%d",&selectedDrone);
        if(!validateDroneId(selectedDrone)) {
            continue;
        }
        printf("\nAvailable Commands: \n");
        printf("1. TAKEOFF\n");
        printf("2. LAND\n");
        printf("3. UP <value in metres>\n");
        printf("4. DOWN <value in metres>\n");
        printf("5. LEFT <value in metres>\n");
        printf("6. RIGHT <value in metres>\n");
        printf("7. FORWARD <value in metres>\n");
        printf("8. BACKWARD <value in metres>\n");
        printf("Enter commands: (Maximum %d commands allowed)\n",MAXCOMMANDS);
        numCommands = 0;
        while(numCommands<MAXCOMMANDS) {
            printf("%d. ",numCommands+1);
            scanf("%s",commands[numCommands]);
            if(strcmp(commands[numCommands],"END")==0) {
                break;
            }
            if(!validateCommand(commands[numCommands])) {
                continue;
            }
            scanf("%d",&values[numCommands]);
            numCommands++;
        }

        printf("\n\nExecuting Commands...\n");

        for(int i=0;i<numCommands;i++) {
            performCommand(&drones[selectedDrone-1],commands[i],values[i]);
        }
        printf("\n\nExecution Finished.\n\n");
    }

    return 0;
}