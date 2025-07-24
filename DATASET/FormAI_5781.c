//FormAI DATASET v1.0 Category: Hotel Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the number of amenities available in the hotel
#define NUM_AMENITIES 5

// Define a structure for each room in the hotel
typedef struct Room {
    int number;
    int beds;
    float price;
    char occupancy[10];
    char amenities[NUM_AMENITIES][30];
} Room;

// Define a structure for the hotel
typedef struct Hotel {
    char name[50];
    Room rooms[MAX_ROOMS];
    int numRooms;
} Hotel;

// Define a function to add a room to the hotel
void addRoom(Hotel *h, int number, int beds, float price, char *occupancy, char amenities[][30], int numAmenities) {
    // Check if the hotel is full
    if (h->numRooms >= MAX_ROOMS) {
        printf("Hotel is full. Cannot add another room.\n");
        return;
    }
    // Add the room
    Room r;
    r.number = number;
    r.beds = beds;
    r.price = price;
    strcpy(r.occupancy, occupancy);
    for (int i = 0; i < numAmenities; i++) {
        strcpy(r.amenities[i], amenities[i]);
    }
    h->rooms[h->numRooms++] = r;
    printf("Room %d added successfully.\n", number);
}

// Define a function to remove a room from the hotel
void removeRoom(Hotel *h, int number) {
    // Find the room
    int found = 0;
    for (int i = 0; i < h->numRooms; i++) {
        if (h->rooms[i].number == number) {
            // Shift all the rooms after this room up by one
            for (int j = i; j < h->numRooms - 1; j++) {
                h->rooms[j] = h->rooms[j+1];
            }
            h->numRooms--;
            printf("Room %d removed successfully.\n", number);
            found = 1;
            break;
        }
    }
    // If the room was not found, print an error message
    if (!found) {
        printf("Room %d not found.\n", number);
    }
}

// Define a function to search for a room by number
Room *searchRoom(Hotel *h, int number) {
    // Find the room
    for (int i = 0; i < h->numRooms; i++) {
        if (h->rooms[i].number == number) {
            return &h->rooms[i];
        }
    }
    // If the room was not found, return NULL
    return NULL;
}

// Define a function to print the details of a room
void printRoom(Room *r) {
    printf("Room %d, %s occupancy, %d beds, $%.2f per night\n", r->number, r->occupancy, r->beds, r->price);
    printf("Amenities: ");
    for (int i = 0; i < NUM_AMENITIES; i++) {
        if (strcmp(r->amenities[i], "") != 0) {
            printf("%s ", r->amenities[i]);
        }
    }
    printf("\n");
}

// Define a function to print the details of all the rooms in the hotel
void printRooms(Hotel *h) {
    printf("%s\n", h->name);
    printf("Total number of rooms: %d\n", h->numRooms);
    for (int i = 0; i < h->numRooms; i++) {
        printRoom(&h->rooms[i]);
    }
}

int main() {
    // Create a hotel
    Hotel h;
    strcpy(h.name, "Hotel California");
    h.numRooms = 0;

    // Add some rooms to the hotel
    char amenities1[][30] = {"Free WiFi", "Flat-screen TV", "Mini-fridge"};
    addRoom(&h, 101, 1, 99.99, "Single", amenities1, 3);
    char amenities2[][30] = {"Free WiFi", "Flat-screen TV", "Mini-fridge", "Sea view"};
    addRoom(&h, 102, 2, 149.99, "Double", amenities2, 4);
    char amenities3[][30] = {"Free WiFi", "Flat-screen TV", "Mini-fridge", "Balcony"};
    addRoom(&h, 103, 1, 109.99, "Single", amenities3, 4);

    // Print the details of the hotel
    printRooms(&h);

    // Search for a room by number
    Room *r = searchRoom(&h, 102);
    if (r != NULL) {
        printRoom(r);
    } else {
        printf("Room not found.\n");
    }

    // Remove a room from the hotel
    removeRoom(&h, 101);

    // Print the details of the hotel again
    printRooms(&h);

    return 0;
}