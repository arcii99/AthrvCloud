//FormAI DATASET v1.0 Category: Hotel Management System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ROOMS 10

struct Room {
  int room_number;
  char guest_name[30];
  char guest_phone_number[15];
  int occupied;
};

struct Room rooms[MAX_ROOMS];

void initialize_rooms() {
  for(int i=0; i<MAX_ROOMS; i++) {
    rooms[i].room_number = i+1; 
    rooms[i].occupied = 0;
  }
}

void check_in() {
  printf("Enter room number: ");
  int room_number;
  scanf("%d", &room_number);

  if(room_number > MAX_ROOMS || room_number < 0) {
    printf("Invalid room number!\n");
    return;
  }

  if(rooms[room_number-1].occupied == 1) {
    printf("Room is already occupied!\n");
    return;
  }

  printf("Enter guest name: ");
  char guest_name[30];
  scanf("%s", guest_name);

  printf("Enter guest phone number: ");
  char guest_phone_number[15];
  scanf("%s", guest_phone_number);

  rooms[room_number-1].occupied = 1;
  strcpy(rooms[room_number-1].guest_name, guest_name);
  strcpy(rooms[room_number-1].guest_phone_number, guest_phone_number);

  printf("Check-in successful!\n");
}

void check_out() {
  printf("Enter room number: ");
  int room_number;
  scanf("%d", &room_number);

  if(room_number > MAX_ROOMS || room_number < 0) {
    printf("Invalid room number!\n");
    return;
  }

  if(rooms[room_number-1].occupied == 0) {
    printf("Room is not occupied!\n");
    return;
  }

  rooms[room_number-1].occupied = 0;
  strcpy(rooms[room_number-1].guest_name, "");
  strcpy(rooms[room_number-1].guest_phone_number, "");

  printf("Check-out successful!\n");
}

void display() {
  for(int i=0; i<MAX_ROOMS; i++) {
    printf("Room Number: %d | Occupied: %d ", rooms[i].room_number, rooms[i].occupied);
    if(rooms[i].occupied == 1) {
      printf("| Guest Name: %s | Guest Phone Number: %s\n", rooms[i].guest_name, rooms[i].guest_phone_number);
    }
    else {
      printf("\n");
    }
  }
}

int main() {
  initialize_rooms();

  printf("==== Welcome to the Hotel Management System ====\n");

  while(1) {
    printf("\n");
    printf("1. Check-in\n");
    printf("2. Check-out\n");
    printf("3. Display Rooms\n");
    printf("4. Exit\n");

    int option;
    printf("\nEnter your option: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        check_in();
        break;
      case 2:
        check_out();
        break;
      case 3:
        display();
        break;
      case 4:
        printf("Thank you for using the Hotel Management System!\n");
        exit(0);
      default:
        printf("Invalid option! Please try again.\n");
    }
  }

  return 0;
}