//FormAI DATASET v1.0 Category: Smart home light control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROOMS 10
#define MAX_USERS 10

struct Room {
  char name[20];
  int num_lights;
  bool lights_on[10];
};

struct User {
  char name[20];
  int num_rooms;
  int rooms[10];
};

struct Room rooms[MAX_ROOMS] = {
  {"Living Room", 2, {false, false}},
  {"Kitchen", 3, {false, false, false}},
  {"Bedroom 1", 1, {false}},
  {"Bedroom 2", 1, {false}},
  {"Bathroom", 1, {false}},
  {"Office", 2, {false, false}},
};

struct User users[MAX_USERS];

void printRoomState(int roomIndex) {
  printf("%s Lights:\n", rooms[roomIndex].name);
  for (int i = 0; i < rooms[roomIndex].num_lights; i++) {
    printf("Light %d: %s\n", i + 1, rooms[roomIndex].lights_on[i] ? "On" : "Off");
  }
}

void toggleLight(int roomIndex, int lightIndex) {
  rooms[roomIndex].lights_on[lightIndex] = !rooms[roomIndex].lights_on[lightIndex];
  printRoomState(roomIndex);
}

void printUserRooms(int userIndex) {
  printf("%s Rooms:\n", users[userIndex].name);
  for (int i = 0; i < users[userIndex].num_rooms; i++) {
    printf("%d. %s\n", i + 1, rooms[users[userIndex].rooms[i]].name);
  }
}

int main() {
  // Initialize users
  users[0].num_rooms = 3;
  users[0].rooms[0] = 0; // Living Room
  users[0].rooms[1] = 1; // Kitchen
  users[0].rooms[2] = 5; // Office
  strcpy(users[0].name, "Alice");

  users[1].num_rooms = 2;
  users[1].rooms[0] = 2; // Bedroom 1
  users[1].rooms[1] = 4; // Bathroom
  strcpy(users[1].name, "Bob");

  // Main loop
  bool running = true;
  while (running) {
    printf("\n\n");
    printf("Welcome to Smart Home Light Control!\n");
    printf("\n");
    printf("1. View rooms\n");
    printf("2. Toggle light\n");
    printf("3. Exit\n");
    printf("\n");

    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: { // View rooms
        printf("\n");
        for (int i = 0; i < MAX_USERS; i++) {
          if (strlen(users[i].name) > 0) {
            printUserRooms(i);
            printf("\n");
          }
        }
        break;
      }
      case 2: { // Toggle light
        int userIndex;
        printf("Enter user index: ");
        scanf("%d", &userIndex);

        int roomIndex;
        printf("Enter room index: ");
        scanf("%d", &roomIndex);

        int lightIndex;
        printf("Enter light index: ");
        scanf("%d", &lightIndex);

        bool authorized = false;
        for (int i = 0; i < MAX_USERS; i++) {
          if (strcmp(users[i].name, users[userIndex].name) == 0) {
            for (int j = 0; j < users[i].num_rooms; j++) {
              if (users[i].rooms[j] == roomIndex) {
                authorized = true;
              }
            }
          }
        }

        if (authorized) {
          toggleLight(roomIndex, lightIndex);
        } else {
          printf("Error: You are not authorized to control that light.\n");
        }

        break;
      }
      case 3: { // Exit
        running = false;
        break;
      }
      default: {
        printf("Invalid choice. Please try again.\n");
        break;
      }
    }
  }

  return 0;
}