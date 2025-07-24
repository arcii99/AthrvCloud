//FormAI DATASET v1.0 Category: Hotel Management System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char name[20];
    char address[50];
    char phone[12];
    int roomNumber;
    int numDays;
    float totalCost;
}Guest;

typedef struct
{
    int roomNumber;
    int occupied;
}Room;

void displayMenu()
{
    printf("==== HOTEL MANAGEMENT SYSTEM ====\n");
    printf("1. Add new guest\n");
    printf("2. Show guest details\n");
    printf("3. Check out guest\n");
    printf("4. Display all guests\n");
    printf("5. Exit\n");
}

void addNewGuest(Guest hotelGuests[], Room hotelRooms[])
{
    int i, roomNumber, numDays;
    float totalCost;
    char name[20], address[50], phone[12];

    printf("Enter guest name: ");
    scanf("%s", name);

    printf("Enter guest address: ");
    scanf("%s", address);

    printf("Enter guest phone number: ");
    scanf("%s", phone);

    printf("Select room number (101-108): ");
    scanf("%d", &roomNumber);

    printf("Enter number of days staying: ");
    scanf("%d", &numDays);

    totalCost = numDays * 120.0;

    for(i = 0; i < 8; i++)
    {
        if(hotelRooms[i].roomNumber == roomNumber)
        {
            hotelRooms[i].occupied = 1;
            break;
        }
    }

    strcpy(hotelGuests[i].name, name);
    strcpy(hotelGuests[i].address, address);
    strcpy(hotelGuests[i].phone, phone);
    hotelGuests[i].roomNumber = roomNumber;
    hotelGuests[i].numDays = numDays;
    hotelGuests[i].totalCost = totalCost;

    printf("\nNew guest added successfully!\n\n");
}

void showGuestDetails(Guest hotelGuests[], int numGuests)
{
    int i, roomNumber;

    printf("Enter room number to show details: ");
    scanf("%d", &roomNumber);

    for(i = 0; i < numGuests; i++)
    {
        if(hotelGuests[i].roomNumber == roomNumber)
        {
            printf("\n========== GUEST DETAILS ==========\n");
            printf("Name: %s\n", hotelGuests[i].name);
            printf("Address: %s\n", hotelGuests[i].address);
            printf("Phone number: %s\n", hotelGuests[i].phone);
            printf("Room number: %d\n", hotelGuests[i].roomNumber);
            printf("Number of days staying: %d\n", hotelGuests[i].numDays);
            printf("Total cost: $%.2f\n\n", hotelGuests[i].totalCost);
            return;
        }
    }

    printf("\nRoom number not found!\n\n");
}

void checkOutGuest(Guest hotelGuests[], Room hotelRooms[], int numGuests)
{
    int i, roomNumber;

    printf("Enter room number to check out: ");
    scanf("%d", &roomNumber);

    for(i = 0; i < numGuests; i++)
    {
        if(hotelGuests[i].roomNumber == roomNumber)
        {
            hotelRooms[i].occupied = 0;
            printf("\nGuest checked out successfully!\n\n");
            return;
        }
    }

    printf("\nRoom number not found!\n\n");
}

void displayAllGuests(Guest hotelGuests[], int numGuests)
{
    int i;

    printf("\n========== ALL GUESTS ==========\n");
    for(i = 0; i < numGuests; i++)
    {
        printf("Name: %s\n", hotelGuests[i].name);
        printf("Address: %s\n", hotelGuests[i].address);
        printf("Phone number: %s\n", hotelGuests[i].phone);
        printf("Room number: %d\n", hotelGuests[i].roomNumber);
        printf("Number of days staying: %d\n", hotelGuests[i].numDays);
        printf("Total cost: $%.2f\n\n", hotelGuests[i].totalCost);
    }
}

int main()
{
    Guest hotelGuests[8];
    Room hotelRooms[8];
    int choice, numGuests = 0;

    int i;
    for(i = 0; i < 8; i++)
    {
        hotelRooms[i].roomNumber = i+101;
        hotelRooms[i].occupied = 0;
    }

    printf("Welcome to the hotel management system!\n\n");

    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addNewGuest(hotelGuests, hotelRooms);
                    numGuests++;
                    break;
            case 2: showGuestDetails(hotelGuests, numGuests);
                    break;
            case 3: checkOutGuest(hotelGuests, hotelRooms, numGuests);
                    break;
            case 4: displayAllGuests(hotelGuests, numGuests);
                    break;
            case 5: exit(0);
            default: printf("Invalid choice!\n\n");
        }

    }while(choice != 5);

    return 0;
}