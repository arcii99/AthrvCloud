//FormAI DATASET v1.0 Category: Hotel Management System ; Style: immersive
#include<stdio.h>
#include<string.h>

void display_menu()
{
    printf("\n----------Welcome to C Hotel Management System----------\n\n");
    printf("\t\t\tMenu\n");
    printf("\n1. Book a room");
    printf("\n2. Check-in");
    printf("\n3. Check-out");
    printf("\n4. Total earnings");
    printf("\n5. Exit\n");
}

struct guests
{
    char name[20];
    char gender[10];
    int age;
};

struct room
{
    int number;
    char status[10];
    struct guests guest;
};

struct hotel
{
    struct room rooms[20];
    int earnings;
}h;

void initialize()
{
    int i;
    for(i=0;i<20;i++)
    {
        h.rooms[i].number = i+101;
        strcpy(h.rooms[i].status,"Available");
        h.rooms[i].guest.name[0]='\0';
        h.rooms[i].guest.gender[0]='\0';
        h.rooms[i].guest.age=0;
    }
    h.earnings=0;
}

void book_room()
{
    int i,room_no;
    printf("\nEnter the room number you want to book: ");
    scanf("%d",&room_no);
    for(i=0;i<20;i++)
    {
        if(h.rooms[i].number==room_no)
        {
            if(strcmp(h.rooms[i].status,"Available")==0)
            {
                printf("\nEnter guest details:\n");
                printf("\n\tName: ");
                scanf("%s",h.rooms[i].guest.name);
                printf("\n\tGender: ");
                scanf("%s",h.rooms[i].guest.gender);
                printf("\n\tAge: ");
                scanf("%d",&h.rooms[i].guest.age);
                strcpy(h.rooms[i].status,"Booked");
                printf("\nThe room has been booked.\n");
            }
            else
            {
                printf("\nThe room is already booked.\n");
            }
            break;
        }
    }
    if(i==20)
    {
        printf("\nInvalid room number.\n");
    }
}

void check_in()
{
    int i,room_no;
    printf("\nEnter the room number you want to check-in: ");
    scanf("%d",&room_no);
    for(i=0;i<20;i++)
    {
        if(h.rooms[i].number==room_no)
        {
            if(strcmp(h.rooms[i].status,"Booked")==0)
            {
                printf("\nEnter guest details:\n");
                printf("\n\tName: ");
                scanf("%s",h.rooms[i].guest.name);
                printf("\n\tGender: ");
                scanf("%s",h.rooms[i].guest.gender);
                printf("\n\tAge: ");
                scanf("%d",&h.rooms[i].guest.age);
                strcpy(h.rooms[i].status,"Occupied");
                printf("\nThe room has been successfully checked-in.\n");
            }
            else if(strcmp(h.rooms[i].status,"Available")==0)
            {
                printf("\nThe room is not booked yet.\n");
            }
            else
            {
                printf("\nThe room is already occupied.\n");
            }
            break;
        }
    }
    if(i==20)
    {
        printf("\nInvalid room number.\n");
    }
}

void check_out()
{
    int i,room_no;
    printf("\nEnter the room number you want to check-out: ");
    scanf("%d",&room_no);
    for(i=0;i<20;i++)
    {
        if(h.rooms[i].number==room_no)
        {
            if(strcmp(h.rooms[i].status,"Occupied")==0)
            {
                printf("\nGuest details:\n");
                printf("\n\tName: %s",h.rooms[i].guest.name);
                printf("\n\tGender: %s",h.rooms[i].guest.gender);
                printf("\n\tAge: %d",h.rooms[i].guest.age);
                printf("\n\tRoom charge: $100\n");
                h.earnings+=100;
                h.rooms[i].guest.name[0]='\0';
                h.rooms[i].guest.gender[0]='\0';
                h.rooms[i].guest.age=0;
                strcpy(h.rooms[i].status,"Available");
                printf("\nThe room has been checked-out.\n");
            }
            else if(strcmp(h.rooms[i].status,"Available")==0)
            {
                printf("\nThe room is not booked yet.\n");
            }
            else
            {
                printf("\nThe room is already available.\n");
            }
            break;
        }
    }
    if(i==20)
    {
        printf("\nInvalid room number.\n");
    }
}

void total_earnings()
{
    printf("\nTotal earnings: $%d\n",h.earnings);
}

int main()
{
    initialize();
    int choice;
    do
    {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: book_room();
            break;

            case 2: check_in();
            break;

            case 3: check_out();
            break;

            case 4: total_earnings();
            break;

            case 5: printf("\nThank you for using C Hotel Management System!\n");
            break;

            default: printf("\nInvalid choice!\n");
        }
    }while(choice!=5);
    return 0;
}