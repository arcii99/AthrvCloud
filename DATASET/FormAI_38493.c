//FormAI DATASET v1.0 Category: Hotel Management System ; Style: statistical
#include <stdio.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 200

typedef struct {
  int room_number;
  int num_adults;
  int num_children;
  float price;
} Room;

typedef struct {
  char name[50];
  int age;
  int room_number;
} Guest;

Room rooms[MAX_ROOMS];
Guest guests[MAX_GUESTS];

int num_rooms = 0;
int num_guests = 0;

void add_room(int num_adults, int num_children, float price) {
  if (num_rooms >= MAX_ROOMS) {
    printf("Error: No more rooms can be added.\n");
    return;
  }
  Room new_room;
  new_room.room_number = num_rooms + 1;
  new_room.num_adults = num_adults;
  new_room.num_children = num_children;
  new_room.price = price;
  rooms[num_rooms++] = new_room;
  printf("Added room number %d with price $%.2f\n", new_room.room_number, new_room.price);
}

void add_guest(char* name, int age, int room_number) {
  if (num_guests >= MAX_GUESTS) {
    printf("Error: No more guests can be added.\n");
    return;
  }
  Guest new_guest;
  snprintf(new_guest.name, 50, "%s", name);
  new_guest.age = age;
  new_guest.room_number = room_number;
  guests[num_guests++] = new_guest;
  printf("Added guest %s to room number %d\n", new_guest.name, new_guest.room_number);
}

void print_rooms() {
  printf("Rooms:\n");
  printf("%-10s %-12s %-12s %10s\n", "Room #", "# Adults", "# Children", "Price");
  for (int i = 0; i < num_rooms; i++) {
    printf("%-10d %-12d %-12d $%9.2f\n", rooms[i].room_number, rooms[i].num_adults, rooms[i].num_children, rooms[i].price);
  }
}

void print_guests() {
  printf("Guests:\n");
  printf("%-20s %-10s %-10s\n", "Name", "Age", "Room #");
  for (int i = 0; i < num_guests; i++) {
    printf("%-20s %-10d %-10d\n", guests[i].name, guests[i].age, guests[i].room_number);
  }
}

int main() {
  add_room(2, 1, 199.99);
  add_room(4, 2, 299.99);
  add_guest("John Smith", 35, 1);
  add_guest("Jane Doe", 27, 1);
  add_guest("Bob Johnson", 42, 2);
  print_rooms();
  print_guests();
  return 0;
}