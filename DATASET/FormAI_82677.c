//FormAI DATASET v1.0 Category: Hotel Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
  int roomNumber;
  char guestName[30];
};

struct Room hotel[10];

void checkIn() {
  int roomNumber;
  char guestName[30];
  printf("\nEnter room number: ");
  scanf("%d", &roomNumber);
  
  if(hotel[roomNumber-1].roomNumber == roomNumber) {
    printf("\nRoom is already occupied\n");
  }
  else {
    printf("\nEnter guest name: ");
    scanf("%s", guestName);
    hotel[roomNumber-1].roomNumber = roomNumber;
    strcpy(hotel[roomNumber-1].guestName, guestName);
    printf("\n%s has been checked in to room number %d\n", guestName, roomNumber);
  }
}

void checkOut() {
  int roomNumber;
  printf("\nEnter room number to check out: ");
  scanf("%d", &roomNumber);
  
  if(hotel[roomNumber-1].roomNumber == 0) {
    printf("\nRoom is unoccupied\n");
  }
  else {
    printf("\n%s has checked out of room number %d\n", hotel[roomNumber-1].guestName, roomNumber);
    strcpy(hotel[roomNumber-1].guestName, "");
    hotel[roomNumber-1].roomNumber = 0;
  }
}

void menu() {
  int choice;
  printf("\n1. Check-in");
  printf("\n2. Check-out");
  printf("\n3. Exit");
  printf("\nEnter choice: ");
  scanf("%d", &choice);
  
  switch(choice) {
    case 1:
      checkIn();
      break;
    case 2:
      checkOut();
      break;
    case 3:
      exit(0);
      break;
    default:
      printf("\nInvalid choice\n");
      break;
  }
}

int main() {
  int i;
  for(i=0; i<10; i++) {
    hotel[i].roomNumber = 0;
    strcpy(hotel[i].guestName, "");
  }
  
  while(1) {
    menu();
  }
  return 0;
}