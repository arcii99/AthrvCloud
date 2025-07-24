//FormAI DATASET v1.0 Category: Hotel Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 50
#define MAX_BOOKINGS 365

typedef struct {
    int roomNumber;
    char guestName[MAX_NAME_LENGTH];
    int checkInDay;
    int checkOutDay;
    double totalPrice;
} Booking;

int numRooms = 0;
Booking bookings[MAX_BOOKINGS];

int addBooking(int roomNumber, char* guestName, int checkInDay, int checkOutDay) {
    if (numRooms == MAX_ROOMS || checkInDay < 0 || checkOutDay < 0 || checkOutDay <= checkInDay) {
        return -1;
    }

    double totalPrice = (checkOutDay - checkInDay) * 100.0;

    bookings[numRooms].roomNumber = roomNumber;
    strcpy(bookings[numRooms].guestName, guestName);
    bookings[numRooms].checkInDay = checkInDay;
    bookings[numRooms].checkOutDay = checkOutDay;
    bookings[numRooms].totalPrice = totalPrice;

    numRooms++;

    return 0;
}

void displayBookings() {
    printf("Bookings:\n");
    printf("| %10s | %20s | %10s | %11s | %12s |\n", "Room Number", "Guest Name", "Check In", "Check Out", "Total Price");
    printf("------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < numRooms; i++) {
        printf("| %10d | %20s | %10d | %11d | $%11.2f |\n", bookings[i].roomNumber, bookings[i].guestName, 
                bookings[i].checkInDay, bookings[i].checkOutDay, bookings[i].totalPrice);
    }

    printf("\n");
}

int getTotalRoomNights(int roomNumber) {
    int totalNights = 0;

    for (int i = 0; i < numRooms; i++) {
        if (bookings[i].roomNumber == roomNumber) {
            totalNights += bookings[i].checkOutDay - bookings[i].checkInDay;
        }
    }

    return totalNights;
}

int main() {
    srand(time(0));

    printf("Welcome to the C Hotel Management System!\n");
    printf("=========================================\n\n");

    printf("Adding some example bookings...\n\n");

    addBooking(101, "John Smith", 0, 3);
    addBooking(102, "Jane Doe", 2, 5);
    addBooking(103, "Bob Johnson", 2, 6);
    addBooking(101, "Sarah Lee", 4, 8);
    addBooking(104, "Tom Williams", 6, 9);
    addBooking(102, "Alice Chang", 8, 11);

    displayBookings();

    printf("Total nights booked for Room 101: %d\n\n", getTotalRoomNights(101));

    return 0;
}