//FormAI DATASET v1.0 Category: Hotel Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOTELS 100
#define MAX_ROOMS 1000

typedef struct {
    int room_number;
    char guest_name[30];
    int occupancy_status;
} Room;

typedef struct {
    int hotel_id;
    char hotel_name[50];
    Room rooms[MAX_ROOMS];
} Hotel;

Hotel hotels[MAX_HOTELS];

int num_hotels = 0;
int num_rooms = 0;

void add_hotel() {
    printf("Enter details of hotel %d:\n", num_hotels+1);
    printf("Enter hotel ID: ");
    scanf("%d", &hotels[num_hotels].hotel_id);
    printf("Enter hotel name: ");
    getchar();
    fgets(hotels[num_hotels].hotel_name, 50, stdin);
    strtok(hotels[num_hotels].hotel_name, "\n");

    printf("How many rooms in the hotel? ");
    int num;
    scanf("%d", &num);

    for(int i=0;i<num;i++) {
        hotels[num_hotels].rooms[i].room_number = num_rooms+1;
        hotels[num_hotels].rooms[i].occupancy_status = 0;

        printf("Enter name for room %d: ", i+1);
        getchar();
        fgets(hotels[num_hotels].rooms[i].guest_name, 30, stdin);
        strtok(hotels[num_hotels].rooms[i].guest_name, "\n");

        num_rooms++;
    }

    num_hotels++;
}

void list_all_hotels() {
    if(num_hotels == 0) {
        printf("No hotels found.\n");
        return;
    }
    printf("List of all hotels:\n");
    for(int i=0;i<num_hotels;i++) {
        printf("%d. %s\n", hotels[i].hotel_id, hotels[i].hotel_name);
    }
}

void list_all_rooms() {
    if(num_rooms == 0) {
        printf("No rooms found.\n");
        return;
    }
    printf("List of all rooms:\n");
    for(int i=0;i<num_hotels;i++) {
        printf("Rooms in hotel %d (%s):\n", hotels[i].hotel_id, hotels[i].hotel_name);
        for(int j=0;j<num_rooms;j++) {
            if(hotels[i].rooms[j].occupancy_status == 0) {
                printf("Room %d: Empty\n", hotels[i].rooms[j].room_number);
            } else {
                printf("Room %d: %s\n", hotels[i].rooms[j].room_number, hotels[i].rooms[j].guest_name);
            }
        }
    }
}

void check_in() {
    int hotel_id, room_number;
    char guest_name[30];
    printf("Enter hotel ID: ");
    scanf("%d", &hotel_id);
    printf("Enter room number: ");
    scanf("%d", &room_number);
    getchar();
    printf("Enter guest name: ");
    fgets(guest_name, 30, stdin);
    strtok(guest_name, "\n");

    for(int i=0;i<num_hotels;i++) {
        if(hotels[i].hotel_id == hotel_id) {
            for(int j=0;j<num_rooms;j++) {
                if(hotels[i].rooms[j].room_number == room_number) {
                    if(hotels[i].rooms[j].occupancy_status == 1) {
                        printf("Room is already occupied.\n");
                        return;
                    } else {
                        strncpy(hotels[i].rooms[j].guest_name, guest_name, 30);
                        hotels[i].rooms[j].occupancy_status = 1;
                        printf("Checked in successfully.\n");
                        return;
                    }
                }
            }
        }
    }
    printf("Room not found.\n");
}

void check_out() {
    int hotel_id, room_number;
    printf("Enter hotel ID: ");
    scanf("%d", &hotel_id);
    printf("Enter room number: ");
    scanf("%d", &room_number);

    for(int i=0;i<num_hotels;i++) {
        if(hotels[i].hotel_id == hotel_id) {
            for(int j=0;j<num_rooms;j++) {
                if(hotels[i].rooms[j].room_number == room_number) {
                    if(hotels[i].rooms[j].occupancy_status == 0) {
                        printf("Room is not occupied.\n");
                        return;
                    } else {
                        hotels[i].rooms[j].occupancy_status = 0;
                        printf("Checked out successfully.\n");
                        return;
                    }
                }
            }
        }
    }
    printf("Room not found.\n");
}

int main() {
    printf("Welcome to our C Hotel Management System!\n");

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add hotel\n");
        printf("2. List all hotels\n");
        printf("3. List all rooms\n");
        printf("4. Check in\n");
        printf("5. Check out\n");
        printf("6. Exit\n");
        printf("Enter option number: ");

        int opt;
        scanf("%d", &opt);

        switch(opt) {
            case 1: add_hotel(); break;
            case 2: list_all_hotels(); break;
            case 3: list_all_rooms(); break;
            case 4: check_in(); break;
            case 5: check_out(); break;
            case 6: printf("Thank you for using our Hotel Management System!\n"); exit(0);
            default: printf("Invalid option.\n");
        }
    }

    return 0;
}