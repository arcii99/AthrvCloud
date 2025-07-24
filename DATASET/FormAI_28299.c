//FormAI DATASET v1.0 Category: Hotel Management System ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ROOMS 100
#define MAX_CUSTOMERS 100

typedef struct {
    char name[50];
    int age;
    char gender;
    char address[100];
    char phone[11];
} Customer;

typedef struct {
    char room_type[20];
    int room_number;
    int occupancy;
    float rate;
    Customer *customer;
} Room;

typedef struct {
    Room rooms[MAX_ROOMS];
    int total_rooms;
    Customer customers[MAX_CUSTOMERS];
    int total_customers;
} Hotel;

void initialize_hotel(Hotel *hotel) {
    hotel->total_rooms = 0;
    hotel->total_customers = 0;
}

void add_room(Hotel *hotel, char *room_type, int room_number, int occupancy, float rate) {
    if (hotel->total_rooms == MAX_ROOMS) {
        printf("Error: Maximum rooms capacity reached\n");
        return;
    }
    strcpy(hotel->rooms[hotel->total_rooms].room_type, room_type);
    hotel->rooms[hotel->total_rooms].room_number = room_number;
    hotel->rooms[hotel->total_rooms].occupancy = occupancy;
    hotel->rooms[hotel->total_rooms].rate = rate;
    hotel->rooms[hotel->total_rooms].customer = NULL;
    hotel->total_rooms++;
}

void display_room_status(Hotel *hotel) {
    printf("Room status:\n");
    printf("Room type\tRoom number\tOccupancy\tRate\n");
    for (int i = 0; i < hotel->total_rooms; i++) {
        printf("%s\t\t%d\t\t%d\t\t%.2f\n", hotel->rooms[i].room_type, hotel->rooms[i].room_number, hotel->rooms[i].occupancy, hotel->rooms[i].rate);
    }
}

void add_customer(Hotel *hotel, char *name, int age, char gender, char *address, char *phone) {
    if (hotel->total_customers == MAX_CUSTOMERS) {
        printf("Error: Maximum customers capacity reached\n");
        return;
    }
    strcpy(hotel->customers[hotel->total_customers].name, name);
    hotel->customers[hotel->total_customers].age = age;
    hotel->customers[hotel->total_customers].gender = gender;
    strcpy(hotel->customers[hotel->total_customers].address, address);
    strcpy(hotel->customers[hotel->total_customers].phone, phone);
    hotel->total_customers++;
}

void allocate_room(Hotel *hotel, int room_number, Customer *customer) {
    if (hotel->rooms[room_number-1].customer != NULL) {
       printf("Error: Room already allocated to a customer\n");
       return;
    }
    hotel->rooms[room_number-1].customer = customer;
    hotel->rooms[room_number-1].occupancy = 1;
}

void display_customer_status(Hotel *hotel) {
    printf("Customer status:\n");
    printf("Name\tAge\tGender\tAddress\tPhone number\n");
    for (int i = 0; i < hotel->total_customers; i++) {
        printf("%s\t%d\t%c\t%s\t%s\n", hotel->customers[i].name, hotel->customers[i].age, hotel->customers[i].gender, hotel->customers[i].address, hotel->customers[i].phone);
    }
}

int main() {
    Hotel hotel;
    initialize_hotel(&hotel);
    add_room(&hotel, "Deluxe", 101, 0, 5000);
    add_room(&hotel, "Premium", 201, 0, 7000);
    add_room(&hotel, "Standard", 301, 0, 3000);
    add_customer(&hotel, "John Doe", 30, 'M', "123 Main St", "18005551212");
    allocate_room(&hotel, 1, &hotel.customers[0]);
    display_room_status(&hotel);
    display_customer_status(&hotel);
    return 0;
}