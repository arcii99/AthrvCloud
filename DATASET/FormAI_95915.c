//FormAI DATASET v1.0 Category: Hotel Management System ; Style: imaginative
/* Welcome to the C Hotel Management System! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum number of rooms */
#define MAX_ROOMS 100

/* Define the maximum length of room names */
#define MAX_NAME_LEN 20

/* Define the maximum length of guest names */
#define MAX_GUESTS_LEN 30

/* Define the maximum length of guest emails */
#define MAX_EMAILS_LEN 50

/* Define the maximum length of guest phone numbers */
#define MAX_PHONE_LEN 20

/* Define a struct for each hotel room */
typedef struct Room {
    int number;
    int occupied;
    char name[MAX_NAME_LEN];
    char guests[MAX_GUESTS_LEN];
    char email[MAX_EMAILS_LEN];
    char phone[MAX_PHONE_LEN];
} Room;

/* Define a function to print the hotel menu */
void print_menu() {
  printf("--------------------\n");
  printf("Hotel Management System\n");
  printf("--------------------\n");
  printf("1. Check in\n");
  printf("2. Check out\n");
  printf("3. Display rooms\n");
  printf("4. Exit\n");
  printf("--------------------\n");
}

/* Define a function to set a room as occupied */
void check_in(Room *room, char *name, char *guests, char *email, char *phone) {
  room->occupied = 1;
  strncpy(room->name, name, MAX_NAME_LEN);
  strncpy(room->guests, guests, MAX_GUESTS_LEN);
  strncpy(room->email, email, MAX_EMAILS_LEN);
  strncpy(room->phone, phone, MAX_PHONE_LEN);
  printf("Room %d checked in.\n", room->number);
}

/* Define a function to set a room as unoccupied */
void check_out(Room *room) {
  room->occupied = 0;
  memset(room->name, 0, MAX_NAME_LEN);
  memset(room->guests, 0, MAX_GUESTS_LEN);
  memset(room->email, 0, MAX_EMAILS_LEN);
  memset(room->phone, 0, MAX_PHONE_LEN);
  printf("Room %d checked out.\n", room->number);
}

/* Define a function to display the hotel rooms */
void display_rooms(Room *rooms, int num_rooms) {
  printf("Rooms:\n");
  for (int i = 0; i < num_rooms; i++) {
    printf("%d. ", rooms[i].number);
    if (rooms[i].occupied) printf("Occupied by %s\n", rooms[i].name);
    else printf("Unoccupied\n");
  }
}

/* Define the main function */
int main() {
  /* Initialize the hotel rooms */
  Room hotel_rooms[MAX_ROOMS];
  for (int i = 0; i < MAX_ROOMS; i++) {
    hotel_rooms[i].number = i+1;
    hotel_rooms[i].occupied = 0;
  }

  /* Set up variables */
  int choice = 0, room_num = 0;
  char name[MAX_NAME_LEN], guests[MAX_GUESTS_LEN], email[MAX_EMAILS_LEN], phone[MAX_PHONE_LEN];

  /* Print the menu and loop until the user chooses to exit */
  do {
    print_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    /* Handle user input */
    switch (choice) {
      case 1:
        printf("Enter the room number: ");
        scanf("%d", &room_num);
        if (hotel_rooms[room_num-1].occupied) {
            printf("Room is already occupied.\n");
        } else {
            printf("Enter your name: ");
            scanf("%s", name);
            printf("Enter the guest(s) name(s): ");
            scanf("%s", guests);
            printf("Enter your email: ");
            scanf("%s", email);
            printf("Enter your phone number: ");
            scanf("%s", phone);
            check_in(&hotel_rooms[room_num-1], name, guests, email, phone);
        }
        break;
      case 2:
        printf("Enter the room number: ");
        scanf("%d", &room_num);
        if (hotel_rooms[room_num-1].occupied) {
            check_out(&hotel_rooms[room_num-1]);
        } else {
            printf("Room is not occupied.\n");
        }
        break;
      case 3:
        display_rooms(hotel_rooms, MAX_ROOMS);
        break;
      case 4:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }

  } while (choice != 4);

  return 0;
}