//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: safe
#include <stdio.h>

#define DRONEID_LEN 10

typedef struct drone_t {
  char droneid[DRONEID_LEN];
  int altitude;
  int x, y, z;
} Drone;

// Function prototype definitions
void printDroneStatus(Drone drone);
void climb(Drone* drone, int altitude);
void move(Drone* drone, int x, int y, int z);

int main(void) {
  Drone myDrone = {"1-A23B456C78", 0, 0, 0, 0}; // Initialize drone data
  
  printf("Drone Remote Control\n");
  printf("====================\n");
  printDroneStatus(myDrone); // Print drone status
  
  // Command the drone to climb to 1000ft
  printf("\nClimbing to 1000ft...\n");
  climb(&myDrone, 1000);
  printDroneStatus(myDrone); // Print drone status
  
  // Command the drone to move to 50, 75, 500ft
  printf("\nMoving to (50, 75, 500)...\n");
  move(&myDrone, 50, 75, 500);
  printDroneStatus(myDrone); // Print drone status
  
  return 0;
}

// Print drone status
void printDroneStatus(Drone drone) {
  printf("\nDrone status:\n");
  printf("ID: %s\n", drone.droneid);
  printf("Altitude: %dft\n", drone.altitude);
  printf("Location: (%d, %d, %d)\n", drone.x, drone.y, drone.z);
}

// Command the drone to climb to a specified altitude
void climb(Drone* drone, int altitude) {
  drone->altitude = altitude;
}

// Command the drone to move to a specified position
void move(Drone* drone, int x, int y, int z) {
  drone->x = x;
  drone->y = y;
  drone->z = z;
}