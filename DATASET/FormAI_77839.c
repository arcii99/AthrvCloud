//FormAI DATASET v1.0 Category: Hotel Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

//Creating a structure for hotel guests
struct Guest {
    char name[50];
    int age;
    char address[100];
    char phone_number[20];
    int room_number;
};

//Creating a structure for hotel rooms
struct Room {
    int room_number;
    char room_type[20];
    int price;
    int occupied;
};

//Function to display the available rooms
void displayRooms(struct Room rooms[], int n) {
    int i;
    printf("Available Rooms:\n\n");
    for (i = 0; i < n; i++) {
        if (rooms[i].occupied == 0) {
            printf("Room Number: %d\n", rooms[i].room_number);
            printf("Room Type: %s\n", rooms[i].room_type);
            printf("Price: %d\n", rooms[i].price);
            printf("\n");
        }
    }
}

//Function to add a new guest
void addGuest(struct Guest guests[], int n, struct Room rooms[], int m) {
    int i, room_num, flag = 0;
    //Checking if there are available rooms
    for (i = 0; i < m; i++) {
        if (rooms[i].occupied == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("Sorry, no rooms available.\n");
        return;
    }
    //Assigning an available room to the guest
    displayRooms(rooms, m);
    printf("Enter Room Number: ");
    scanf("%d", &room_num);
    for (i = 0; i < m; i++) {
        if (rooms[i].room_number == room_num && rooms[i].occupied == 0) {
            guests[n].room_number = room_num;
            rooms[i].occupied = 1;
            printf("\nEnter Guest Details:\n");
            printf("Name: ");
            scanf("%s", guests[n].name);
            printf("Age: ");
            scanf("%d", &guests[n].age);
            printf("Address: ");
            scanf("%s", guests[n].address);
            printf("Phone Number: ");
            scanf("%s", guests[n].phone_number);
            printf("\nGuest Added Successfully!\n");
            return;
        }
    }
    printf("\nRoom number not found or occupied!\n");
}

//Function to display the guest list
void displayGuests(struct Guest guests[], int n) {
    int i;
    printf("\nGuest List:\n\n");
    for (i = 0; i < n; i++) {
        if (guests[i].room_number != 0) {
            printf("Guest Name: %s\n", guests[i].name);
            printf("Room Number: %d\n", guests[i].room_number);
            printf("Age: %d\n", guests[i].age);
            printf("Address: %s\n", guests[i].address);
            printf("Phone Number: %s\n", guests[i].phone_number);
            printf("\n");
        }
    }
}

int main() {

    //Creating an array of rooms
    struct Room rooms[10];
    rooms[0].room_number = 101;
    strcpy(rooms[0].room_type, "Standard");
    rooms[0].price = 5000;
    rooms[0].occupied = 0;

    rooms[1].room_number = 102;
    strcpy(rooms[1].room_type, "Standard");
    rooms[1].price = 5000;
    rooms[1].occupied = 0;

    rooms[2].room_number = 103;
    strcpy(rooms[2].room_type, "Deluxe");
    rooms[2].price = 7000;
    rooms[2].occupied = 0;

    rooms[3].room_number = 104;
    strcpy(rooms[3].room_type, "Deluxe");
    rooms[3].price = 7000;
    rooms[3].occupied = 0;

    rooms[4].room_number = 105;
    strcpy(rooms[4].room_type, "Superior");
    rooms[4].price = 10000;
    rooms[4].occupied = 0;

    rooms[5].room_number = 106;
    strcpy(rooms[5].room_type, "Superior");
    rooms[5].price = 10000;
    rooms[5].occupied = 0;

    rooms[6].room_number = 107;
    strcpy(rooms[6].room_type, "Premium");
    rooms[6].price = 15000;
    rooms[6].occupied = 0;

    rooms[7].room_number = 108;
    strcpy(rooms[7].room_type, "Premium");
    rooms[7].price = 15000;
    rooms[7].occupied = 0;

    rooms[8].room_number = 109;
    strcpy(rooms[8].room_type, "Executive Suite");
    rooms[8].price = 25000;
    rooms[8].occupied = 0;

    rooms[9].room_number = 110;
    strcpy(rooms[9].room_type, "Presidential Suite");
    rooms[9].price = 50000;
    rooms[9].occupied = 0;

    //Creating an array of guests
    struct Guest guests[10];
    int n = 0, i, choice;

    //Displaying the options
    while (1) {
        printf("Welcome to C Hotel Management System\n\n");
        printf("1. Add Guest\n");
        printf("2. Display Guest List\n");
        printf("3. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGuest(guests, n, rooms, 10);
                n++;
                break;
            case 2:
                displayGuests(guests, n);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
    return 0;
}