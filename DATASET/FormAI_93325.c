//FormAI DATASET v1.0 Category: Hotel Management System ; Style: protected
#include<stdio.h>
#include<string.h>

//Defining Constants for Room Types and Prices
#define SINGLE_ROOM 100
#define DOUBLE_ROOM 200
#define DELUXE_ROOM 300

//Declaring the Structure for Rooms
struct Room {
    int room_no;
    char type[10];
    int price;
    char status[10];
    char guest_name[30];
};

//Function to Print Menu and Take User Input
int menu() {
    int choice;
    printf("\n\n-------Welcome to C Hotel Management System-------\n\n");
    printf("1. Check Available Rooms\n");
    printf("2. Book a Room\n");
    printf("3. View Booked Rooms\n");
    printf("4. Check Out a Room\n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

//Function to Initialize Rooms
void initialize(struct Room rooms[], int size) {
    int i;
    for(i=0; i<size; i++) {
        rooms[i].room_no = i+1;
        if(i<size/3) {
            strcpy(rooms[i].type, "Single");
            rooms[i].price = SINGLE_ROOM;
        }
        else if(i<size*2/3) {
            strcpy(rooms[i].type, "Double");
            rooms[i].price = DOUBLE_ROOM;
        }
        else {
            strcpy(rooms[i].type, "Deluxe");
            rooms[i].price = DELUXE_ROOM;
        }
        strcpy(rooms[i].status, "Available");
        strcpy(rooms[i].guest_name, "");
    }
}

//Function to Check Available Rooms
void check_available_rooms(struct Room rooms[], int size) {
    int i, count=0;
    printf("\n\n-------Available Rooms-------\n\n");
    for(i=0; i<size; i++) {
        if(!strcmp(rooms[i].status, "Available")) {
            printf("Room Number: %d\n", rooms[i].room_no);
            printf("Room Type: %s\n", rooms[i].type);
            printf("Room Price: %d\n\n", rooms[i].price);
            count++;
        }
    }
    if(count==0)
        printf("Sorry, No Rooms Available currently.\n\n");
}

//Function to Book a Room
void book_room(struct Room rooms[], int size) {
    int room_number, i;
    printf("\nEnter Room Number to Book: ");
    scanf("%d", &room_number);
    for(i=0; i<size; i++) {
        if(rooms[i].room_no==room_number) {
            if(!strcmp(rooms[i].status, "Available")) {
                printf("\nEnter Guest Name: ");
                scanf("%s", rooms[i].guest_name);
                strcpy(rooms[i].status, "Booked");
                printf("\nRoom Booked Successfully.\n\n");
            }
            else {
                printf("\nSorry, Room is Not Available.\n\n");
            }
            return;
        }
    }
    printf("\nInvalid Room Number.\n\n");
}

//Function to View Booked Rooms
void view_booked_rooms(struct Room rooms[], int size) {
    int i, count=0;
    printf("\n\n-------Booked Rooms-------\n\n");
    for(i=0; i<size; i++) {
        if(!strcmp(rooms[i].status, "Booked")) {
            printf("Room Number: %d\n", rooms[i].room_no);
            printf("Room Type: %s\n", rooms[i].type);
            printf("Room Price: %d\n", rooms[i].price);
            printf("Guest Name: %s\n\n", rooms[i].guest_name);
            count++;
        }
    }
    if(count==0)
        printf("Sorry, No Rooms Booked currently.\n\n");
}

//Function to Check Out a Room
void checkout_room(struct Room rooms[], int size) {
    int room_number, i;
    printf("\nEnter Room Number to Check Out: ");
    scanf("%d", &room_number);
    for(i=0; i<size; i++) {
        if(rooms[i].room_no==room_number) {
            if(!strcmp(rooms[i].status, "Booked")) {
                printf("\nGuest Name: %s\n", rooms[i].guest_name);
                printf("Room Type: %s\n", rooms[i].type);
                printf("Room Price: %d\n", rooms[i].price);
                printf("Total Bill: %d\n\n", rooms[i].price*1);
                strcpy(rooms[i].status, "Available");
                strcpy(rooms[i].guest_name, "");
                printf("\nRoom Checked Out Successfully.\n\n");
            }
            else {
                printf("\nSorry, Room is Not Booked.\n\n");
            }
            return;
        }
    }
    printf("\nInvalid Room Number.\n\n");
}

//Main Function
int main() {
    int choice, n=9; //Assuming 9 Rooms in C Hotel
    struct Room rooms[n];
    initialize(rooms, n); //Initializing Rooms
    while(1) {
        choice = menu();
        switch(choice) {
            case 1:
                check_available_rooms(rooms, n);
                break;
            case 2:
                book_room(rooms, n);
                break;
            case 3:
                view_booked_rooms(rooms, n);
                break;
            case 4:
                checkout_room(rooms, n);
                break;
            case 5:
                printf("\n\n-------Thank You for Using C Hotel Management System-------\n\n");
                return 0;
            default:
                printf("\nInvalid Choice.\n");
        }
    }
    return 0;
}