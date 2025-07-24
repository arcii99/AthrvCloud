//FormAI DATASET v1.0 Category: Hotel Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for rooms and reservations
typedef struct {
    int roomNumber;
    int occupancy;
    float rate;
} Room;

typedef struct {
    char guestName[30];
    int roomNumber;
    int numGuests;
    char checkInDate[11];
    char checkOutDate[11];
} Reservation;

// Function prototypes
void displayMenu();
void displayRooms(Room rooms[], int numRooms);
void displayReservations(Reservation reservations[], int numReservations);
void addReservation(Reservation reservations[], int *numReservations, Room rooms[], int numRooms);
void editReservation(Reservation reservations[], int numReservations, Room rooms[], int numRooms);
void cancelReservation(Reservation reservations[], int *numReservations, Room rooms[], int numRooms);
void checkIn(Reservation reservations[], int numReservations, Room rooms[], int numRooms);
void checkOut(Reservation reservations[], int numReservations, Room rooms[], int numRooms);

int main() {
    int choice;
    int numRooms = 10; // Assume 10 rooms to start
    int numReservations = 0;
    Room rooms[numRooms];
    Reservation reservations[50];

    // Initialize room data
    for (int i = 0; i < numRooms; i++) {
        rooms[i].roomNumber = i + 101; // Room numbers start at 101
        rooms[i].occupancy = 0;
        rooms[i].rate = 100.00; // Assume $100 per night
    }

    // Display main menu options
    do {
        displayMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms(rooms, numRooms);
                break;
            case 2:
                displayReservations(reservations, numReservations);
                break;
            case 3:
                addReservation(reservations, &numReservations, rooms, numRooms);
                break;
            case 4:
                editReservation(reservations, numReservations, rooms, numRooms);
                break;
            case 5:
                cancelReservation(reservations, &numReservations, rooms, numRooms);
                break;
            case 6:
                checkIn(reservations, numReservations, rooms, numRooms);
                break;
            case 7:
                checkOut(reservations, numReservations, rooms, numRooms);
                break;
            case 8:
                // Exit program
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

// Display the main menu options
void displayMenu() {
    printf("\n---C Hotel Management System---\n");
    printf("1. Display Room Status\n");
    printf("2. Display Reservations\n");
    printf("3. Add Reservation\n");
    printf("4. Edit Reservation\n");
    printf("5. Cancel Reservation\n");
    printf("6. Check In\n");
    printf("7. Check Out\n");
    printf("8. Exit\n");
}

// Display the current status of each room
void displayRooms(Room rooms[], int numRooms) {
    printf("\n---Room Status---\n");
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d: ", rooms[i].roomNumber);
        if (rooms[i].occupancy == 1) {
            printf("Occupied\n");
        } else {
            printf("Available\n");
        }
    }
}

// Display the list of reservations
void displayReservations(Reservation reservations[], int numReservations) {
    if (numReservations == 0) {
        printf("\nNo reservations found.\n");
    } else {
        printf("\n---Reservations---\n");
        for (int i = 0; i < numReservations; i++) {
            printf("%d. %s (Room %d, %d guests): %s to %s\n", i+1, 
                   reservations[i].guestName, reservations[i].roomNumber, 
                   reservations[i].numGuests, reservations[i].checkInDate,
                   reservations[i].checkOutDate);
        }
    }
}

// Add a new reservation
void addReservation(Reservation reservations[], int *numReservations, Room rooms[], int numRooms) {
    if (*numReservations == 50) { // Assume max 50 reservations
        printf("\nNo more reservations can be added.\n");
    } else {
        // Get reservation data from user
        Reservation newRes;
        printf("\n---Add Reservation---\n");
        printf("Guest Name: ");
        scanf("%s", newRes.guestName);

        // Display available rooms and prompt user to select a room
        printf("\n---Available Rooms---\n");
        for (int i = 0; i < numRooms; i++) {
            if (rooms[i].occupancy == 0) {
                printf("Room %d ($%.2f per night)\n", rooms[i].roomNumber, rooms[i].rate);
            }
        }
        printf("Enter room number: ");
        scanf("%d", &newRes.roomNumber);

        // Check for valid room number and update room occupancy
        int validRoom = 0;
        for (int i = 0; i < numRooms; i++) {
            if (rooms[i].roomNumber == newRes.roomNumber) {
                if (rooms[i].occupancy == 0) {
                    validRoom = 1;
                    rooms[i].occupancy = 1;
                    break;
                } else {
                    printf("Room is occupied. Please select an available room.\n");
                    return;
                }
            }
        }
        if (validRoom == 0) {
            printf("Invalid room number. Please try again.\n");
            return;
        }

        printf("Number of Guests: ");
        scanf("%d", &newRes.numGuests);
        printf("Check-in Date (YYYY-MM-DD): ");
        scanf("%s", newRes.checkInDate);
        printf("Check-out Date (YYYY-MM-DD): ");
        scanf("%s", newRes.checkOutDate);

        // Add new reservation to array and update reservation count
        reservations[*numReservations] = newRes;
        *numReservations += 1;

        printf("\nReservation added.\n");
    }
}

// Modify an existing reservation
void editReservation(Reservation reservations[], int numReservations, Room rooms[], int numRooms) {
    if (numReservations == 0) {
        printf("\nNo reservations found.\n");
    } else {
        // Display current reservations and prompt user to select one to edit
        printf("\n---Edit Reservation---\n");
        for (int i = 0; i < numReservations; i++) {
            printf("%d. %s (Room %d, %d guests): %s to %s\n", i+1, 
                   reservations[i].guestName, reservations[i].roomNumber, 
                   reservations[i].numGuests, reservations[i].checkInDate,
                   reservations[i].checkOutDate);
        }
        printf("Enter reservation number to edit: ");
        int resNum;
        scanf("%d", &resNum);

        // Check for valid reservation number and prompt user for new data
        if (resNum < 1 || resNum > numReservations) {
            printf("Invalid reservation number. Please try again.\n");
            return;
        } else {
            Reservation *res = &reservations[resNum-1];
            printf("\n---Edit Reservation #%d---\n", resNum);
            printf("Guest Name (%s): ", res->guestName);
            scanf("%s", res->guestName);

            // Display available rooms and prompt user to select a room
            printf("\n---Available Rooms---\n");
            for (int i = 0; i < numRooms; i++) {
                if (rooms[i].occupancy == 0) {
                    printf("Room %d ($%.2f per night)\n", rooms[i].roomNumber, rooms[i].rate);
                }
            }
            printf("Enter room number (%d): ", res->roomNumber);
            scanf("%d", &res->roomNumber);

            // Check for valid room number and update room occupancy
            int validRoom = 0;
            for (int i = 0; i < numRooms; i++) {
                if (rooms[i].roomNumber == res->roomNumber) {
                    if (rooms[i].occupancy == 0 || rooms[i].roomNumber == res->roomNumber) {
                        validRoom = 1;
                        rooms[i].occupancy = 1;
                        break;
                    } else {
                        printf("Room is occupied. Please select an available room.\n");
                        return;
                    }
                }
            }
            if (validRoom == 0) {
                printf("Invalid room number. Please try again.\n");
                return;
            }

            printf("Number of Guests (%d): ", res->numGuests);
            scanf("%d", &res->numGuests);
            printf("Check-in Date (%s): ", res->checkInDate);
            scanf("%s", res->checkInDate);
            printf("Check-out Date (%s): ", res->checkOutDate);
            scanf("%s", res->checkOutDate);

            printf("\nReservation updated.\n");
        }
    }
}

// Cancel an existing reservation
void cancelReservation(Reservation reservations[], int *numReservations, Room rooms[], int numRooms) {
    if (*numReservations == 0) {
        printf("\nNo reservations found.\n");
    } else {
        // Display current reservations and prompt user to select one to cancel
        printf("\n---Cancel Reservation---\n");
        for (int i = 0; i < *numReservations; i++) {
            printf("%d. %s (Room %d, %d guests): %s to %s\n", i+1, 
                   reservations[i].guestName, reservations[i].roomNumber, 
                   reservations[i].numGuests, reservations[i].checkInDate,
                   reservations[i].checkOutDate);
        }
        printf("Enter reservation number to cancel: ");
        int resNum;
        scanf("%d", &resNum);

        // Check for valid reservation number and cancel reservation
        if (resNum < 1 || resNum > *numReservations) {
            printf("Invalid reservation number. Please try again.\n");
            return;
        } else {
            Reservation *res = &reservations[resNum-1];
            for (int i = 0; i < numRooms; i++) {
                if (rooms[i].roomNumber == res->roomNumber) {
                    rooms[i].occupancy = 0;
                    break;
                }
            }
            for (int i = resNum-1; i < *numReservations-1; i++) {
                reservations[i] = reservations[i+1];
            }
            *numReservations -= 1;

            printf("\nReservation is cancelled.\n");
        }
    }
}

// Check a guest into their reserved room
void checkIn(Reservation reservations[], int numReservations, Room rooms[], int numRooms) {
    if (numReservations == 0) {
        printf("\nNo reservations found.\n");
    } else {
        // Display current reservations and prompt user to select one to check in
        printf("\n---Check In---\n");
        for (int i = 0; i < numReservations; i++) {
            printf("%d. %s (Room %d, %d guests): %s to %s\n", i+1, 
                   reservations[i].guestName, reservations[i].roomNumber, 
                   reservations[i].numGuests, reservations[i].checkInDate,
                   reservations[i].checkOutDate);
        }
        printf("Enter reservation number to check-in: ");
        int resNum;
        scanf("%d", &resNum);

        // Check for valid reservation number and check-in guest
        if (resNum < 1 || resNum > numReservations) {
            printf("Invalid reservation number. Please try again.\n");
            return;
        } else {
            Reservation *res = &reservations[resNum-1];
            for (int i = 0; i < numRooms; i++) {
                if (rooms[i].roomNumber == res->roomNumber) {
                    rooms[i].occupancy = 1;
                    break;
                }
            }

            printf("\n%s is checked in to Room %d.\n", res->guestName, res->roomNumber);
        }
    }
}

// Check a guest out of their room
void checkOut(Reservation reservations[], int numReservations, Room rooms[], int numRooms) {
    if (numReservations == 0) {
        printf("\nNo reservations found.\n");
    } else {
        // Display current reservations and prompt user to select one to check out
        printf("\n---Check Out---\n");
        for (int i = 0; i < numReservations; i++) {
            printf("%d. %s (Room %d, %d guests): %s to %s\n", i+1, 
                   reservations[i].guestName, reservations[i].roomNumber, 
                   reservations[i].numGuests, reservations[i].checkInDate,
                   reservations[i].checkOutDate);
        }
        printf("Enter reservation number to check-out: ");
        int resNum;
        scanf("%d", &resNum);

        // Check for valid reservation number and check-out guest
        if (resNum < 1 || resNum > numReservations) {
            printf("Invalid reservation number. Please try again.\n");
            return;
        } else {
            Reservation *res = &reservations[resNum-1];
            for (int i = 0; i < numRooms; i++) {
                if (rooms[i].roomNumber == res->roomNumber) {
                    rooms[i].occupancy = 0;
                    break;
                }
            }

            // Calculate final bill and display receipt
            float totalCost = (float)res->numGuests * rooms[res->roomNumber-101].rate;
            int numNights = atoi(res->checkOutDate+8) - atoi(res->checkInDate+8);
            totalCost *= numNights;
            printf("\n---Receipt---\n");
            printf("Guest Name: %s\n", res->guestName);
            printf("Room Number: %d\n", res->roomNumber);
            printf("Number of Guests: %d\n", res->numGuests);
            printf("Check-in Date: %s\n", res->checkInDate);
            printf("Check-out Date: %s\n", res->checkOutDate);
            printf("Total Amount Due: $%.2f\n", totalCost);

            // Remove reservation from array
            for (int i = resNum-1; i < numReservations-1; i++) {
                reservations[i] = reservations[i+1];
            }
            numReservations -= 1;

            printf("\n%s is checked out of Room %d.\n", res->guestName, res->roomNumber);
        }
    }
}