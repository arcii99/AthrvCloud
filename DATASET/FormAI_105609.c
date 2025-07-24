//FormAI DATASET v1.0 Category: Hotel Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int room_number;
  char room_type[20];
  float price;
  int status;
} Room;

typedef struct {
  char name[50];
  char address[100];
  char phone_number[15];
} Customer;

typedef struct {
  int checkin_date;
  int checkout_date;
  int num_of_nights;
  Customer customer;
  Room room;
} Reservation;

Room rooms[50]; // initialized with 50 rooms
Reservation reservations[100]; // initialized with capacity for 100 reservations
int num_of_rooms = 0;
int num_of_reservations = 0;

void add_room(int room_number, char* room_type, float price) {
  Room new_room;
  new_room.room_number = room_number;
  strcpy(new_room.room_type, room_type);
  new_room.price = price;
  new_room.status = 1; // 1 means it is available
  num_of_rooms++;
  rooms[num_of_rooms-1] = new_room;
}

void print_rooms() {
  for (int i = 0; i < num_of_rooms; i++) {
    printf("Room %d - Type: %s, Price: $%.2f per night, Status: %s\n", 
           rooms[i].room_number, rooms[i].room_type, rooms[i].price, 
           rooms[i].status == 1 ? "Available" : "Occupied");
  }
}

int get_room_index(int room_number) {
  for (int i = 0; i < num_of_rooms; i++) {
    if (rooms[i].room_number == room_number) {
      return i;
    }
  }
  return -1; // room not found
}

void print_reservations() {
  for (int i = 0; i < num_of_reservations; i++) {
    printf("Reservation #%d\n", i+1);
    printf("Customer: %s\n", reservations[i].customer.name);
    printf("Room: %d\n", reservations[i].room.room_number);
    printf("Check-in Date: %d\n", reservations[i].checkin_date);
    printf("Check-out Date: %d\n", reservations[i].checkout_date);
    printf("Number of Nights: %d\n", reservations[i].num_of_nights);
  }
}

void book_room(int room_number, int checkin_date, int checkout_date, Customer customer) {
  int room_index = get_room_index(room_number);
  if (room_index == -1) {
    printf("This room does not exist\n");
    return;
  }
  if (rooms[room_index].status == 0) {
    printf("This room is already occupied\n");
    return;
  }
  Reservation new_reservation;
  new_reservation.room = rooms[room_index];
  new_reservation.checkin_date = checkin_date;
  new_reservation.checkout_date = checkout_date;
  new_reservation.num_of_nights = checkout_date - checkin_date;
  new_reservation.customer = customer;
  rooms[room_index].status = 0; // mark room as occupied
  num_of_reservations++;
  reservations[num_of_reservations-1] = new_reservation;
  printf("Room %d has been booked by %s from %d to %d\n", 
         room_number, customer.name, checkin_date, checkout_date);
}

int main() {
  // adding rooms
  add_room(101, "Standard", 99.99);
  add_room(102, "Standard", 99.99);
  add_room(103, "Deluxe", 139.99);
  add_room(104, "Deluxe", 139.99);
  add_room(105, "Suite", 259.99);
  add_room(106, "Suite", 259.99);
  
  // printing rooms
  printf("List of Rooms\n");
  print_rooms();
  
  // adding reservations
  Customer customer1 = {"John Smith", "123 Main St, Anytown, USA", "+1 (123) 456-7890"};
  book_room(101, 20211011, 20211014, customer1);
  Customer customer2 = {"Jane Doe", "456 Oak Ave, Another Town, USA", "+1 (234) 567-8901"};
  book_room(105, 20211201, 20211205, customer2);
  Customer customer3 = {"Bob Johnson", "789 Maple Rd, A Third Town, USA", "+1 (345) 678-9012"};
  book_room(103, 20220101, 20220103, customer3);
  
  // printing reservations
  printf("\nList of Reservations\n");
  print_reservations();
  
  return 0;
}