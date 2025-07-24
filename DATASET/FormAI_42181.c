//FormAI DATASET v1.0 Category: Hotel Management System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

struct room {
    int roomNumber;
    char roomType[20];
    int roomStatus;
};

void checkIn(struct room list[]) {
    int roomNum, flag=0;
    printf("Enter room number to check in: ");
    scanf("%d", &roomNum);
    for(int i=0; i<10; i++) {
        if(list[i].roomNumber==roomNum) {
            flag=1;
            if(list[i].roomStatus==1) {
                printf("Room already occupied.\n");
            }
            else {
                list[i].roomStatus=1;
                printf("Room %d checked in successfully.\n", roomNum);
            }
            break;
        }
    }
    if(flag==0) {
        printf("Room not found.\n");
    }
}

void checkOut(struct room list[]) {
    int roomNum, flag=0;
    printf("Enter room number to check out: ");
    scanf("%d", &roomNum);
    for(int i=0; i<10; i++) {
        if(list[i].roomNumber==roomNum) {
            flag=1;
            if(list[i].roomStatus==0) {
                printf("Room not occupied.\n");
            }
            else {
                list[i].roomStatus=0;
                printf("Room %d checked out successfully.\n", roomNum);
            }
            break;
        }
    }
    if(flag==0) {
        printf("Room not found.\n");
    }
}

void displayRooms(struct room list[]) {
    printf("Room No.\tRoom Type\tRoom Status\n");
    for(int i=0; i<10; i++) {
        printf("%d\t\t%s\t\t", list[i].roomNumber, list[i].roomType);
        if(list[i].roomStatus==0) {
            printf("Available\n");
        }
        else {
            printf("Occupied\n");
        }
    }
}

int main() {
    struct room rooms[10];
    for(int i=0; i<10; i++) {
        rooms[i].roomNumber=i+1;
        if(i%3==0) {
            strcpy(rooms[i].roomType, "Single");
        }
        else if(i%3==1) {
            strcpy(rooms[i].roomType, "Double");
        }
        else {
            strcpy(rooms[i].roomType, "Family");
        }
        rooms[i].roomStatus=0;
    }
    int choice;
    while(1) {
        printf("\n1. Check In\n2. Check Out\n3. Display Rooms\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                checkIn(rooms);
                break;
            case 2:
                checkOut(rooms);
                break;
            case 3:
                displayRooms(rooms);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}