//FormAI DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
    char type[20];
    int num_rooms;
    int price;
};

struct booking {
    char name[50];
    int room_no;
    int duration;
};

int main() {
    struct room rooms[5];
    strcpy(rooms[0].type, "Single");
    rooms[0].num_rooms = 5;
    rooms[0].price = 10;
    strcpy(rooms[1].type, "Double");
    rooms[1].num_rooms = 5;
    rooms[1].price = 20;
    strcpy(rooms[2].type, "Triple");
    rooms[2].num_rooms = 5;
    rooms[2].price = 30;
    strcpy(rooms[3].type, "Quad");
    rooms[3].num_rooms = 5;
    rooms[3].price = 40;
    strcpy(rooms[4].type, "Suite");
    rooms[4].num_rooms = 5;
    rooms[4].price = 50;

    struct booking bookings[50];
    int num_bookings = 0;

    int choice;
    int room_choice;
    int duration;
    int room_found;
    char name[50];

    while (1) {
        printf("Welcome to our Medieval Hotel Management System\n");
        printf("1. Book a room\n");
        printf("2. View all bookings\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Which type of room would you like to book?\n");
                printf("1. Single\n");
                printf("2. Double\n");
                printf("3. Triple\n");
                printf("4. Quad\n");
                printf("5. Suite\n");

                scanf("%d", &room_choice);

                printf("Please enter your name: ");
                scanf("%s", name);

                printf("How many nights would you like to stay? ");
                scanf("%d", &duration);

                room_found = 0;
                for (int i = 0; i < 5; i++) {
                    if (strcmp(rooms[i].type, rooms[room_choice-1].type) == 0) {
                        if (rooms[i].num_rooms > 0) {
                            bookings[num_bookings].room_no = i+1;
                            strcpy(bookings[num_bookings].name, name);
                            bookings[num_bookings].duration = duration;
                            rooms[i].num_rooms--;
                            num_bookings++;
                            printf("Booking confirmed! Your room number is %d\n", i+1);
                            room_found = 1;
                            break;
                        }
                    }
                }

                if (!room_found) {
                    printf("Sorry, we do not have that room type available for your selected dates.\n");
                }

                break;
            case 2:
                printf("Printing All Bookings:\n");
                printf("Room No.\tGuest Name\tDuration\n");
                for (int i = 0; i < num_bookings; i++) {
                    printf("%d\t\t%s\t\t%d\n", bookings[i].room_no, bookings[i].name, bookings[i].duration);
                }
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}