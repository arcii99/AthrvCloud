//FormAI DATASET v1.0 Category: Hotel Management System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int roomNum;
    char roomType[10];
    int rates;
    int occupancy;
    char status[10];
} room;

room rooms[10];

void initializeRooms() {
    int i;
    for(i=0;i<5;i++) {
        rooms[i].roomNum = i+101;
        strcpy(rooms[i].roomType, "Single");
        rooms[i].rates = 1500;
        rooms[i].occupancy = 1;
        strcpy(rooms[i].status, "Available");
    }
    for(i=5;i<10;i++) {
        rooms[i].roomNum = i+101;
        strcpy(rooms[i].roomType, "Double");
        rooms[i].rates = 2200;
        rooms[i].occupancy = 2;
        strcpy(rooms[i].status, "Available");
    }
}

void displayAvailableRooms() {
    int i;
    printf("\nRoom Number\tRoom Type\tRates\tOccupancy\tStatus\n");
    for(i=0;i<10;i++) {
        if(strcmp(rooms[i].status, "Available") == 0)
            printf("%d\t\t%s\t%d\t%d\t\t%s\n", rooms[i].roomNum, rooms[i].roomType, rooms[i].rates, rooms[i].occupancy, rooms[i].status);
    }
}

void bookRoom() {
    int roomNum, i;
    printf("\nEnter Room Number:");
    scanf("%d", &roomNum);
    for(i=0;i<10;i++) {
        if(rooms[i].roomNum == roomNum) {
            if(strcmp(rooms[i].status, "Available") == 0) {
                strcpy(rooms[i].status, "Booked");
                printf("\nRoom Booked Successfully!\n");
                return;
            }
            else {
                printf("\nRoom already occupied\n");
                return;
            }
        }
    }
    printf("\nRoom not found\n");
}

void cancelRoom() {
    int roomNum, i;
    printf("\nEnter Room Number:");
    scanf("%d", &roomNum);
    for(i=0;i<10;i++) {
        if(rooms[i].roomNum == roomNum) {
            if(strcmp(rooms[i].status, "Booked") == 0) {
                strcpy(rooms[i].status, "Available");
                printf("\nBooking Cancelled Successfully!\n");
                return;
            }
            else {
                printf("\nUnable to cancel booking\n");
                return;
            }
        }
    }
    printf("\nRoom not found\n");
}

int main() {
    int choice, i;
    initializeRooms();
    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Display available rooms\n");
        printf("2. Book a room\n");
        printf("3. Cancel a booking\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nAvailable Rooms:\n");
                displayAvailableRooms();
                break;
            case 2:
                bookRoom();
                break;
            case 3:
                cancelRoom();
                break;
            case 4:
                printf("\nExiting....\n");
                exit(0);
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}