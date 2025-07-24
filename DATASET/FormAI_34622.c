//FormAI DATASET v1.0 Category: Hotel Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int room_no;
  float rate;
  int days;
  float total_bill;
  int booked;
} Room;

Room rooms[10];

void initialize_rooms() {
  for (int i=0; i<10; i++) {
    strcpy(rooms[i].name, "");
    rooms[i].room_no = i+1;
    rooms[i].rate = 1000.0;
    rooms[i].days = 0;
    rooms[i].total_bill = 0.0;
    rooms[i].booked = 0;
  }
}

void book_room() {
  int room;
  printf("Enter room number to book: ");
  fflush(stdin);
  scanf("%d", &room);
  if (room < 1 || room > 10) {
    printf("Invalid room number.");
    return;
  }
  if (rooms[room-1].booked == 1) {
    printf("Room already booked.");
    return;
  }
  printf("Enter guest name: ");
  fflush(stdin);
  fgets(rooms[room-1].name, 50, stdin);
  rooms[room-1].name[strlen(rooms[room-1].name)-1] = '\0';
  printf("Enter no. of days to book: ");
  fflush(stdin);
  scanf("%d", &rooms[room-1].days);
  rooms[room-1].total_bill = rooms[room-1].days * rooms[room-1].rate;
  rooms[room-1].booked = 1;
  printf("Room booked successfully.\n");
}

void display_rooms() {
  printf("Room No.\tGuest Name\tDays\tRate\tTotal Bill\n");
  for (int i=0; i<10; i++) {
    printf("%d\t\t%s\t\t%d\t%.2f\t%.2f\n", rooms[i].room_no, rooms[i].name, rooms[i].days, rooms[i].rate, rooms[i].total_bill);
  }
}

void show_menu() {
  printf("1. Book room\n");
  printf("2. Display rooms\n");
  printf("3. Exit\n");
}

int main() {
  initialize_rooms();
  int choice;
  do {
    show_menu();
    printf("Enter your choice: ");
    fflush(stdin);
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        book_room();
        break;
      case 2:
        display_rooms();
        break;
      case 3:
        printf("Goodbye!\n");
        exit(0);
        break;
      default:
        printf("Invalid choice. Try again.\n");
        break;
    }
  } while(1);
  return 0;
}