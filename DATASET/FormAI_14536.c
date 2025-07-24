//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_ROOMS 5

struct Room {
    int id;
    char* description;
    char* items[3];
    struct Room* connected_rooms[4];
    int num_connected;
};

struct Room* create_room(int id, char* desc, char* item1, char* item2, char* item3) {
    struct Room* room = (struct Room*)malloc(sizeof(struct Room));
    room->id = id;
    room->description = desc;
    room->items[0] = item1;
    room->items[1] = item2;
    room->items[2] = item3;
    room->num_connected = 0;
    return room;
}

void connect_rooms(struct Room* room1, struct Room* room2) {
    if (room1->num_connected < 4) {
        room1->connected_rooms[room1->num_connected] = room2;
        room1->num_connected++;
    }
    if (room2->num_connected < 4) {
        room2->connected_rooms[room2->num_connected] = room1;
        room2->num_connected++;
    }
}

void print_room_info(struct Room* room) {
    printf("\nRoom %d - %s\n", room->id, room->description);
    printf("Items in the room: [%s, %s, %s]\n", room->items[0], room->items[1], room->items[2]);
    printf("Connected rooms: ");
    for (int i=0; i<room->num_connected; i++) {
        printf("%d ", room->connected_rooms[i]->id);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    char* item_names[] = {"Knife", "Flashlight", "Candle", "Book", "Wire"};
    char* room_descs[] = {"A musty room with a creaky door", 
                          "An abandoned kitchen with broken shelves", 
                          "A dark hallway with flickering lights", 
                          "A cavernous living room with moth-eaten furniture", 
                          "A small bathroom with shattered mirrors"};
    
    int starting_room_id = rand() % MAX_ROOMS;
    struct Room* rooms[MAX_ROOMS];
    rooms[0] = create_room(0, room_descs[0], item_names[0], item_names[1], item_names[2]);
    rooms[1] = create_room(1, room_descs[1], item_names[3], item_names[4], item_names[0]);
    rooms[2] = create_room(2, room_descs[2], item_names[1], item_names[2], item_names[3]);
    rooms[3] = create_room(3, room_descs[3], item_names[4], item_names[0], item_names[1]);
    rooms[4] = create_room(4, room_descs[4], item_names[2], item_names[3], item_names[4]);

    connect_rooms(rooms[0], rooms[1]);
    connect_rooms(rooms[0], rooms[2]);
    connect_rooms(rooms[1], rooms[2]);
    connect_rooms(rooms[3], rooms[2]);
    connect_rooms(rooms[3], rooms[4]);

    struct Room* current_room = rooms[starting_room_id];
    printf("\nWelcome to the Haunted House! You have entered Room %d.\n", current_room->id);
    print_room_info(current_room);

    int gameOver = 0;
    while (!gameOver) {
        printf("Enter a direction to move (n/e/s/w): ");
        char input;
        scanf(" %c", &input);

        switch(input) {
            case 'n':
                if (current_room->connected_rooms[0] != NULL) {
                    printf("Moving north...\n");
                    current_room = current_room->connected_rooms[0];
                    print_room_info(current_room);
                } else {
                    printf("Can't move in that direction.\n");
                }
                break;

            case 'e':
                if (current_room->connected_rooms[1] != NULL) {
                    printf("Moving east...\n");
                    current_room = current_room->connected_rooms[1];
                    print_room_info(current_room);
                } else {
                    printf("Can't move in that direction.\n");
                }
                break;

            case 's':
                if (current_room->connected_rooms[2] != NULL) {
                    printf("Moving south...\n");
                    current_room = current_room->connected_rooms[2];
                    print_room_info(current_room);
                } else {
                    printf("Can't move in that direction.\n");
                }
                break;

            case 'w':
                if (current_room->connected_rooms[3] != NULL) {
                    printf("Moving west...\n");
                    current_room = current_room->connected_rooms[3];
                    print_room_info(current_room);
                } else {
                    printf("Can't move in that direction.\n");
                }
                break;

            default:
                printf("Invalid input. Try again.\n");
                break;
        }

        printf("Enter 'q' to quit, or any other key to continue exploring: ");
        char playAgain;
        scanf(" %c", &playAgain);
        if (playAgain == 'q') {
            printf("Leaving the haunted house...\n");
            gameOver = 1;
        }
    }

    for (int i=0; i<MAX_ROOMS; i++) {
        free(rooms[i]);
    }

    return 0;
}