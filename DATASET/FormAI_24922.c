//FormAI DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct room
{
    int room_no;
    int room_type; // 1 for single, 2 for double and 3 for suite
    int room_status; // 0 for vacant, 1 for occupied
    char guest_name[50];
    int guest_age;
};
struct room rooms[30];

// initialize the rooms
void init_rooms()
{
    int i;
    for(i=0;i<30;i++)
    {
        rooms[i].room_no = i+1;
        if(i<10)
            rooms[i].room_type = 3; // first 10 rooms are suites
        else if(i>=10 && i<20)
            rooms[i].room_type = 2; // next 10 rooms are doubles
        else
            rooms[i].room_type = 1; // last 10 rooms are singles
        rooms[i].room_status = 0; // all rooms are vacant initially
        strcpy(rooms[i].guest_name, "");
        rooms[i].guest_age = 0;
    }
}

// display vacant rooms
void vacant_rooms()
{
    int i;
    printf("\n\nList of Vacant Rooms\n");
    printf("---------------------\n");
    for(i=0;i<30;i++)
    {
        if(rooms[i].room_status == 0)
        {
            printf("Room No: %d\t Room Type: %d\n", rooms[i].room_no, rooms[i].room_type);
        }
    }
}

// book a room for a guest
void book_room(int roomno)
{
    if(rooms[roomno-1].room_status == 0)
    {
        printf("\nEnter Guest Name: ");
        scanf("%s", rooms[roomno-1].guest_name);
        printf("\nEnter Guest Age: ");
        scanf("%d", &rooms[roomno-1].guest_age);
        rooms[roomno-1].room_status = 1;
        printf("\nBooking Confirmed!\n");
    }
    else
    {
        printf("\nSorry, the room is already occupied\n");
    }
}

// display the list of guests staying in the hotel
void guest_list()
{
    int i;
    printf("\n\nGuest List\n");
    printf("-----------\n");
    for(i=0;i<30;i++)
    {
        if(rooms[i].room_status == 1)
        {
            printf("Room No: %d\t Guest Name: %s\t Age: %d\n", rooms[i].room_no, rooms[i].guest_name, rooms[i].guest_age);
        }
    }
}

// main function
int main()
{
    int choice, roomno;
    init_rooms(); // initialize the rooms
    printf("\n\nWelcome to the Medieval Hotel Management System\n");
    printf("------------------------------------------------\n");
    do
    {
        printf("\n\nMenu\n");
        printf("----\n");
        printf("1. List of Vacant Rooms\n");
        printf("2. Book a Room\n");
        printf("3. Guest List\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                vacant_rooms();
                break;
            case 2:
                printf("\nEnter the Room Number: ");
                scanf("%d", &roomno);
                book_room(roomno);
                break;
            case 3:
                guest_list();
                break;
            case 4:
                printf("\nThank You for using the Medieval Hotel Management System\n");
                break;
            default:
                printf("\nInvalid Choice! Please try again\n");
        }
    }while(choice!=4);
    return 0;
}