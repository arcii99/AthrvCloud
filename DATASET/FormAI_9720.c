//FormAI DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[20];
    int age;
    char gender[10];
    char address[100];
    int room_no;
} Guest;

typedef struct {
    int room_no;
    char type[20];
    int price;
    int availability;
} Room;

void guest_menu(Guest* guests, int* counter);
void room_menu(Room* rooms, int num_rooms);

int main() {
    int num_rooms;
    printf("Welcome to the C Hotel Management System\n");
    printf("Please enter the number of rooms in the hotel: ");
    scanf("%d", &num_rooms);

    Room* rooms = (Room*)malloc(num_rooms * sizeof(Room));
    for (int i = 0; i < num_rooms; i++) {
        rooms[i].room_no = i+1;
        printf("Please enter the type of room #%d: ", i+1);
        scanf("%s", rooms[i].type);
        printf("Please enter the price of room #%d: ", i+1);
        scanf("%d", &rooms[i].price);
        rooms[i].availability = 1;
    }

    Guest* guests = (Guest*)malloc(num_rooms * sizeof(Guest)); 
    int counter = 0;

    int choice;

    do {
        printf("\n*****MAIN MENU*****\n");
        printf("1. Guest Menu\n");
        printf("2. Room Menu\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                guest_menu(guests, &counter);
                break;
            case 2:
                room_menu(rooms, num_rooms);
                break;
            case 3:
                printf("Thank you for using C Hotel Management System.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    free(rooms);
    free(guests);

    return 0;
}

void guest_menu(Guest* guests, int* counter) {
    int choice;

    do {
        printf("\n*****GUEST MENU*****\n");
        printf("1. Check In\n");
        printf("2. Check Out\n");
        printf("3. View Guests\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (*counter < 1) {
                    printf("No available rooms.\n");
                    break;
                }
                printf("Enter guest name: ");
                scanf("%s", guests[*counter].name);
                printf("Enter guest age: ");
                scanf("%d", &guests[*counter].age);
                printf("Enter guest gender: ");
                scanf("%s", guests[*counter].gender);
                printf("Enter guest address: ");
                scanf("%s", guests[*counter].address);
                int room_choice;
                do {
                    printf("Choose room number (1-%d): ", *counter);
                    scanf("%d", &room_choice);
                } while (room_choice < 1 || room_choice > *counter);
                guests[*counter].room_no = room_choice;
                printf("%s has checked in to room #%d.\n", guests[*counter].name, guests[*counter].room_no);
                *counter += 1;
                break;
            case 2:
                if (*counter < 1) {
                    printf("No guests to check out.\n");
                    break;
                }
                char check_out_name[20];
                printf("Enter guest name to check out: ");
                scanf("%s", check_out_name);
                for (int i = 0; i < *counter; i++) {
                    if (strcmp(guests[i].name, check_out_name) == 0) {
                        printf("Goodbye, %s.\n", guests[i].name);
                        guests[i] = guests[*counter-1];
                        *counter -= 1;
                        break;
                    }
                }
                break;
            case 3:
                if (*counter < 1) {
                    printf("No guests to display.\n");
                    break;
                }
                printf("\nGuests:\n");
                printf("Name\tAge\tGender\tAddress\t\tRoom No.\n");
                for (int i = 0; i < *counter; i++) {
                    printf("%s\t%d\t%s\t%-15s\t%d\n", guests[i].name, guests[i].age, guests[i].gender, guests[i].address, guests[i].room_no);
                }
                break;
            case 4:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
}

void room_menu(Room* rooms, int num_rooms) {
    int choice;

    do {
        printf("\n*****ROOM MENU*****\n");
        printf("1. View Rooms\n");
        printf("2. Book Room\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nRooms:\n");
                printf("Room No.\tType\tPrice\tAvailability\n");
                for (int i = 0; i < num_rooms; i++) {
                    printf("%d\t\t%s\t%d\t%s\n", rooms[i].room_no, rooms[i].type, rooms[i].price, rooms[i].availability ? "Available" : "Occupied");
                }
                break;
            case 2:
                int book_choice;
                do {
                    printf("Choose room number (1-%d): ", num_rooms);
                    scanf("%d", &book_choice);
                    if (book_choice < 1 || book_choice > num_rooms) {
                        printf("Invalid choice.\n");
                    } else if (!rooms[book_choice-1].availability) {
                        printf("Room #%d is not available.\n", book_choice);
                    }
                } while (book_choice < 1 || book_choice > num_rooms || !rooms[book_choice-1].availability);
                printf("You have booked room #%d for %s.\n", book_choice, rooms[book_choice-1].type);
                rooms[book_choice-1].availability = 0;
                break;
            case 3:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);
}