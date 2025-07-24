//FormAI DATASET v1.0 Category: Hotel Management System ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ROOMS 100
#define MAX_NAME 50

typedef struct{
    int room_num;
    char name[MAX_NAME];
    int occupancy;
    char check_in_date[MAX_NAME];
    char check_out_date[MAX_NAME];
} Room;

void check_in(Room rooms[]){
    int room_num;
    printf("Enter Room Number: ");
    scanf("%d", &room_num);

    if (room_num < 1 || room_num > MAX_ROOMS){
        printf("Invalid Room Number\n");
        return;
    }

    if (rooms[room_num - 1].occupancy == 1){
        printf("Room %d is already occupied\n", room_num);
        return;
    }

    printf("Enter Guest Name: ");
    scanf("%s", rooms[room_num - 1].name);
    printf("Enter Check-In Date: ");
    scanf("%s", rooms[room_num - 1].check_in_date);

    rooms[room_num - 1].occupancy = 1;

    printf("Successfully checked in to Room %d\n", room_num);
}

void check_out(Room rooms[]){
    int room_num;
    printf("Enter Room Number: ");
    scanf("%d", &room_num);

    if (room_num < 1 || room_num > MAX_ROOMS){
        printf("Invalid Room Number\n");
        return;
    }

    if (rooms[room_num - 1].occupancy == 0){
        printf("Room %d is already vacant\n", room_num);
        return;
    }

    printf("Enter Check-Out Date: ");
    scanf("%s", rooms[room_num - 1].check_out_date);

    printf("Successfully checked out of Room %d\n", room_num);

    rooms[room_num - 1].room_num = 0;
    rooms[room_num - 1].name[0] = '\0';
    rooms[room_num - 1].occupancy = 0;
    rooms[room_num - 1].check_in_date[0] = '\0';
    rooms[room_num - 1].check_out_date[0] = '\0';
}

void display(Room rooms[]){
    printf("%-10s%-20s%-15s%-15s%-20s\n", "Room Num", "Guest Name", "Occupancy", "Check-In", "Check-Out");
    for(int i = 0; i < MAX_ROOMS; i++){
        printf("%-10d", i + 1);
        if(rooms[i].occupancy){
            printf("%-20s", rooms[i].name);
            printf("%-15s", "Occupied");
            printf("%-15s", rooms[i].check_in_date);
            printf("%-20s", rooms[i].check_out_date);
        }else{
            printf("%-20s%-15s%-15s%-20s", "Vacant", "", "", "");
        }
        printf("\n");
    }
}

int main(){
    Room rooms[MAX_ROOMS];
    for(int i = 0; i < MAX_ROOMS; i++){
        rooms[i].room_num = i + 1;
        rooms[i].occupancy = 0;
        rooms[i].name[0] = '\0';
        rooms[i].check_in_date[0] = '\0';
        rooms[i].check_out_date[0] = '\0';
    }

    int option;
    do{
        printf("\n1. Check In\n");
        printf("2. Check Out\n");
        printf("3. Display Rooms\n");
        printf("4. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                check_in(rooms);
                break;
            case 2:
                check_out(rooms);
                break;
            case 3:
                display(rooms);
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid Option\n");
        }
    }while(option != 4);
    return 0;
}