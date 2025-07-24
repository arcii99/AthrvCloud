//FormAI DATASET v1.0 Category: Hotel Management System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Hotel
{
    int room_no;
    char name[30];
    float room_rent;
    int is_booked;
};

struct Hotel hotel[50];

void insert_rooms();
void display_rooms();
void book_room();
void exit_hotel();

int main()
{
    int choice = 0;
    printf("******************************\n");
    printf("Welcome to C Hotel Management\n");
    printf("******************************\n");
    for(int i=0;i<50;i++)
    {
       hotel[i].room_no = i;
    }
    do
    {
        printf("\n\n");
        printf("1. Insert Rooms\n");
        printf("2. Display Rooms\n");
        printf("3. Book Room\n");
        printf("4. Exit C Hotel Management\n\n");
        printf("Enter your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert_rooms();
                break;
            case 2:
                display_rooms();
                break;
            case 3:
                book_room();
                break;
            case 4:
                exit_hotel();
                break;
            default:
                printf("Invalid Input Please Enter Correct option:");
        }
    }while(choice != 4);

    return 0;
}

void insert_rooms()
{
    int n;
    printf("Enter number of rooms to insert(1-50): ");
    scanf("%d",&n);
    if(n>0 && n<50)
    {
        for(int i=0;i<n;i++)
        {

            printf("\nEnter the room rent for room %d: ", i+1);
            scanf("%f",&hotel[i].room_rent);
            hotel[i].is_booked = 0;
        }
        printf("\n\n%d rooms Inserted Successfully.\n\n",n);
    }
    else
    {
        printf("Invalid Input");
    }
}

void display_rooms()
{
    printf("*******************\n");
    printf("C Hotel Room List\n");
    printf("*******************\n");

    printf("\nRoom No.\tRoom Rent\tStatus\n");
    printf("-------------------------------------");
        for(int i=0;i<50;i++)
        {
            if(hotel[i].room_rent>0)
            {
                if(hotel[i].is_booked == 0)
                {
                    printf("\n%d\t\t%.2f\t\t%s",hotel[i].room_no+1,hotel[i].room_rent,"Available");
                }
                else
                {
                    printf("\n%d\t\t%.2f\t\t%s",hotel[i].room_no+1,hotel[i].room_rent,"Booked");
                }
            }
        }
}

void book_room()
{
    char name[30];
    int room_no,index=-1;
    display_rooms();
    printf("\nEnter the room number which you want to book: ");
    scanf("%d",&room_no);
    if(room_no>0 && room_no<51)
    {
        index = room_no - 1;
        if(hotel[index].is_booked == 0)
        {
            printf("\nEnter your name: ");
            scanf("%s",&name);
            strcpy(hotel[index].name,name);
            hotel[index].is_booked = 1;
            printf("\n\nRoom No. %d Booked Successfully.", room_no);
        }
        else
        {
            printf("Room is already booked.\n");
        }
    }
    else
    {
        printf("Invalid Room No. please Enter correct Room No.");
    }

}

void exit_hotel()
{
    printf("\n\n******************THANK YOU******************\n\n");
}