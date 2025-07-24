//FormAI DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct room_t {
    int number;
    int price;
    char occupancy[20];
    char amenities[100];
} Room;

Room createRoom(int number, int price, char* occupancy, char* amenities) {
    Room r;
    r.number = number;
    r.price = price;
    strcpy(r.occupancy, occupancy);
    strcpy(r.amenities, amenities);
    return r;
}

void printRoom(Room r) {
    printf("Room Number: %d\n", r.number);
    printf("Occupancy: %s\n", r.occupancy);
    printf("Amenities: %s\n", r.amenities);
    printf("Price: %d\n", r.price);
}

int main() {
    Room rooms[10];
    rooms[0] = createRoom(101, 200, "Single", "TV, AC");
    rooms[1] = createRoom(102, 300, "Single", "TV, AC, Mini Fridge");
    rooms[2] = createRoom(201, 250, "Double", "TV, AC");
    rooms[3] = createRoom(202, 350, "Double", "TV, AC, Mini Fridge");
    rooms[4] = createRoom(301, 300, "Triple", "TV, AC");
    rooms[5] = createRoom(302, 450, "Triple", "TV, AC, Mini Fridge");
    rooms[6] = createRoom(401, 350, "Quad", "TV, AC");
    rooms[7] = createRoom(402, 500, "Quad", "TV, AC, Mini Fridge");
    rooms[8] = createRoom(501, 400, "Suite", "TV, AC, Mini Fridge, Jacuzzi");
    rooms[9] = createRoom(502, 600, "Suite", "TV, AC, Mini Fridge, Jacuzzi, Balcony");

    printf("Welcome to the C Hotel Management System!\n");
    printf("----------------------------------------\n");
    printf("Enter the desired room number (101-502): ");
    int roomNumber;
    scanf("%d", &roomNumber);

    if (roomNumber < 101 || roomNumber > 502) {
        printf("Invalid room number. Exiting...\n");
        exit(0);
    }

    Room selectedRoom;
    for (int i = 0; i < 10; i++) {
        if (rooms[i].number == roomNumber) {
            selectedRoom = rooms[i];
        }
    }

    printf("\n");
    printf("Room Details\n");
    printf("-------------\n");
    printRoom(selectedRoom);

    return 0;
}