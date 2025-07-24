//FormAI DATASET v1.0 Category: Hotel Management System ; Style: enthusiastic
#include <stdio.h>

// Structure for a hotel room
typedef struct
{
    int roomNumber;
    int numberOfBeds;
    int isOccupied;
} room;

int main()
{
    int numberOfRooms;
    printf("Enter the number of rooms in the hotel: ");
    scanf("%d", &numberOfRooms);

    // Create an array of rooms
    room hotelRooms[numberOfRooms];

    // Initialize the hotelRooms array
    for (int i = 0; i < numberOfRooms; i++)
    {
        hotelRooms[i].roomNumber = i + 1;
        hotelRooms[i].numberOfBeds = i % 4 + 1;
        hotelRooms[i].isOccupied = 0;
    }

    printf("Welcome to the C Hotel Management System!\n");

    while (1)
    {
        int choice;
        printf("\nWhat would you like to do?\n");
        printf("1. Book a room\n");
        printf("2. Check out of a room\n");
        printf("3. View room information\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Book a room
                int roomNumberToBook;
                printf("Enter the room number you would like to book: ");
                scanf("%d", &roomNumberToBook);

                if (hotelRooms[roomNumberToBook - 1].isOccupied)
                {
                    printf("Sorry, that room is already occupied.\n");
                }
                else
                {
                    hotelRooms[roomNumberToBook - 1].isOccupied = 1;
                    printf("Room %d has been booked.\n", roomNumberToBook);
                }
                break;

            case 2:
                // Check out of a room
                int roomNumberToCheckOut;
                printf("Enter the room number you would like to check out of: ");
                scanf("%d", &roomNumberToCheckOut);

                if (hotelRooms[roomNumberToCheckOut - 1].isOccupied)
                {
                    hotelRooms[roomNumberToCheckOut - 1].isOccupied = 0;
                    printf("You have checked out of room %d.\n", roomNumberToCheckOut);
                }
                else
                {
                    printf("Sorry, that room is not occupied.\n");
                }
                break;

            case 3:
                // View room information
                printf("Room\tBeds\tOccupied\n");
                for (int i = 0; i < numberOfRooms; i++)
                {
                    printf("%d\t%d\t", hotelRooms[i].roomNumber, hotelRooms[i].numberOfBeds);

                    if (hotelRooms[i].isOccupied)
                    {
                        printf("Yes\n");
                    }
                    else
                    {
                        printf("No\n");
                    }
                }
                break;

            case 4:
                // Exit the program
                printf("Thank you for using the C Hotel Management System.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}