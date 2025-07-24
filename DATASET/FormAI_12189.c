//FormAI DATASET v1.0 Category: Hotel Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
   int roomNumber;
   char guestName[MAX_NAME_LENGTH]; 
   float roomRate;
   int numberOfNights; 
} Room;

Room hotelRooms[MAX_ROOMS];
int numRooms = 0;

void addRoom(int roomNumber, char *guestName, float roomRate, int numberOfNights) {
   if(numRooms == MAX_ROOMS) {
      printf("\n Hotel is full. Cannot add any more rooms.");
      return;
   }
   Room newRoom;
   newRoom.roomNumber = roomNumber;
   strcpy(newRoom.guestName, guestName);
   newRoom.roomRate = roomRate;
   newRoom.numberOfNights = numberOfNights;
   hotelRooms[numRooms++] = newRoom;
   printf("\n Room %d has been successfully added to the hotel.\n", newRoom.roomNumber);
}

void displayRoomData(int roomNumber) {
   for(int i=0;i<numRooms;i++) {
      if(hotelRooms[i].roomNumber == roomNumber) {
         printf("\n Room Number: %d", hotelRooms[i].roomNumber);
         printf("\n Guest Name: %s", hotelRooms[i].guestName);
         printf("\n Room Rate: %f", hotelRooms[i].roomRate);
         printf("\n Number of Nights: %d", hotelRooms[i].numberOfNights);
         return;
      }
   }
   printf("\n Room Number %d could not be found in the hotel.", roomNumber);
}

void displayHotelData() {
   printf("\n Number of Rooms in the Hotel: %d", numRooms);
   printf("\n======== Hotel Room Details =========\n\n");
   for(int i=0;i<numRooms;i++) {
      printf("\n Room Number: %d", hotelRooms[i].roomNumber);
      printf("\n Guest Name: %s", hotelRooms[i].guestName);
      printf("\n Room Rate: %f", hotelRooms[i].roomRate);
      printf("\n Number of Nights: %d", hotelRooms[i].numberOfNights);
      printf("\n====================================\n\n");
   }
}

void deleteRoom(int roomNumber) {
   int index = -1;
   for(int i=0;i<numRooms;i++) {
      if(hotelRooms[i].roomNumber == roomNumber ) {
         index = i;
         break;
      }
   }
   if(index == -1) {
      printf("\n Room Number %d could not be found in the hotel. Cannot delete.", roomNumber);
      return;
   }
   printf("\n Room %d with Guest Name %s has been successfully deleted from the hotel.", hotelRooms[index].roomNumber, hotelRooms[index].guestName);
   for(int i=index;i<numRooms-1;i++) {
      hotelRooms[i] = hotelRooms[i+1];
   }
   numRooms--;
}

float calculateOccupancyRate() {
   int occupiedRooms = 0;
   for(int i=0;i<numRooms;i++) {
      if(strlen(hotelRooms[i].guestName) > 0) {
         occupiedRooms++;
      }
   }
   return (occupiedRooms * 1.0) / (numRooms * 1.0);
}

int main() {
   printf("\n Welcome to the Hotel Management System");

   addRoom(101, "John", 100.0, 3);
   addRoom(102, "Alice", 200.0, 2);
   addRoom(103, "Bob", 75.0, 5);

   printf("\n\n======== Hotel Data We Have Entered =========\n");
   displayHotelData();

   printf("\n\n======== Displaying Room Data =========\n");
   displayRoomData(102);

   printf("\n\n======== Deleting a Room =========\n");
   deleteRoom(102);
   displayHotelData();

   printf("\n\n======== Calculating Occupancy Rate =========\n");
   printf("\nOccupancy rate of the hotel is %f", calculateOccupancyRate());

   return 0;
}