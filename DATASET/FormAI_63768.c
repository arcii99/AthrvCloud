//FormAI DATASET v1.0 Category: Hotel Management System ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int room_number;
    char occupant[50];
    float price;
} Room;

typedef struct {
    char name[50];
    Room rooms[50];
    int num_rooms;
} Hotel;

//function declarations
void print_hotel(Hotel h);
void add_room(Hotel *h, int room_number, float price, char occupant[]);
void remove_room(Hotel *h, int room_number);

int main() {
    Hotel h1 = {"Hilton", {}, 0}; //initialize hotel with no rooms
    add_room(&h1, 101, 150.00, "John Smith"); //add a room
    add_room(&h1, 102, 100.00, "Jane Doe"); //add another room
    print_hotel(h1); //print hotel information
    remove_room(&h1, 101); //remove a room
    print_hotel(h1); //print updated hotel information

    return 0;
}

void add_room(Hotel *h, int room_number, float price, char occupant[]) {
    Room r = {room_number, "", price}; //initialize room with empty occupant field
    strncpy(r.occupant, occupant, sizeof(r.occupant) - 1); //copy occupant name to room
    h->rooms[h->num_rooms] = r; //add room to hotel's room array
    h->num_rooms++; //increment number of rooms in hotel
}

void remove_room(Hotel *h, int room_number) {
    int i, j;
    for(i = 0; i < h->num_rooms; i++) {
        if(h->rooms[i].room_number == room_number) { //find the room to remove
            for(j = i; j < h->num_rooms - 1; j++) {
                h->rooms[j] = h->rooms[j + 1]; //shift all following rooms left by one
            }
            h->num_rooms--; //decrement number of rooms in hotel
            break; //exit loop once room is found and removed
        }
    }
}

void print_hotel(Hotel h) {
    int i;
    printf("Hotel Name: %s\n", h.name);
    printf("Total Rooms: %d\n", h.num_rooms);
    printf("Room Information:\n");
    for(i = 0; i < h.num_rooms; i++) {
        printf("Room %d\n", h.rooms[i].room_number);
        printf("Occupant: %s\n", h.rooms[i].occupant);
        printf("Price: %.2f\n", h.rooms[i].price);
    }
    printf("---\n");
}