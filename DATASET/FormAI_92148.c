//FormAI DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOTELS 10
#define MAX_ROOMS 100

typedef struct {
    char name[50];
    int id;
} Hotel;

typedef struct {
    int roomNumber;
    int capacity;
    int price;
    int hotelId;
} Room;

Hotel hotels[MAX_HOTELS];
int numHotels = 0;

Room rooms[MAX_ROOMS];
int numRooms = 0;

int main() {
    int option;
    do {
        printf("Hotel Management System\n");
        printf("1 - Add Hotel\n");
        printf("2 - Add Room\n");
        printf("3 - Show all rooms at hotel\n");
        printf("4 - Find cheapest room in hotel\n");
        printf("5 - Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addHotel();
                break;
            case 2:
                addRoom();
                break;
            case 3:
                showAllRoomsAtHotel();
                break;
            case 4:
                findCheapestRoomInHotel();
                break;
        }
    } while (option != 5);

    return 0;
}

void addHotel() {
    if (numHotels == MAX_HOTELS) {
        printf("Maximum hotels reached.\n");
        return;
    }

    printf("Enter hotel name: ");
    scanf("%s", hotels[numHotels].name);
    hotels[numHotels].id = numHotels + 1;

    numHotels++;

    printf("Hotel added successfully.\n");
}

void addRoom() {
    if (numRooms == MAX_ROOMS) {
        printf("Maximum rooms reached.\n");
        return;
    }

    printf("Enter room number: ");
    scanf("%d", &rooms[numRooms].roomNumber);

    printf("Enter room capacity: ");
    scanf("%d", &rooms[numRooms].capacity);

    printf("Enter room price: ");
    scanf("%d", &rooms[numRooms].price);

    printf("Enter hotel ID: ");
    scanf("%d", &rooms[numRooms].hotelId);

    numRooms++;

    printf("Room added successfully.\n");
}

void showAllRoomsAtHotel() {
    int hotelId;

    printf("Enter hotel ID: ");
    scanf("%d", &hotelId);

    printf("Rooms at hotel %s:\n", hotels[hotelId - 1].name);

    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].hotelId == hotelId) {
            printf("Room %d - Capacity: %d - Price: %d\n", rooms[i].roomNumber, rooms[i].capacity, rooms[i].price);
        }
    }
}

void findCheapestRoomInHotel() {
    int hotelId;
    int cheapestPrice = -1;

    printf("Enter hotel ID: ");
    scanf("%d", &hotelId);

    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].hotelId == hotelId) {
            if (cheapestPrice == -1 || rooms[i].price < cheapestPrice) {
                cheapestPrice = rooms[i].price;
            }
        }
    }

    if (cheapestPrice == -1) {
        printf("No rooms found at hotel %s\n", hotels[hotelId - 1].name);
    } else {
        printf("Cheapest room at hotel %s is $%d\n", hotels[hotelId - 1].name, cheapestPrice);
    }
}