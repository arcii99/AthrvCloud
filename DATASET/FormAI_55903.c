//FormAI DATASET v1.0 Category: Hotel Management System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// defining hotel structure
struct hotel {
    int room_no;
    char name[50];
    int add_charges;
    int room_charges;
    int total_charges;
} h[10];

// function to book a room
void book_room() {
    int room, index, ad_charges, room_charges;

    // checking for available rooms
    for(int i=0; i<10; i++) {
        if(h[i].name[0] == '\0') {
            printf("Room %d is available.\n", i+1);
        }
    }

    // taking input from user for room booking
    printf("Enter the room number: ");
    scanf("%d", &room);

    // checking if the room has already been booked or not
    if(h[room-1].name[0] != '\0') {
        printf("Sorry, the room is already booked.\n");
    }
    else {
        h[room-1].room_no = room;

        printf("Enter the name: ");
        getchar();
        fgets(h[room-1].name, 50, stdin);

        printf("Enter additional charges: ");
        scanf("%d", &ad_charges);

        printf("Enter room charges: ");
        scanf("%d", &room_charges);

        h[room-1].add_charges = ad_charges;
        h[room-1].room_charges = room_charges;
        h[room-1].total_charges = ad_charges + room_charges;

        printf("Room %d booked successfully.\n", room);
    }
}

// function to display booking details of all the rooms
void display_bookings() {
    printf("ROOM DETAILS\n");
    printf("Room No.\tName\t\tAdditional Charges\tRoom Charges\tTotal Charges\n");

    for(int i=0; i<10; i++) {
        printf("%d\t\t%s\t\t%d\t\t\t%d\t\t%d\n", h[i].room_no, h[i].name, h[i].add_charges, h[i].room_charges, h[i].total_charges);
    }
}

int main() {
    int choice;

    // initializing all room entries
    for(int i=0; i<10; i++) {
        h[i].room_no = i+1;
        h[i].name[0] = '\0';
        h[i].add_charges = 0;
        h[i].room_charges = 0;
        h[i].total_charges = 0;
    }

    while(1) {
        printf("\nHOTEL MANAGEMENT SYSTEM\n");
        printf("1. Book room\n");
        printf("2. Display bookings\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: book_room();
                    break;

            case 2: display_bookings();
                    break;

            case 3: exit(0);

            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}