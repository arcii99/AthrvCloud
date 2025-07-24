//FormAI DATASET v1.0 Category: Hotel Management System ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 50

typedef struct {
    int room_number;
    int num_guests;
    char guest_names[MAX_GUESTS][50];
} Room;

typedef struct {
    Room rooms[MAX_ROOMS];
    int num_rooms;
} Hotel;

int find_empty_room(Hotel* hotel) {
    int i;
    for (i = 0; i < hotel->num_rooms; i++) {
        if (hotel->rooms[i].num_guests == 0) return i;
    }
    return -1;
}

void add_guest(Hotel* hotel) {
    int room_num = find_empty_room(hotel);
    if (room_num == -1) {
        printf("Sorry, all rooms are occupied.\n");
        return;
    }
    Room* room = &hotel->rooms[room_num];
    printf("Enter guest names (one per line, \"done\" to finish):\n");
    char name[50];
    while (fgets(name, 50, stdin)) {
        if (strcmp(name, "done\n") == 0) break;
        name[strlen(name)-1] = '\0';
        strcpy(room->guest_names[room->num_guests], name);
        room->num_guests++;
    }
    printf("Guests added to room %d.\n", room->room_number);
}

void list_guests(Hotel* hotel) {
    int i, j;
    for (i = 0; i < hotel->num_rooms; i++) {
        Room* room = &hotel->rooms[i];
        printf("Room %03d: ", room->room_number);
        for (j = 0; j < room->num_guests; j++) {
            printf("%s", room->guest_names[j]);
            if (j != room->num_guests - 1) printf(", ");
        }
        printf("\n");
    }
}

int main() {
    Hotel hotel = {{0}, 0};
    int choice;
    do {
        printf("MENU:\n");
        printf("1. Add guests\n");
        printf("2. List guests\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // eat newline
        switch (choice) {
            case 1: add_guest(&hotel); break;
            case 2: list_guests(&hotel); break;
            case 3: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n"); break;
        }
    } while (choice != 3);
    return 0;
}