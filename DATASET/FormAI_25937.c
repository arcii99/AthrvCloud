//FormAI DATASET v1.0 Category: Hotel Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROOMS 50 //maximum number of rooms in the hotel

typedef struct {
    int roomNo;
    char guestName[50];
    int numGuests;
    float rate;
    int daysOccupied;
    float totalBill;
    int occupied;
} Room; //structure for the hotel rooms

void checkIn(Room *roomArr, int roomNum, int guestNum, char guestName[]){
    roomArr[roomNum-1].occupied = 1; 
    roomArr[roomNum-1].numGuests = guestNum; 
    strcpy(roomArr[roomNum-1].guestName, guestName); 
    printf("%s has checked into Room %d.\n", guestName, roomNum); 
}

void checkOut(Room *roomArr, int roomNum){
    if(roomArr[roomNum-1].occupied == 0){ 
        printf("Room %d is not occupied.\n", roomNum); 
    } else { 
        float bill = roomArr[roomNum-1].rate * roomArr[roomNum-1].daysOccupied * roomArr[roomNum-1].numGuests; 
        roomArr[roomNum-1].totalBill = bill; 
        printf("%s has checked out of Room %d. Their total bill is $%.2f.\n", roomArr[roomNum-1].guestName, roomNum, bill); 
        strcpy(roomArr[roomNum-1].guestName, ""); 
        roomArr[roomNum-1].numGuests = 0; 
        roomArr[roomNum-1].daysOccupied = 0; 
        roomArr[roomNum-1].occupied = 0; 
    }
}

void showRoom(Room *roomArr, int roomNum){
    printf("Room %d:\n", roomNum); 
    printf("    Guest Name: %s\n", roomArr[roomNum-1].guestName); 
    printf("    Number of guests: %d\n", roomArr[roomNum-1].numGuests); 
    printf("    Rate: $%.2f per night\n", roomArr[roomNum-1].rate); 
    printf("    Days Occupied: %d\n", roomArr[roomNum-1].daysOccupied);
    if(roomArr[roomNum-1].occupied == 1) { 
        printf("    Currently Occupied\n"); 
    } else { 
        printf("    Currently Unoccupied\n"); 
    }
}

int main(){
    Room roomArr[MAX_ROOMS]; //initialize the array of rooms
    for(int i = 0; i < MAX_ROOMS; i++){ 
        roomArr[i].roomNo = i+1; 
        roomArr[i].occupied = 0; 
        roomArr[i].rate = 99.99; 
        roomArr[i].totalBill = 0.0; 
        roomArr[i].numGuests = 0; 
        roomArr[i].daysOccupied = 0; 
    }

    int choice = 0;
    while(choice != 4){
        printf("Welcome to the Hotel Management System!\n");
        printf("1. Check in a guest\n");
        printf("2. Check out a guest\n");
        printf("3. Show room information\n");
        printf("4. Quit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                int roomNum, guestNum;
                char guestName[50];
                printf("Enter the room number: ");
                scanf("%d", &roomNum);
                printf("Enter the guest name: ");
                scanf("%s", guestName);
                printf("Enter the number of guests: ");
                scanf("%d", &guestNum);
                checkIn(roomArr, roomNum, guestNum, guestName);
                break;
            }
            case 2:{
                int roomNum;
                printf("Enter the room number: ");
                scanf("%d", &roomNum);
                checkOut(roomArr, roomNum);
                break;
            }
            case 3:{
                int roomNum;
                printf("Enter the room number: ");
                scanf("%d", &roomNum);
                showRoom(roomArr, roomNum);
                break;
            }
            case 4:{
                printf("Thank you for using the Hotel Management System! Goodbye.\n");
                break;
            }
            default:{
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
    return 0;
}