//FormAI DATASET v1.0 Category: Hotel Management System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_GUESTS 100

//guest structure
typedef struct Guest {
    char name[50];
    int room_no;
    int days_staying;
    float total_bill;
    char phone_no[20];
} Guest;

//hotel structure
typedef struct Hotel {
    int num_of_rooms;
    int num_of_guests;
    int available_rooms[MAX_GUESTS];
    Guest guests[MAX_GUESTS];
} Hotel;

//function prototypes
void add_guest(Hotel *hotel);
void print_guest(Guest guest);
void print_guests(Hotel hotel);
void search_guest(Hotel hotel, char *name);
void checkout_guest(Hotel *hotel, int room_no);

int main() {
    //initialize hotel
    Hotel hotel;
    strcpy(hotel.available_rooms, "1111111111");
    hotel.num_of_guests = 0;
    hotel.num_of_rooms = 10;

    int choice = 0;

    //menu loop
    while(choice != 5) {
        printf("Welcome to the Hotel Management System!\n\n");
        printf("1. Add a new Guest\n");
        printf("2. Print all guests\n");
        printf("3. Search for a guest\n");
        printf("4. Checkout a guest\n");
        printf("5. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_guest(&hotel);
                break;
            case 2:
                print_guests(hotel);
                break;
            case 3:
                printf("Enter the name of the guest you want to search for: ");
                char name[50];
                scanf("%s", name);
                search_guest(hotel, name);
                break;
            case 4:
                printf("Enter the room number of the guest you want to checkout: ");
                int room_no;
                scanf("%d", &room_no);
                checkout_guest(&hotel, room_no);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        printf("\n\n\n");
    }

    return 0;
}

//function to add a new guest to the hotel
void add_guest(Hotel *hotel) {
    //check if any rooms are available
    if(strlen(hotel->available_rooms) == 0) {
        printf("No rooms available!\n");
        return;
    }

    //get guest details from user
    Guest guest;
    printf("Enter the name of the guest: ");
    scanf("%s", guest.name);

    printf("Enter the phone number of the guest: ");
    scanf("%s", guest.phone_no);

    printf("Enter the number of days the guest is staying: ");
    scanf("%d", &guest.days_staying);

    printf("Available rooms: %s\n", hotel->available_rooms);
    printf("Enter the room number for the guest: ");
    scanf("%d", &guest.room_no);

    //add guest to guests array
    hotel->guests[hotel->num_of_guests] = guest;
    hotel->num_of_guests++;

    //mark room as taken
    int index = guest.room_no - 1;
    hotel->available_rooms[index] = '0';

    printf("Guest added successfully!\n");
}

//function to print a single guest
void print_guest(Guest guest) {
    printf("Name: %s\n", guest.name);
    printf("Phone Number: %s\n", guest.phone_no);
    printf("Room Number: %d\n", guest.room_no);
    printf("Days Staying: %d\n", guest.days_staying);
    printf("Total Bill: %.2f\n", guest.total_bill);
    printf("--------------------\n");
}

//function to print all guests
void print_guests(Hotel hotel) {
    printf("All guests: \n");
    for(int i = 0; i < hotel.num_of_guests; i++) {
        print_guest(hotel.guests[i]);
    }
}

//function to search for a guest by name
void search_guest(Hotel hotel, char *name) {
    for(int i = 0; i < hotel.num_of_guests; i++) {
        if(strcmp(hotel.guests[i].name, name) == 0) {
            print_guest(hotel.guests[i]);
            return;
        }
    }

    printf("Guest not found!\n");
}

//function to checkout a guest and calculate their total bill
void checkout_guest(Hotel *hotel, int room_no) {
    //find guest in guests array
    int index = -1;
    for(int i = 0; i < hotel->num_of_guests; i++) {
        if(hotel->guests[i].room_no == room_no) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Guest not found!\n");
        return;
    }

    //calculate total bill
    float rate = 1000; //rate per day
    int days_staying = hotel->guests[index].days_staying;
    float total_bill = rate * days_staying;

    //update guest and hotel
    hotel->guests[index].total_bill = total_bill;
    hotel->available_rooms[room_no - 1] = '1';

    printf("Guest checked out successfully!\n");
    printf("Total bill: %.2f\n", total_bill);
}