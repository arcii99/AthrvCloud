//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    int number;
    int capacity;
    char type[20];
    int price;
    int status; // 0 for available, 1 for occupied
};

struct Reservation {
    char guestName[50];
    char guestPhone[20];
    int numDays;
    int roomNumber;
};

struct Hotel {
    char name[50];
    struct Room rooms[100];
    struct Reservation reservations[100];
    int numRooms;
    int numReservations;
};

void printMenu() {
    printf("\n");
    printf("Welcome to Hotel Management System!\n");
    printf("1) Add New Room\n");
    printf("2) Edit Room Details\n");
    printf("3) Search Room by Type\n");
    printf("4) Display All Rooms\n");
    printf("5) Make Reservation\n");
    printf("6) Edit Reservation Details\n");
    printf("7) Cancel Reservation\n");
    printf("8) Display All Reservations\n");
    printf("9) Exit\n");
    printf("\n");
}

void addNewRoom(struct Hotel *hotel) {
    int number, capacity, price;
    char type[20];

    printf("\n");
    printf("Enter Room Number: ");
    scanf("%d", &number);
    printf("Enter Room Capacity: ");
    scanf("%d", &capacity);
    printf("Enter Room Type: ");
    scanf("%s", type);
    printf("Enter Room Price: ");
    scanf("%d", &price);

    hotel->rooms[hotel->numRooms].number = number;
    hotel->rooms[hotel->numRooms].capacity = capacity;
    strcpy(hotel->rooms[hotel->numRooms].type, type);
    hotel->rooms[hotel->numRooms].price = price;
    hotel->rooms[hotel->numRooms].status = 0;

    hotel->numRooms++;

    printf("Room Added Successfully!\n");
}

void editRoomDetails(struct Hotel *hotel) {
    int number, choice;

    printf("\n");
    printf("Enter Room Number to Edit: ");
    scanf("%d", &number);

    int roomIndex = -1;
    for (int i = 0; i < hotel->numRooms; i++) {
        if (hotel->rooms[i].number == number) {
            roomIndex = i;
            break;
        }
    }

    if (roomIndex == -1) {
        printf("Room Not Found!\n");
        return;
    }

    printf("\n");
    printf("Room Details:\n");
    printf("1) Room Number: %d\n", hotel->rooms[roomIndex].number);
    printf("2) Room Capacity: %d\n", hotel->rooms[roomIndex].capacity);
    printf("3) Room Type: %s\n", hotel->rooms[roomIndex].type);
    printf("4) Room Price: %d\n", hotel->rooms[roomIndex].price);
    printf("Enter Option Number to Edit: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter New Room Number: ");
            scanf("%d", &hotel->rooms[roomIndex].number);
            break;
        case 2:
            printf("Enter New Room Capacity: ");
            scanf("%d", &hotel->rooms[roomIndex].capacity);
            break;
        case 3:
            printf("Enter New Room Type: ");
            scanf("%s", hotel->rooms[roomIndex].type);
            break;
        case 4:
            printf("Enter New Room Price: ");
            scanf("%d", &hotel->rooms[roomIndex].price);
            break;
        default:
            printf("Invalid Option Number!\n");
            return;
    }

    printf("Room Details Updated Successfully!\n");
}

void searchRoomByType(struct Hotel *hotel) {
    char type[20];

    printf("\n");
    printf("Enter Room Type to Search: ");
    scanf("%s", type);

    printf("\n");
    printf("Search Results:\n");

    for (int i = 0; i < hotel->numRooms; i++) {
        if (strcmp(hotel->rooms[i].type, type) == 0 && hotel->rooms[i].status == 0) {
            printf("Room Number: %d\n", hotel->rooms[i].number);
            printf("Room Capacity: %d\n", hotel->rooms[i].capacity);
            printf("Room Type: %s\n", hotel->rooms[i].type);
            printf("Room Price: %d\n", hotel->rooms[i].price);
            printf("Room Status: Available\n");
            printf("\n");
        }
    }

    printf("End of Search Results.\n");
}

