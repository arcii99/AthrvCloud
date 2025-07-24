//FormAI DATASET v1.0 Category: Hotel Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_CUSTOMERS 200

// Room Structure
typedef struct {
    int room_number;
    char room_type[20];
    int room_price;
} Room;

// Customer Structure
typedef struct {
    int customer_id;
    char customer_name[50];
    char customer_email[50];
    int room_number;
    int number_of_days;
    int total_price;
} Customer;

// Hotel Structure containing Rooms and Customers
typedef struct {
    Room rooms[MAX_ROOMS];
    int num_of_rooms;
    Customer customers[MAX_CUSTOMERS];
    int num_of_customers;
} Hotel;

// Function to add a new Room to Hotel Structure
void add_room(Hotel *hotel, int room_number, char *room_type, int room_price) {
    if (hotel->num_of_rooms < MAX_ROOMS) {
        int index = hotel->num_of_rooms;
        hotel->rooms[index].room_number = room_number;
        strcpy(hotel->rooms[index].room_type, room_type);
        hotel->rooms[index].room_price = room_price;
        hotel->num_of_rooms++;
        printf("Room added successfully!\n");
    } else {
        printf("Cannot add Room! Hotel has reached maximum capacity!\n");
    }
}

// Function to view all Rooms in Hotel Structure
void view_rooms(Hotel *hotel) {
    if (hotel->num_of_rooms == 0) {
        printf("Hotel has no Rooms yet!\n");
    } else {
        printf("Rooms in Hotel:\n");
        printf("Room No.\tRoom Type\tRoom Price\n");
        for (int i = 0; i < hotel->num_of_rooms; i++) {
            printf("%d\t\t%s\t\t%d\n", hotel->rooms[i].room_number, hotel->rooms[i].room_type, hotel->rooms[i].room_price);
        }
    }
}

// Function to add a new Customer to Hotel Structure and allocate a Room
void add_customer(Hotel *hotel, char *customer_name, char *customer_email, int room_number, int number_of_days) {
    if (hotel->num_of_customers < MAX_CUSTOMERS) {
        int index = hotel->num_of_customers;
        int room_index = -1;
        for (int i = 0; i < hotel->num_of_rooms; i++) {
            if (hotel->rooms[i].room_number == room_number) {
                room_index = i;
                break;
            }
        }
        if (room_index >= 0) {
            hotel->customers[index].customer_id = index + 1;
            strcpy(hotel->customers[index].customer_name, customer_name);
            strcpy(hotel->customers[index].customer_email, customer_email);
            hotel->customers[index].room_number = room_number;
            hotel->customers[index].number_of_days = number_of_days;
            hotel->customers[index].total_price = number_of_days * hotel->rooms[room_index].room_price;
            hotel->num_of_customers++;
            printf("Customer added and Room allocated successfully!\n");
        } else {
            printf("Cannot add Customer! Room is not available!\n");
        }
    } else {
        printf("Cannot add Customer! Hotel has reached maximum capacity!\n");
    }
}

// Function to view all Customers in Hotel Structure
void view_customers(Hotel *hotel) {
    if (hotel->num_of_customers == 0) {
        printf("Hotel has no Customers yet!\n");
    } else {
        printf("Customers in Hotel:\n");
        printf("Customer ID\tCustomer Name\tCustomer Email\t\tRoom No.\tDays\tPrice\n");
        for (int i = 0; i < hotel->num_of_customers; i++) {
            printf("%d\t\t%s\t\t%s\t\t%d\t\t%d\t%d\n", hotel->customers[i].customer_id, hotel->customers[i].customer_name, hotel->customers[i].customer_email, hotel->customers[i].room_number, hotel->customers[i].number_of_days, hotel->customers[i].total_price);
        }
    }
}

// Main Function
int main() {
    Hotel hotel;
    hotel.num_of_rooms = 0;
    hotel.num_of_customers = 0;
    int choice = 0;
    do {
        printf("\n--------- Menu ---------\n");
        printf("1. Add Room\n");
        printf("2. View Rooms\n");
        printf("3. Add Customer and Allocate Room\n");
        printf("4. View Customers\n");
        printf("5. Exit\n");
        printf("-------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                {
                    int room_number, room_price;
                    char room_type[20];
                    printf("Enter Room Number: ");
                    scanf("%d", &room_number);
                    printf("Enter Room Type: ");
                    scanf("%s", room_type);
                    printf("Enter Room Price: ");
                    scanf("%d", &room_price);
                    add_room(&hotel, room_number, room_type, room_price);
                    break;
                }
            case 2:
                {
                    view_rooms(&hotel);
                    break;
                }
            case 3:
                {
                    char customer_name[50], customer_email[50];
                    int room_number, number_of_days;
                    printf("Enter Customer Name: ");
                    scanf("%s", customer_name);
                    printf("Enter Customer Email: ");
                    scanf("%s", customer_email);
                    printf("Enter Room Number: ");
                    scanf("%d", &room_number);
                    printf("Enter Number of Days: ");
                    scanf("%d", &number_of_days);
                    add_customer(&hotel, customer_name, customer_email, room_number, number_of_days);
                    break;
                }
            case 4:
                {
                    view_customers(&hotel);
                    break;
                }
            case 5:
                {
                    printf("Thank you. Exiting...\n");
                    exit(0);
                }
            default:
                {
                    printf("Invalid choice! Please select again.\n");
                    break;
                }
        }
    } while (choice != 5);
    return 0;
}