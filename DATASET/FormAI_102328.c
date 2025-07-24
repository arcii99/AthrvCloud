//FormAI DATASET v1.0 Category: Hotel Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of rooms
#define MAX_ROOMS 100

// Define struct for room
typedef struct
{
    int roomNumber;
    char guestName[30];
    char guestPhoneNumber[12];
    float roomRate;
    int isOccupied;
} Room;

// Define global variable for array of rooms
Room hotelRooms[MAX_ROOMS];

// Define function for displaying main menu
void displayMainMenu()
{
    printf("\nMain Menu:\n");
    printf("1. Check in a guest.\n");
    printf("2. Check out a guest.\n");
    printf("3. View all occupied rooms.\n");
    printf("4. View all available rooms.\n");
    printf("5. Exit.\n");
}

// Define function for checking in a guest
void checkInGuest()
{
    // Declare local variables
    int roomNumber, i;
    char guestName[30];
    char guestPhoneNumber[12];
    float roomRate;

    // Loop through rooms to find available room
    for (i = 0; i < MAX_ROOMS; i++)
    {
        if (hotelRooms[i].isOccupied == 0)
        {
            // Get guest information
            printf("Enter guest name: ");
            scanf("%s", guestName);
            printf("Enter guest phone number: ");
            scanf("%s", guestPhoneNumber);
            printf("Enter room rate: ");
            scanf("%f", &roomRate);

            // Assign room information
            hotelRooms[i].roomNumber = i + 1;
            strcpy(hotelRooms[i].guestName, guestName);
            strcpy(hotelRooms[i].guestPhoneNumber, guestPhoneNumber);
            hotelRooms[i].roomRate = roomRate;
            hotelRooms[i].isOccupied = 1;

            // Display room information
            printf("\nGuest checked in successfully.\n");
            printf("Room number: %d\n", hotelRooms[i].roomNumber);
            printf("Guest name: %s\n", hotelRooms[i].guestName);
            printf("Guest phone number: %s\n", hotelRooms[i].guestPhoneNumber);
            printf("Room rate: %.2f\n", hotelRooms[i].roomRate);

            // Break loop
            break;
        }
    }

    // Check if all rooms are occupied
    if (i == MAX_ROOMS)
    {
        printf("All rooms are currently occupied.\n");
    }
}

// Define function for checking out a guest
void checkOutGuest()
{
    // Declare local variables
    int roomNumber, i;

    // Get room number
    printf("Enter room number: ");
    scanf("%d", &roomNumber);

    // Loop through rooms to find occupied room
    for (i = 0; i < MAX_ROOMS; i++)
    {
        if (hotelRooms[i].roomNumber == roomNumber && hotelRooms[i].isOccupied == 1)
        {
            // Reset room information
            hotelRooms[i].roomNumber = 0;
            strcpy(hotelRooms[i].guestName, "");
            strcpy(hotelRooms[i].guestPhoneNumber, "");
            hotelRooms[i].roomRate = 0.00;
            hotelRooms[i].isOccupied = 0;

            // Display success message
            printf("Guest checked out successfully.\n");

            // Break loop
            break;
        }
    }

    // Check if room number was not found or room was not occupied
    if (i == MAX_ROOMS)
    {
        printf("Room not found or is not occupied.\n");
    }
}

// Define function for viewing all occupied rooms
void viewOccupiedRooms()
{
    // Declare local variables
    int i, count = 0;

    // Loop through rooms to find occupied rooms
    for (i = 0; i < MAX_ROOMS; i++)
    {
        if (hotelRooms[i].isOccupied == 1)
        {
            // Display room information
            printf("\nRoom number: %d\n", hotelRooms[i].roomNumber);
            printf("Guest name: %s\n", hotelRooms[i].guestName);
            printf("Guest phone number: %s\n", hotelRooms[i].guestPhoneNumber);
            printf("Room rate: %.2f\n", hotelRooms[i].roomRate);

            // Increment count
            count++;
        }
    }

    // Check if no occupied rooms were found
    if (count == 0)
    {
        printf("No rooms are currently occupied.\n");
    }
}

// Define function for viewing all available rooms
void viewAvailableRooms()
{
    // Declare local variables
    int i, count = 0;

    // Loop through rooms to find available rooms
    for (i = 0; i < MAX_ROOMS; i++)
    {
        if (hotelRooms[i].isOccupied == 0)
        {
            // Display room information
            printf("\nRoom number: %d\n", hotelRooms[i].roomNumber);
            printf("Room status: Available\n");

            // Increment count
            count++;
        }
    }

    // Check if no available rooms were found
    if (count == 0)
    {
        printf("No rooms are currently available.\n");
    }
}

// Define main function
int main()
{
    // Declare local variable
    int choice;

    // Initialize array of rooms
    int i;
    for (i = 0; i < MAX_ROOMS; i++)
    {
        hotelRooms[i].roomNumber = i + 1;
        hotelRooms[i].isOccupied = 0;
    }

    // Loop through menu options until user chooses to exit
    do
    {
        // Display main menu
        displayMainMenu();

        // Get user choice
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice)
        {
            case 1:
                checkInGuest();
                break;
            case 2:
                checkOutGuest();
                break;
            case 3:
                viewOccupiedRooms();
                break;
            case 4:
                viewAvailableRooms();
                break;
            case 5:
                printf("Thank you for using the Hotel Management System.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}