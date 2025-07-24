//FormAI DATASET v1.0 Category: Hotel Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the structure of a hotel guest
typedef struct hotelGuest {
    char name[50];
    int roomNumber;
    int numNights;
} HotelGuest;

// Defining the structure of a hotel room
typedef struct hotelRoom {
    int roomNumber;
    char status[10];
} HotelRoom;

// Returns the index of a room in the room list given a room number
int findRoom(HotelRoom roomList[], int numRooms, int roomNumber) {
  int i;
  for (i=0; i < numRooms; i++) {
    if (roomList[i].roomNumber == roomNumber) {
      return i;
    }
  }
  // Return -1 if the room was not found
  return -1;
}

int main() {
    // Defining the variables
    int numRooms, numGuests, i, j, option, roomNum;
    float totalRevenue = 0;
    
    printf("Welcome to the C Hotel Management System!\n\n");

    // Prompting the user for the number of rooms in the hotel
    printf("Enter the number of rooms in the hotel: ");
    scanf("%d", &numRooms);

    // Prompting the user for the number of guests in the hotel
    printf("Enter the number of guests in the hotel: ");
    scanf("%d", &numGuests);

    // Initializing the room list and guest list
    HotelRoom roomList[numRooms];
    HotelGuest guestList[numGuests];

    // Initializing the room list
    for (i = 0; i < numRooms; i++) {
        roomList[i].roomNumber = i + 1;
        strcpy(roomList[i].status, "Available");
    }

    // Initializing the guest list
    for (i = 0; i < numGuests; i++) {
        printf("Enter the name of guest %d: ", i + 1);
        scanf("%s", guestList[i].name);

        printf("Enter the room number for guest %d: ", i + 1);
        scanf("%d", &guestList[i].roomNumber);

        printf("Enter the number of nights for guest %d: ", i + 1);
        scanf("%d", &guestList[i].numNights);

        // Marking the room as unavailable
        roomNum = guestList[i].roomNumber;
        j = findRoom(roomList, numRooms, roomNum);
        strcpy(roomList[j].status, "Unavailable");
    }

    // Menu
    do {
        printf("\n\nMenu\n");
        printf("1. Display room status\n");
        printf("2. Calculate total revenue\n");
        printf("3. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nRoom Status\n");
                printf("------------\n");
                printf("Room Number    Status\n");
                printf("--------------------\n");

                // Displaying the status of each room
                for (i = 0; i < numRooms; i++) {
                    printf("       %d           %s\n", roomList[i].roomNumber, roomList[i].status);
                }
                break;

            case 2:
                // Calculating the total revenue
                for (i = 0; i < numGuests; i++) {
                    totalRevenue += (float)guestList[i].numNights * 100;
                }
                printf("\nTotal Revenue: $%0.2f\n", totalRevenue);
                break;

            case 3:
                printf("\nThank you for using the C Hotel Management System!");
                break;

            default:
                printf("\nInvalid option. Please try again!");
                break;
        }
    } while (option != 3);

    return 0;
}