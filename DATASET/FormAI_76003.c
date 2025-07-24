//FormAI DATASET v1.0 Category: Hotel Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

struct Guest {
    char name[100];
    int room_number;
    int num_of_nights;
    float room_price;
    float total_price;
};

struct Room {
    int room_number;
    int capacity;
    char room_type[100];
    float price_per_night;
    int is_available;
};

int main() {
    struct Room rooms[10];
    for (int i = 0; i < 10; i++) {
        rooms[i].room_number = i + 1;
        rooms[i].capacity = 2;
        strcpy(rooms[i].room_type, "Double");
        rooms[i].price_per_night = 75.0;
        rooms[i].is_available = 1;
    }

    int num_of_guests = 0;
    struct Guest guests[10];

    while (1) {
        printf("Enter 1 to book a room, 2 to check out, or 3 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (num_of_guests >= 10) {
                printf("Sorry, the hotel is fully booked.\n");
            } else {
                printf("Enter guest name: ");
                scanf("%s", guests[num_of_guests].name);

                int room_found = 0;
                while (!room_found) {
                    printf("Enter desired room type (Single or Double): ");
                    char desired_room_type[100];
                    scanf("%s", desired_room_type);

                    for (int i = 0; i < 10; i++) {
                        if (rooms[i].is_available && strcmp(rooms[i].room_type, desired_room_type) == 0) {
                            guests[num_of_guests].room_number = rooms[i].room_number;
                            rooms[i].is_available = 0;
                            room_found = 1;
                            break;
                        }
                    }

                    if (!room_found) {
                        printf("Sorry, no available %s rooms. Please try again.\n", desired_room_type);
                    }
                }

                printf("Enter number of nights: ");
                scanf("%d", &guests[num_of_guests].num_of_nights);

                for (int i = 0; i < 10; i++) {
                    if (rooms[i].room_number == guests[num_of_guests].room_number) {
                        guests[num_of_guests].room_price = guests[num_of_guests].num_of_nights * rooms[i].price_per_night;
                        guests[num_of_guests].total_price = guests[num_of_guests].room_price;
                        printf("Room booked for %s. Room number: %d. Total price: $%.2f.\n", guests[num_of_guests].name, guests[num_of_guests].room_number, guests[num_of_guests].total_price);
                        num_of_guests++;
                        break;
                    }
                }
            }
        } else if (choice == 2) {
            int room_number;
            printf("Enter room number: ");
            scanf("%d", &room_number);

            float checkout_price = 0.0;
            for (int i = 0; i < num_of_guests; i++) {
                if (guests[i].room_number == room_number) {
                    checkout_price = guests[i].total_price;
                    for (int j = i + 1; j < num_of_guests; j++) {
                        guests[j - 1] = guests[j];
                    }
                    num_of_guests--;
                    break;
                }
            }

            for (int i = 0; i < 10; i++) {
                if (rooms[i].room_number == room_number) {
                    rooms[i].is_available = 1;
                    break;
                }
            }

            printf("Thank you for staying with us! Your total price is $%.2f.\n", checkout_price);
        } else if (choice == 3) {
            printf("Goodbye!");
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}