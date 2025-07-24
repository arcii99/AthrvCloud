//FormAI DATASET v1.0 Category: Hotel Management System ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

int room_num[MAX];
char room_type[MAX][10];
float room_cost[MAX];
char guest_name[MAX][25];
int total_rooms_available = 0;

void init_rooms()
{
    int i;
    for (i = 0; i < MAX; i++) 
    {
        room_num[i] = i+1;
        strcpy(room_type[i], "Single");
        room_cost[i] = 1200;
        strcpy(guest_name[i], "");
    }
    total_rooms_available = MAX;
}

void print_room_info(int room_number)
{
    printf("Room Number: %d\n", room_num[room_number]);
    printf("Room Type: %s\n", room_type[room_number]);
    printf("Room Cost: $%.2f\n", room_cost[room_number]);
    printf("Guest Name: %s\n\n", guest_name[room_number]);
}

void print_all_rooms()
{
    int i;
    for (i = 0; i < MAX; i++) 
    {
        if (strlen(guest_name[i]) == 0)
        {
            printf("Room Number: %d\nStatus: Available\n\n", room_num[i]);
        }
        else
        {
            printf("Room Number: %d\nStatus: Occupied\n", room_num[i]);
            print_room_info(i);
        }
    }
}

void book_room(int room_number, char *guest_name)
{
    if (strlen(guest_name) == 0)
    {
        printf("Invalid guest name!\n");
        return;
    }

    if (room_number > MAX || room_number < 1)
    {
        printf("Invalid room number!\n");
        return;
    }

    if (strlen(guest_name[room_number-1]) > 0)
    {
        printf("Room already occupied!\n");
        return;
    }

    strcpy(guest_name[room_number-1], guest_name);
    total_rooms_available--;
    printf("Successfully booked the room %d for %s!\n", room_number, guest_name);
}

void checkout(int room_number)
{
    if (strlen(guest_name[room_number-1]) == 0)
    {
        printf("This room is not occupied by anyone!\n");
        return;
    }
    printf("Successfully checked out the room %d, occupied by %s\n", room_number, guest_name[room_number-1]);
    strcpy(guest_name[room_number-1], "");
    total_rooms_available++;
}

int main()
{
    int option, room_number;
    char guest_name[25];

    init_rooms();

    while (1)
    {
        printf("Welcome to C Hotel Management System!\n\n");
        printf("1. Print all rooms\n2. Book a room\n3. Check out\n4. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                print_all_rooms();
                break;
            case 2:
                printf("Enter the room number: ");
                scanf("%d", &room_number);
                printf("Enter your name: ");
                scanf("%s", guest_name);
                book_room(room_number, guest_name);
                break;
            case 3:
                printf("Enter the room number: ");
                scanf("%d", &room_number);
                checkout(room_number);
                break;
            case 4:
                printf("Thank you for using C Hotel Management System!\n");
                exit(0);
            default:
                printf("Invalid option selected! Please try again.\n");
                break;
        }
    }

    return 0;
}