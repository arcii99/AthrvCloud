//FormAI DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numRooms = 10;  // Set number of rooms available
int numBooked = 0; // Initialize number of booked rooms
float rate = 100.00; // Set nightly rate of rooms

// Define structure for Room
typedef struct {
  int roomNum;
  int booked;
  char guestName[50];
  float bill;
} Room;

Room hotelRooms[10]; // Create an array of Rooms

void initializeRooms() {
  // Initialize all rooms to empty
  for (int i = 0; i < numRooms; i++) {
    hotelRooms[i].roomNum = i + 101;
    hotelRooms[i].booked = 0;
    hotelRooms[i].bill = 0.00;
    strcpy(hotelRooms[i].guestName, "");
  }
}

void addGuest() {
  printf("Enter room number: ");
  int roomNum;
  scanf("%d", &roomNum);

  // Check if room is available
  if (hotelRooms[roomNum - 101].booked == 0) {
    hotelRooms[roomNum - 101].roomNum = roomNum;
    getchar();
    printf("Enter guest name: ");
    fgets(hotelRooms[roomNum - 101].guestName, sizeof(hotelRooms[roomNum - 101].guestName), stdin);
    hotelRooms[roomNum - 101].booked = 1;
    numBooked++;
    printf("Guest added successfully!\n");
  } else {
    printf("Room is already booked.\n");
  }
}

void printBill() {
  printf("Enter room number: ");
  int roomNum;
  scanf("%d", &roomNum);

  // Check if room is booked
  if (hotelRooms[roomNum - 101].booked == 1) {
    printf("Guest Name: %s\n", hotelRooms[roomNum - 101].guestName);
    printf("Room Number: %d\n", hotelRooms[roomNum - 101].roomNum );
    printf("Total Bill: %.2f\n", hotelRooms[roomNum - 101].bill);
  } else {
    printf("Room is not yet booked.\n");
  }
}

void checkout() {
  printf("Enter room number: ");
  int roomNum;
  scanf("%d", &roomNum);

  // Check if room is booked
  if (hotelRooms[roomNum - 101].booked == 1) {
    hotelRooms[roomNum - 101].booked = 0;
    numBooked--;
    float bill = rate * 1.1; // Calculate bill with 10% tax
    hotelRooms[roomNum - 101].bill = bill;
    printf("Checkout complete. Total bill is %.2f\n", bill);
  } else {
    printf("Room is not yet booked.\n");
  }
}

void printOccupancy() {
  printf("Number of rooms booked: %d\n", numBooked);
  printf("Number of rooms available: %d\n", (numRooms - numBooked));
}

int main() {
  initializeRooms();
  int choice;
  do {
    printf("\n");
    printf("1. Add Guest\n");
    printf("2. Print Bill\n");
    printf("3. Check Out\n");
    printf("4. Print Occupancy\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1: addGuest();
        break;
      case 2: printBill();
        break;
      case 3: checkout();
        break;
      case 4: printOccupancy();
        break;
      case 0: exit(0);
      default: printf("Invalid Choice.\n");
    }
  } while(choice != 0);

  return 0;
}