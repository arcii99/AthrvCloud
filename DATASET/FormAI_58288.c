//FormAI DATASET v1.0 Category: Hotel Management System ; Style: expert-level
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the structure for storing the information of one room
struct room{
    int roomNo;
    char guestName[30];
    int days;
    int roomType;
    int status;
};

// Declare the function to print the menu and return the selected option
int menu();

// Declare the function to book a room and check availability
void bookRoom(struct room hotelRoom[MAX_ROOMS], int numRooms);

// Declare the function to check out a room and calculate the bill
void checkOut(struct room hotelRoom[MAX_ROOMS], int numRooms);

// Declare the function to display the status of all rooms
void displayAllRooms(struct room hotelRoom[MAX_ROOMS], int numRooms);

// Declare the function to search for a room by room number
int searchRoom(struct room hotelRoom[MAX_ROOMS], int numRooms, int roomNo);

int main(){
    // Declare the array of hotel rooms and initialize to all empty rooms
    struct room hotelRoom[MAX_ROOMS];
    for(int i=0; i<MAX_ROOMS; i++){
        hotelRoom[i].roomNo = i+1;
        hotelRoom[i].status = 0;
    }
    printf("Welcome to the Hotel Management System!\n");
    int option = menu();
    while(option != 4){
        switch(option){
            case 1:
                bookRoom(hotelRoom, MAX_ROOMS);
                break;
            case 2:
                checkOut(hotelRoom, MAX_ROOMS);
                break;
            case 3:
                displayAllRooms(hotelRoom, MAX_ROOMS);
                break;
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
        option = menu();
    }
    printf("Thank you for using the Hotel Management System!\n");
    return 0;
}

int menu(){
    int option;
    printf("\n\tMain Menu\n");
    printf("1. Book a room\n");
    printf("2. Check out a room\n");
    printf("3. Display all rooms\n");
    printf("4. Exit\n");
    printf("Select an option: ");
    scanf("%d", &option);
    return option;
}

void bookRoom(struct room hotelRoom[MAX_ROOMS], int numRooms){
    int roomNo, index;
    printf("Enter the room number: ");
    scanf("%d", &roomNo);
    index = searchRoom(hotelRoom, numRooms, roomNo);
    if(index == -1){
        printf("Invalid room number. Please try again.\n");
        return;
    }
    if(hotelRoom[index].status == 1){
        printf("Sorry, the room is already booked. Please try again later.\n");
        return;
    }
    printf("Enter the guest name: ");
    scanf("%s", hotelRoom[index].guestName);
    printf("Enter the number of days: ");
    scanf("%d", &hotelRoom[index].days);
    printf("Enter the room type (1-Single, 2-Double, 3-Suite): ");
    scanf("%d", &hotelRoom[index].roomType);
    hotelRoom[index].status = 1;
    printf("Room %d has been successfully booked.\n", roomNo);
}

void checkOut(struct room hotelRoom[MAX_ROOMS], int numRooms){
    int roomNo, index;
    printf("Enter the room number: ");
    scanf("%d", &roomNo);
    index = searchRoom(hotelRoom, numRooms, roomNo);
    if(index == -1){
        printf("Invalid room number. Please try again.\n");
        return;
    }
    if(hotelRoom[index].status == 0){
        printf("Sorry, the room is not currently booked. Please try again later.\n");
        return;
    }
    printf("Guest name: %s\n", hotelRoom[index].guestName);
    printf("Number of days: %d\n", hotelRoom[index].days);
    printf("Room type: %d\n", hotelRoom[index].roomType);
    int rate = 0;
    switch(hotelRoom[index].roomType){
        case 1:
            rate = 1000;
            break;
        case 2:
            rate = 1500;
            break;
        case 3:
            rate = 2000;
            break;
        default:
            printf("Invalid room type.\n");
            return;
    }
    printf("Room rate: Rs. %d per day\n", rate);
    int total = rate * hotelRoom[index].days;
    printf("Total bill amount: Rs. %d\n", total);
    hotelRoom[index].status = 0;
    strcpy(hotelRoom[index].guestName, "");
    hotelRoom[index].days = 0;
    hotelRoom[index].roomType = 0;
    printf("Thank you for staying with us.\n");
}

void displayAllRooms(struct room hotelRoom[MAX_ROOMS], int numRooms){
    printf("\n\tRoom status:\n");
    printf("Room No.\tStatus\t\tGuest Name\t\tDays\t\tRoom Type\n");
    for(int i=0; i<numRooms; i++){
        printf("%d\t\t", hotelRoom[i].roomNo);
        if(hotelRoom[i].status == 0){
            printf("Empty\t\t\t");
        }
        else{
            printf("Booked\t\t%s\t\t%d\t\t", hotelRoom[i].guestName, hotelRoom[i].days);
            switch(hotelRoom[i].roomType){
                case 1:
                    printf("Single\n");
                    break;
                case 2:
                    printf("Double\n");
                    break;
                case 3:
                    printf("Suite\n");
                    break;
                default:
                    printf("Invalid\n");
                    break;
            }
        }
    }
}

int searchRoom(struct room hotelRoom[MAX_ROOMS], int numRooms, int roomNo){
    for(int i=0; i<numRooms; i++){
        if(hotelRoom[i].roomNo == roomNo){
            return i;
        }
    }
    return -1;
}