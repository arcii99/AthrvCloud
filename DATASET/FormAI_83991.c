//FormAI DATASET v1.0 Category: Hotel Management System ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//A structure to hold Hotel Room Details
struct Room{
    int roomNo;
    char roomType[20];
    int roomPrice;
    char roomStatus[20];
    char reservedBy[50];
};
//A function to display Room details
void displayRoomDetails(struct Room r)
{
    printf("\nRoom No: %d\nRoom Type: %s\nRoom Price: %d\nRoom Status: %s\nReserved By: %s\n",r.roomNo,r.roomType,r.roomPrice,r.roomStatus,r.reservedBy);
}
int main()
{
    int choice;
    char password[20], attempt[20];
    
    //Creating Room Objects
    struct Room rooms[10] = {
        {101,"Standard",200,"Available","None"},
        {102,"Standard",200,"Available","None"},
        {103,"Deluxe",400,"Available","None"},
        {104,"Deluxe",400,"Available","None"},
        {105,"Suite",600,"Available","None"},
        {106,"Suite",600,"Available","None"},
        {107,"Presidential",1000,"Available","None"},
        {108,"Presidential",1000,"Available","None"},
        {109,"Standard",200,"Available","None"},
        {110,"Deluxe",400,"Available","None"}
    };
    
    //Password
    strcpy(password, "admin123");
    printf("\nPlease Enter Login Password: ");
    scanf("%s",attempt);
    if(strcmp(password,attempt)!=0)
    {
        printf("\nIncorrect Password! Try Again.");
        exit(0); //Terminating Program
    }
    printf("\nLogin Successfull!\n\n");
    do{
        printf("\n1. View All Rooms Details\n2. Room Reservation\n3. Room Checkout\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{
                printf("\n--------------Hotel Room Details--------------\n");
                for(int i=0;i<10;i++)
                {
                    printf("-------------------------------------------\n");
                    displayRoomDetails(rooms[i]);
                    printf("-------------------------------------------\n");
                }
                break;
            }
            case 2:{
                int roomChoice;
                char name[20];
                printf("\n--------------Room Reservation--------------\n");
                printf("\nEnter the Room Number you want to reserve: ");
                scanf("%d",&roomChoice);
                if(strcmp(rooms[roomChoice-1].roomStatus,"Available")==0)
                {
                    printf("\nEnter Your Name: ");
                    scanf("%s",name);
                    strcpy(rooms[roomChoice-1].roomStatus,"Reserved");
                    strcpy(rooms[roomChoice-1].reservedBy,name);
                    printf("\nReservation Successfull!\n");
                }
                else
                {
                    printf("\nRoom is Not Available!\n");
                }
                break;
            }
            case 3:{
                int roomChoice;
                printf("\n--------------Room Checkout--------------\n");
                printf("\nEnter the Room Number you want to checkout: ");
                scanf("%d",&roomChoice);
                if(strcmp(rooms[roomChoice-1].roomStatus,"Reserved")==0)
                {
                    strcpy(rooms[roomChoice-1].roomStatus,"Available");
                    strcpy(rooms[roomChoice-1].reservedBy,"None");
                    printf("\nCheckout Successfull!\n");
                }
                else
                {
                    printf("\nInvalid Room Selection!\n");
                }
                break;
            }
            case 4:{
                printf("\nThank You for using Hotel Management System!\n");
                exit(0);
            }
            default:{
                printf("\nInvalid Choice! Try Again.");
            }
        }
    }while(choice!=4);
    return 0;
}