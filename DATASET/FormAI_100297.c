//FormAI DATASET v1.0 Category: Smart home automation ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

/* Smart Home Automation System */

// Define constants
#define LIVING_ROOM 0
#define KITCHEN 1
#define BEDROOM 2
#define BATHROOM 3
#define GARAGE 4

// Define structure of each room
struct Room {
  char name[20];
  bool lightOn;
  bool fanOn;
  bool ACOn;
  int temperature;
};

// Define function prototypes
void initRooms(struct Room rooms[]);
void displayInfo(struct Room rooms[]);
void toggleLight(struct Room rooms[], int roomNum);
void toggleFan(struct Room rooms[], int roomNum);
void toggleAC(struct Room rooms[], int roomNum);
void setTemperature(struct Room rooms[], int roomNum);
void simulateMotion(struct Room rooms[], int roomNum);

int main() {
  // Initialize random seed for simulation
  srand(time(NULL));
  
  // Initialize all rooms with default values
  struct Room rooms[5];
  initRooms(rooms);
  
  // Display current status of all rooms
  printf("===== Smart Home Automation System =====\n");
  displayInfo(rooms);
  
  // Take user input to control the home appliances
  printf("\nWhat do you want to do?\n");
  printf("1. Turn on/off lights\n");
  printf("2. Turn on/off fans\n");
  printf("3. Turn on/off ACs\n");
  printf("4. Set temperature for an AC\n");
  printf("5. Simulate motion in a room\n");
  printf("6. Exit\n");
  int choice;
  scanf("%d", &choice);
  
  // Continue until user chooses to exit
  while (choice != 6) {
    int roomNum;
    switch (choice) {
      case 1:
        printf("\nWhich room do you want to turn on/off the lights?\n");
        printf("0. Living Room\n");
        printf("1. Kitchen\n");
        printf("2. Bed Room\n");
        printf("3. Bathroom\n");
        printf("4. Garage\n");
        scanf("%d", &roomNum);
        toggleLight(rooms, roomNum);
        break;
      case 2:
        printf("\nWhich room do you want to turn on/off the fan?\n");
        printf("0. Living Room\n");
        printf("1. Kitchen\n");
        printf("2. Bed Room\n");
        printf("3. Bathroom\n");
        printf("4. Garage\n");
        scanf("%d", &roomNum);
        toggleFan(rooms, roomNum);
        break;
      case 3:
        printf("\nWhich room do you want to turn on/off the AC?\n");
        printf("0. Living Room\n");
        printf("1. Kitchen\n");
        printf("2. Bed Room\n");
        printf("3. Bathroom\n");
        printf("4. Garage\n");
        scanf("%d", &roomNum);
        toggleAC(rooms, roomNum);
        break;
      case 4:
        printf("\nWhich room do you want to set the temperature for?\n");
        printf("0. Living Room\n");
        printf("1. Kitchen\n");
        printf("2. Bed Room\n");
        printf("3. Bathroom\n");
        printf("4. Garage\n");
        scanf("%d", &roomNum);
        setTemperature(rooms, roomNum);
        break;
      case 5:
        printf("\nWhich room do you want to simulate motion in?\n");
        printf("0. Living Room\n");
        printf("1. Kitchen\n");
        printf("2. Bed Room\n");
        printf("3. Bathroom\n");
        printf("4. Garage\n");
        scanf("%d", &roomNum);
        simulateMotion(rooms, roomNum);
        break;
      default:
        printf("Invalid choice, try again!\n");
        break;
    }
    // Display updated status of all rooms
    displayInfo(rooms);
    // Take user input for next operation
    printf("\nWhat do you want to do?\n");
    printf("1. Turn on/off lights\n");
    printf("2. Turn on/off fans\n");
    printf("3. Turn on/off ACs\n");
    printf("4. Set temperature for an AC\n");
    printf("5. Simulate motion in a room\n");
    printf("6. Exit\n");
    scanf("%d", &choice);
  }
  return 0;
}

// Initialize all rooms with default values
void initRooms(struct Room rooms[]) {
  strcpy(rooms[LIVING_ROOM].name, "Living Room");
  rooms[LIVING_ROOM].lightOn = false;
  rooms[LIVING_ROOM].fanOn = false;
  rooms[LIVING_ROOM].ACOn = false;
  rooms[LIVING_ROOM].temperature = 0;
  
  strcpy(rooms[KITCHEN].name, "Kitchen");
  rooms[KITCHEN].lightOn = false;
  rooms[KITCHEN].fanOn = false;
  rooms[KITCHEN].ACOn = false;
  rooms[KITCHEN].temperature = 0;
  
  strcpy(rooms[BEDROOM].name, "Bed Room");
  rooms[BEDROOM].lightOn = false;
  rooms[BEDROOM].fanOn = false;
  rooms[BEDROOM].ACOn = false;
  rooms[BEDROOM].temperature = 0;
  
  strcpy(rooms[BATHROOM].name, "Bathroom");
  rooms[BATHROOM].lightOn = false;
  rooms[BATHROOM].fanOn = false;
  rooms[BATHROOM].ACOn = false;
  rooms[BATHROOM].temperature = 0;
  
  strcpy(rooms[GARAGE].name, "Garage");
  rooms[GARAGE].lightOn = false;
  rooms[GARAGE].fanOn = false;
  rooms[GARAGE].ACOn = false;
  rooms[GARAGE].temperature = 0;
}

// Display current status of all rooms
void displayInfo(struct Room rooms[]) {
  printf("\n====== Home Appliances Status ======\n");
  for (int i = 0; i < 5; i++) {
    printf("%s\n", rooms[i].name);
    printf("Light: %s\n", rooms[i].lightOn ? "On" : "Off");
    printf("Fan: %s\n", rooms[i].fanOn ? "On" : "Off");
    printf("AC: %s\n", rooms[i].ACOn ? "On" : "Off");
    if (rooms[i].ACOn) {
      printf("Temperature: %dC\n", rooms[i].temperature);
    }
    printf("-------------------------\n");
  }
}

// Turn on/off the lights in a room
void toggleLight(struct Room rooms[], int roomNum) {
  if (rooms[roomNum].lightOn) {
    rooms[roomNum].lightOn = false;
  } else {
    rooms[roomNum].lightOn = true;
  }
}

// Turn on/off the fan in a room
void toggleFan(struct Room rooms[], int roomNum) {
  if (rooms[roomNum].fanOn) {
    rooms[roomNum].fanOn = false;
  } else {
    rooms[roomNum].fanOn = true;
  }
}

// Turn on/off the AC in a room
void toggleAC(struct Room rooms[], int roomNum) {
  if (rooms[roomNum].ACOn) {
    rooms[roomNum].ACOn = false;
    rooms[roomNum].temperature = 0;
  } else {
    rooms[roomNum].ACOn = true;
    rooms[roomNum].temperature = 25;
  }
}

// Set temperature for an AC
void setTemperature(struct Room rooms[], int roomNum) {
  if (!rooms[roomNum].ACOn) {
    printf("AC is not turned on in this room!\n");
    return;
  }
  int temp;
  printf("Enter temperature (in Celsius): ");
  scanf("%d", &temp);
  rooms[roomNum].temperature = temp;
}

// Simulate motion in a room
void simulateMotion(struct Room rooms[], int roomNum) {
  printf("Simulating motion in %s...\n", rooms[roomNum].name);
  rooms[roomNum].lightOn = true;
  rooms[roomNum].fanOn = true;
  rooms[roomNum].ACOn = true;
  rooms[roomNum].temperature = rand() % 15 + 16;
  printf("Motion simulation completed!\n");
}