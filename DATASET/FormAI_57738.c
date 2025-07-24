//FormAI DATASET v1.0 Category: Hotel Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROOMS 100

struct Reservation {
    int roomNumber;
    char clientName[50];
    int numGuests;
    char checkIn[11]; // dd/mm/yyyy format
    char checkOut[11]; // dd/mm/yyyy format
    double totalPrice;
    int status; // 0=available, 1=booked
};

struct Room {
    int roomNumber;
    char type[20];
    double price;
    int status; // 0=available, 1=booked
};

// Function declarations
void displayMenu();
void initializeRooms(struct Room []);
void displayRooms(struct Room []);
void reserveRoom(struct Room [], struct Reservation []);
void displayReservations(struct Reservation []);
int findReservation(struct Reservation [], int);
void cancelReservation(struct Room [], struct Reservation []);

int main() {
    struct Room rooms[MAX_ROOMS];
    struct Reservation reservations[MAX_ROOMS];
    initializeRooms(rooms); // set status of all rooms to available
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayRooms(rooms);
                break;
            case 2:
                reserveRoom(rooms, reservations);
                break;
            case 3:
                displayReservations(reservations);
                break;
            case 4:
                cancelReservation(rooms, reservations);
                break;
            case 5:
                printf("Thank you for using the hotel management system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}

void displayMenu() {
    printf("\n");
    printf("1. Display rooms\n");
    printf("2. Reserve a room\n");
    printf("3. Display reservations\n");
    printf("4. Cancel reservation\n");
    printf("5. Exit\n");
}

void initializeRooms(struct Room rooms[]) {
    int i;
    for (i=0; i<MAX_ROOMS; i++) {
        rooms[i].roomNumber = i+1;
        strcpy(rooms[i].type, "Standard");
        rooms[i].price = 80.0;
        rooms[i].status = 0;
    }
}

void displayRooms(struct Room rooms[]) {
    int i;
    printf("Room Number\tType\tPrice\tStatus\n");
    for (i=0; i<MAX_ROOMS; i++) {
        printf("%d\t%s\t%.2f\t%s\n", rooms[i].roomNumber, rooms[i].type, rooms[i].price, rooms[i].status==0 ? "Available" : "Booked");
    }
}

void reserveRoom(struct Room rooms[], struct Reservation reservations[]) {
    int roomNum, numGuests, i, found=0;
    char clientName[50];
    char checkIn[11];
    char checkOut[11];
    printf("Enter room number: ");
    scanf("%d", &roomNum);
    for (i=0; i<MAX_ROOMS; i++) {
        if (rooms[i].roomNumber == roomNum) {
            found = 1;
            if (rooms[i].status == 0) {
                printf("Enter client name: ");
                scanf("%s", clientName);
                printf("Enter number of guests: ");
                scanf("%d", &numGuests);
                printf("Enter check-in date (dd/mm/yyyy): ");
                scanf("%s", checkIn);
                printf("Enter check-out date (dd/mm/yyyy): ");
                scanf("%s", checkOut);
                int resNum = findReservation(reservations, -1);
                reservations[resNum].roomNumber = roomNum;
                strcpy(reservations[resNum].clientName, clientName);
                reservations[resNum].numGuests = numGuests;
                strcpy(reservations[resNum].checkIn, checkIn);
                strcpy(reservations[resNum].checkOut, checkOut);
                rooms[i].status = 1;
                reservations[resNum].status = 1;
                double totalCost = rooms[i].price * (atoi(checkOut+1) - atoi(checkIn+1)); // calculate total cost based on number of nights
                reservations[resNum].totalPrice = totalCost;
                printf("Reservation confirmed. Total cost: %.2f\n", totalCost);
            } else {
                printf("Room is already booked.\n");
            }
        }
    }
    if (!found) {
        printf("Invalid room number.\n");
    }
}

void displayReservations(struct Reservation reservations[]) {
    int i, num;
    printf("Reservation Number\tRoom Number\tClient Name\tNumber of Guests\tCheck-in Date\tCheck-out Date\tTotal Price\n");
    for (i=0; i<MAX_ROOMS; i++) {
        if (reservations[i].status == 1) {
            printf("%d\t%d\t%s\t%d\t%s\t%s\t%.2f\n", i+1, reservations[i].roomNumber, reservations[i].clientName, reservations[i].numGuests, reservations[i].checkIn, reservations[i].checkOut, reservations[i].totalPrice);
        }
    }
    printf("Enter reservation number to view details (0 to go back): ");
    scanf("%d", &num);
    if (num > 0 && num <= MAX_ROOMS && reservations[num-1].status == 1) {
        printf("Room Number: %d\n", reservations[num-1].roomNumber);
        printf("Client Name: %s\n", reservations[num-1].clientName);
        printf("Number of Guests: %d\n", reservations[num-1].numGuests);
        printf("Check-in Date: %s\n", reservations[num-1].checkIn);
        printf("Check-out Date: %s\n", reservations[num-1].checkOut);
        printf("Total Price: %.2f\n", reservations[num-1].totalPrice);
    }
}

int findReservation(struct Reservation reservations[], int roomNum) {
    int i;
    for (i=0; i<MAX_ROOMS; i++) {
        if (reservations[i].status == 0) {
            return i;
        }
        if (reservations[i].roomNumber == roomNum) {
            return i;
        }
    }
    return -1; // no available reservations
}

void cancelReservation(struct Room rooms[], struct Reservation reservations[]) {
    int resNum, i;
    printf("Enter reservation number to cancel: ");
    scanf("%d", &resNum);
    if (resNum > 0 && resNum <= MAX_ROOMS && reservations[resNum-1].status == 1) {
        reservations[resNum-1].status = 0;
        for (i=0; i<MAX_ROOMS; i++) {
            if (rooms[i].roomNumber == reservations[resNum-1].roomNumber) {
                rooms[i].status = 0;
            }
        }
        printf("Reservation cancelled.\n");
    } else {
        printf("Invalid reservation number.\n");
    }
}