void displayAllRooms(struct Hotel *hotel) {
    printf("\n");
    printf("All Rooms:\n");
    for (int i = 0; i < hotel->numRooms; i++) {
        printf("Room Number: %d\n", hotel->rooms[i].number);
        printf("Room Capacity: %d\n", hotel->rooms[i].capacity);
        printf("Room Type: %s\n", hotel->rooms[i].type);
        printf("Room Price: %d\n", hotel->rooms[i].price);
        if (hotel->rooms[i].status == 0) {
            printf("Room Status: Available\n");
        } else {
            printf("Room Status: Occupied\n");
        }
        printf("\n");
    }
}

void makeReservation(struct Hotel *hotel) {
    char guestName[50], guestPhone[20];
    int numDays, roomNumber;

    printf("\n");
    printf("Enter Guest Name: ");
    scanf("%s", guestName);
    printf("Enter Guest Phone Number: ");
    scanf("%s", guestPhone);
    printf("Enter Number of Days: ");
    scanf("%d", &numDays);

    printf("\n");
    printf("Search for Available Rooms:\n");
    searchRoomByType(hotel);

    printf("Enter Room Number to Reserve: ");
    scanf("%d", &roomNumber);

    int roomIndex = -1;
    for (int i = 0; i < hotel->numRooms; i++) {
        if (hotel->rooms[i].number == roomNumber) {
            roomIndex = i;
            break;
        }
    }

    if (roomIndex == -1) {
        printf("Room Not Found!\n");
        return;
    }

    if (hotel->rooms[roomIndex].status == 1) {
        printf("Room Already Occupied!\n");
        return;
    }

    strcpy(hotel->reservations[hotel->numReservations].guestName, guestName);
    strcpy(hotel->reservations[hotel->numReservations].guestPhone, guestPhone);
    hotel->reservations[hotel->numReservations].numDays = numDays;
    hotel->reservations[hotel->numReservations].roomNumber = roomNumber;

    hotel->rooms[roomIndex].status = 1;

    hotel->numReservations++;

    printf("Reservation Made Successfully!\n");
}

void editReservationDetails(struct Hotel *hotel) {
    char guestPhone[20];
    int choice, roomNumber;

    printf("\n");
    printf("Enter Guest Phone Number to Edit Reservation: ");
    scanf("%s", guestPhone);

    int reservationIndex = -1;
    for (int i = 0; i < hotel->numReservations; i++) {
        if (strcmp(hotel->reservations[i].guestPhone, guestPhone) == 0) {
            reservationIndex = i;
            break;
        }
    }

    if (reservationIndex == -1) {
        printf("Reservation Not Found!\n");
        return;
    }

    printf("\n");
    printf("Reservation Details:\n");
    printf("1) Guest Name: %s\n", hotel->reservations[reservationIndex].guestName);
    printf("2) Guest Phone: %s\n", hotel->reservations[reservationIndex].guestPhone);
    printf("3) Number of Days: %d\n", hotel->reservations[reservationIndex].numDays);
    printf("4) Room Number: %d\n", hotel->reservations[reservationIndex].roomNumber);
    printf("Enter Option Number to Edit: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter New Guest Name: ");
            scanf("%s", hotel->reservations[reservationIndex].guestName);
            break;
        case 2:
            printf("Enter New Guest Phone: ");
            scanf("%s", hotel->reservations[reservationIndex].guestPhone);
            break;
        case 3:
            printf("Enter New Number of Days: ");
            scanf("%d", &hotel->reservations[reservationIndex].numDays);
            break;
        case 4:
            printf("\n");
            printf("Search for Available Rooms:\n");
            searchRoomByType(hotel);
            printf("Enter New Room Number: ");
            scanf("%d", &roomNumber);

            int oldRoomIndex = -1;
            for (int i = 0; i < hotel->numRooms; i++) {
                if (hotel->rooms[i].number == hotel->reservations[reservationIndex].roomNumber) {
                    oldRoomIndex = i;
                    break;
                }
            }

            if (oldRoomIndex == -1) {
                printf("Old Room Not Found!\n");
                return;
            }

            hotel->rooms[oldRoomIndex].status = 0;

            int newRoomIndex = -1;
            for (int i = 0; i < hotel->numRooms; i++) {
                if (hotel->rooms[i].number == roomNumber) {
                    newRoomIndex = i;
                    break;
                }
            }

            if (newRoomIndex == -1) {
                printf("New Room Not Found!\n");
                return;
            }

            if (hotel->rooms[newRoomIndex].status == 1) {
                printf("New Room Already Occupied!\n");
                return;
            }

            hotel->reservations[reservationIndex].roomNumber = roomNumber;
            hotel->rooms[newRoomIndex].status = 1;

            break;
        default:
            printf("Invalid Option Number!\n");
            return;
    }

    printf("Reservation Details Updated Successfully!\n");
}

