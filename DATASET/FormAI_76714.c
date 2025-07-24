//FormAI DATASET v1.0 Category: Hotel Management System ; Style: ultraprecise
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 100
#define CHECK_IN 1
#define CHECK_OUT 2

typedef struct {
    int roomNumber;
    int capacity;
    int occupied;
    float price;
} Room;

typedef struct {
    int id;
    char name[50];
    char email[50];
    char phone[15];
} Guest;

typedef struct {
    int bookingNumber;
    int guestId;
    int roomNumber;
    int days;
} Booking;

Room rooms[MAX_ROOMS];
Guest guests[MAX_ROOMS];
Booking bookings[MAX_ROOMS];

int numRooms = 0;
int numGuests = 0;
int numBookings = 0;

void initRooms() {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = 100 + i;
        rooms[i].capacity = 2;
        rooms[i].occupied = 0;
        rooms[i].price = 100.0;
    }
    numRooms = MAX_ROOMS;
}

int findAvailableRoom() {
    int i;
    for (i = 0; i < numRooms; i++) {
        if (rooms[i].occupied == 0) {
            return i;
        }
    }
    return -1;
}

void displayRooms() {
    int i;
    printf("Room\tCapacity\tPrice\n");
    for (i = 0; i < numRooms; i++) {
        printf("%d\t%d\t%.2f\n", rooms[i].roomNumber, rooms[i].capacity, rooms[i].price);
    }
}

void addGuest() {
    Guest newGuest;
    printf("Enter guest name: ");
    scanf("%s", newGuest.name);
    printf("Enter guest email: ");
    scanf("%s", newGuest.email);
    printf("Enter guest phone number: ");
    scanf("%s", newGuest.phone);
    newGuest.id = numGuests + 1;
    guests[numGuests] = newGuest;
    numGuests++;
    printf("Guest added successfully!\n");
}

void displayGuests() {
    int i;
    printf("ID\tName\tEmail\tPhone\n");
    for (i = 0; i < numGuests; i++) {
        printf("%d\t%s\t%s\t%s\n", guests[i].id, guests[i].name, guests[i].email, guests[i].phone);
    }
}

void bookRoom() {
    Booking newBooking;
    int roomIndex;
    int guestId;
    int days;
    int availableRooms;

    printf("Enter guest ID: ");
    scanf("%d", &guestId);
    printf("Enter number of days: ");
    scanf("%d", &days);

    availableRooms = findAvailableRoom();
    if (availableRooms == -1) {
        printf("Sorry, no rooms are available.\n");
        return;
    }

    roomIndex = availableRooms;
    rooms[roomIndex].occupied = 1;

    newBooking.bookingNumber = numBookings + 1;
    newBooking.guestId = guestId;
    newBooking.roomNumber = rooms[roomIndex].roomNumber;
    newBooking.days = days;
    bookings[numBookings] = newBooking;

    printf("Room %d booked successfully!\n", newBooking.roomNumber);
    numBookings++;
}

void checkIn() {
    int roomNumber;
    int bookingIndex;
    int guestIndex;
    int i;

    printf("Enter room number: ");
    scanf("%d", &roomNumber);

    for (i = 0; i < numBookings; i++) {
        if (bookings[i].roomNumber == roomNumber) {
            bookingIndex = i;
            break;
        }
    }

    if (i == numBookings) {
        printf("Sorry, no booking was found for that room.\n");
        return;
    }

    for (i = 0; i < numGuests; i++) {
        if (guests[i].id == bookings[bookingIndex].guestId) {
            guestIndex = i;
            break;
        }
    }

    printf("Welcome %s! Enjoy your stay.\n", guests[guestIndex].name);
}

void checkOut() {
    int roomNumber;
    int bookingIndex;
    int guestIndex;
    int i;
    float total;

    printf("Enter room number: ");
    scanf("%d", &roomNumber);

    for (i = 0; i < numBookings; i++) {
        if (bookings[i].roomNumber == roomNumber) {
            bookingIndex = i;
            break;
        }
    }

    if (i == numBookings) {
        printf("Sorry, no booking was found for that room.\n");
        return;
    }

    for (i = 0; i < numGuests; i++) {
        if (guests[i].id == bookings[bookingIndex].guestId) {
            guestIndex = i;
            break;
        }
    }

    total = bookings[bookingIndex].days * rooms[roomNumber - 100].price;

    printf("Thank you %s for staying with us!\n", guests[guestIndex].name);
    printf("Your total bill is %.2f\n", total);

    rooms[roomNumber - 100].occupied = 0;
    for (i = bookingIndex; i < numBookings - 1; i++) {
        bookings[i] = bookings[i+1];
    }
    numBookings--;
}

int main() {
    int choice;
    initRooms();

    while (1) {
        printf("\n");
        printf("1. Display available rooms\n");
        printf("2. Add guest\n");
        printf("3. Display guests\n");
        printf("4. Book room\n");
        printf("5. Check in\n");
        printf("6. Check out\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayRooms();
                break;
            case 2:
                addGuest();
                break;
            case 3:
                displayGuests();
                break;
            case 4:
                bookRoom();
                break;
            case 5:
                checkIn();
                break;
            case 6:
                checkOut();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}