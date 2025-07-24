//FormAI DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_NAME 50
#define MAX_STAYS 365

struct Room {
   int roomNumber;
   int capacity;
   int reserved;
   char guestName[MAX_NAME];
   int guestStay[MAX_STAYS];
};

// Function prototypes
void printRooms(struct Room[], int);
int reserveRoom(struct Room[], int, int, char[], int);
void releaseRoom(struct Room[], int, int);
void printMenu();

int main() {
   // Initialize all rooms
   struct Room rooms[MAX_ROOMS];
   for (int i = 0; i < MAX_ROOMS; ++i) {
      rooms[i].roomNumber = i + 1;
      rooms[i].capacity = rand() % 4 + 1;
      rooms[i].reserved = 0;
      rooms[i].guestName[0] = '\0';
      for (int j = 0; j < MAX_STAYS; ++j) {
         rooms[i].guestStay[j] = 0;
      }
   }

   int choice = -1;
   while (choice != 4) {
      printMenu();
      printf("> ");
      scanf("%d", &choice);

      switch (choice) {
         case 1: // Reserve a room
            printf("Enter room number (1 - %d): ", MAX_ROOMS);
            int roomNum;
            scanf("%d", &roomNum);

            if (roomNum < 1 || roomNum > MAX_ROOMS) {
               printf("Invalid room number\n");
               break;
            }

            if (rooms[roomNum - 1].reserved == 1) {
               printf("Room is already reserved\n");
               break;
            }

            printf("Enter guest name: ");
            char guestName[MAX_NAME];
            scanf("%s", guestName);

            printf("Enter length of stay (1 - %d): ", MAX_STAYS);
            int stayLength;
            scanf("%d", &stayLength);

            int result = reserveRoom(rooms, MAX_ROOMS, roomNum, guestName, stayLength);
            if (result == -1) {
               printf("Room is not available for that length of stay\n");
            }
            else {
               printf("Room %d has been reserved for %s for %d days\n", roomNum, guestName, stayLength);
            }

            break;
         case 2: // Release a room
            printf("Enter room number (1 - %d): ", MAX_ROOMS);
            int relRoomNum;
            scanf("%d", &relRoomNum);

            if (relRoomNum < 1 || relRoomNum > MAX_ROOMS || rooms[relRoomNum - 1].reserved == 0) {
               printf("That room is not currently reserved\n");
               break;
            }

            releaseRoom(rooms, MAX_ROOMS, relRoomNum);
            printf("Room %d has been released\n", relRoomNum);

            break;
         case 3: // Print all rooms
            printRooms(rooms, MAX_ROOMS);
            break;
         case 4: // Quit
            printf("Goodbye!\n");
            break;
         default: // Invalid choice
            printf("Invalid choice, please try again\n");
      }
   }

   return 0;
}

// Prints out all of the rooms
void printRooms(struct Room rooms[], int numRooms) {
   printf("Room #\tCapacity\tGuest name\tStays\n");
   printf("-----\t--------\t----------\t-----\n");
   for (int i = 0; i < numRooms; ++i) {
      printf("%d\t%d\t\t", rooms[i].roomNumber, rooms[i].capacity);

      if (rooms[i].reserved == 1) {
         printf("%s\t\t", rooms[i].guestName);

         for (int j = 0; j < MAX_STAYS; ++j) {
            if (rooms[i].guestStay[j] == 1) {
               printf("%d ", j + 1);
            }
         }
      }
      printf("\n");
   }
   printf("\n");
}

// Reserves a room for a guest for a certain length of stay
// Returns -1 if the room is not available for that length of stay
int reserveRoom(struct Room rooms[], int numRooms, int roomNum, char guestName[], int stayLength) {
   int roomIndex = roomNum - 1;

   // Check if the room is currently available
   for (int i = 0; i < MAX_STAYS - stayLength; ++i) {
      int available = 1;
      for (int j = i; j < i + stayLength; ++j) {
         if (rooms[roomIndex].guestStay[j] == 1) {
            available = 0;
            break;
         }
      }

      if (available == 1) {
         // Reserve the room
         rooms[roomIndex].reserved = 1;
         strcpy(rooms[roomIndex].guestName, guestName);
         for (int j = i; j < i + stayLength; ++j) {
            rooms[roomIndex].guestStay[j] = 1;
         }

         return 0;
      }
   }

   // Room is not available for that length of stay
   return -1;
}

// Releases a room and clears all guest data
void releaseRoom(struct Room rooms[], int numRooms, int roomNum) {
   int roomIndex = roomNum - 1;

   // Clear all guest data
   rooms[roomIndex].reserved = 0;
   rooms[roomIndex].guestName[0] = '\0';
   for (int i = 0; i < MAX_STAYS; ++i) {
      rooms[roomIndex].guestStay[i] = 0;
   }
}

// Prints the main menu
void printMenu() {
   printf("1. Reserve a room\n");
   printf("2. Release a room\n");
   printf("3. View all rooms\n");
   printf("4. Quit\n");
}