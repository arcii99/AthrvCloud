//FormAI DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
  char name[50];
  int room_number;
  int nights_stayed;
  float bill;
};

struct guest hotel[10];

int main() {
  int choice;

  do {
    printf("\nWelcome to the C Hotel Management System!\n");
    printf("\nWhat would you like to do?\n");
    printf("1. Check in a guest\n");
    printf("2. Check out a guest\n");
    printf("3. View all guests\n");
    printf("4. Exit\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        check_in();
        break;
      case 2:
        check_out();
        break;
      case 3:
        view_guests();
        break;
      case 4:
        printf("\nThank you for using the C Hotel Management System!\n");
        exit(0);
        break;
      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  } while(choice != 4);

  return 0;
}

void check_in() {
  int i, room_available = 0;

  for(i = 0; i < 10; i++) {
    if(hotel[i].room_number == 0) {
      room_available = 1;
      printf("\nEnter guest name: ");
      scanf("%s", hotel[i].name);
      printf("Enter room number: ");
      scanf("%d", &hotel[i].room_number);
      printf("Enter number of nights stayed: ");
      scanf("%d", &hotel[i].nights_stayed);
      hotel[i].bill = hotel[i].nights_stayed * 100.0;
      printf("\nGuest checked in successfully!\n");
      break;
    }
  }

  if(!room_available) {
    printf("\nSorry, all rooms are currently booked.\n");
  }
}

void check_out() {
  int room_number, i, guest_found = 0;

  printf("\nEnter room number of guest to check out: ");
  scanf("%d", &room_number);

  for(i = 0; i < 10; i++) {
    if(hotel[i].room_number == room_number) {
      guest_found = 1;
      printf("\nGuest name: %s\n", hotel[i].name);
      printf("Number of nights stayed: %d\n", hotel[i].nights_stayed);
      printf("Room bill: $%.2f\n", hotel[i].bill);
      hotel[i].room_number = 0;
      hotel[i].nights_stayed = 0;
      hotel[i].bill = 0.0;
      printf("\nGuest checked out successfully!\n");
      break;
    }
  }

  if(!guest_found) {
    printf("\nSorry, no guest found with that room number.\n");
  }
}

void view_guests() {
  int i, guests_in_hotel = 0;

  for(i = 0; i < 10; i++) {
    if(hotel[i].room_number != 0) {
      guests_in_hotel++;
      printf("\nGuest #%d\n", guests_in_hotel);
      printf("Name: %s\n", hotel[i].name);
      printf("Room number: %d\n", hotel[i].room_number);
      printf("Number of nights stayed: %d\n", hotel[i].nights_stayed);
      printf("Room bill: $%.2f\n", hotel[i].bill);
    }
  }

  if(guests_in_hotel == 0) {
    printf("\nThere are no guests currently checked in.\n");
  }
}