void cancelReservation(struct Hotel *hotel) {
    char guestPhone[20];

    printf("\n");
    printf("Enter Guest Phone Number to Cancel Reservation: ");
    scanf("%s", guestPhone);

    int reservationIndex = -1;
    for (int i = 0; i < hotel->numReservations; i++) {
        if (strcmp(hotel->reservations[i].guestPhone, guestPhone) == 0) {
            reservationIndex = i;
            break;
        }
    }

    if (reservationIndex == -1) {
        printf("Reservation Not Found!\n");
        return;
    }

    int roomIndex = -1;
    for (int i = 0; i < hotel->numRooms; i++) {
        if (hotel->rooms[i].number == hotel->reservations[reservationIndex].roomNumber) {
            roomIndex = i;
            break;
        }
    }

    if (roomIndex == -1) {
        printf("Room Not Found!\n");
        return;
    }

    hotel->rooms[roomIndex].status = 0;

    for (int i = reservationIndex; i < hotel->numReservations - 1; i++) {
        strcpy(hotel->reservations[i].guestName, hotel->reservations[i + 1].guestName);
        strcpy(hotel->reservations[i].guestPhone, hotel->reservations[i + 1].guestPhone);
        hotel->reservations[i].numDays = hotel->reservations[i + 1].numDays;
        hotel->reservations[i].roomNumber = hotel->reservations[i + 1].roomNumber;
    }

    hotel->numReservations--;

    printf("Reservation Cancelled Successfully!\n");
}

void displayAllReservations(struct Hotel *hotel) {
    printf("\n");
    printf("All Reservations:\n");
    for (int i = 0; i < hotel->numReservations; i++) {
        printf("Guest Name: %s\n", hotel->reservations[i].guestName);
        printf("Guest Phone: %s\n", hotel->reservations[i].guestPhone);
        printf("Number of Days: %d\n", hotel->reservations[i].numDays);
        printf("Room Number: %d\n", hotel->reservations[i].roomNumber);
        printf("\n");
    }
}

int main() {
    struct Hotel hotel;
    strcpy(hotel.name, "Grand Hotel");
    hotel.numRooms = 0;
    hotel.numReservations = 0;

    int choice;

    do {
        printMenu();

        printf("Enter Option Number: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addNewRoom(&hotel);
                break;
            case 2:
                editRoomDetails(&hotel);
                break;
            case 3:
                searchRoomByType(&hotel);
                break;
            case 4:
                displayAllRooms(&hotel);
                break;
            case 5:
                makeReservation(&hotel);
                break;
            case 6:
                editReservationDetails(&hotel);
                break;
            case 7:
                cancelReservation(&hotel);
                break;
            case 8:
                displayAllReservations(&hotel);
                break;
            case 9:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Option Number!\n");
                break;
        }
    } while (choice != 9);

    return 0;
}