//FormAI DATASET v1.0 Category: Hotel Management System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct room {
    int roomNumber;
    char roomType[10];
    int roomCapacity;
    char roomStatus[20];
} Room;

typedef struct booking {
    int bookingID;
    int roomNumber;
    char guestName[50];
    char checkInDate[15];
    char checkOutDate[15];
    char bookingStatus[20];
} Booking;

int main() {
    Room hotel[50];
    Booking bookings[100];
    int totalRooms = 50;
    int totalBookings = 0;

    //initialize hotel rooms with default values
    for(int i=0; i<50; i++) {
        hotel[i].roomNumber = i+1;
        strcpy(hotel[i].roomType, "regular");
        hotel[i].roomCapacity = 2;
        strcpy(hotel[i].roomStatus, "available");
    }

    printf("Welcome to C Hotel Management System\n");
    printf("-----------------------------------\n\n");

    int option;
    do {
        printf("Menu:\n");
        printf("1. View room status\n");
        printf("2. Check room availability\n");
        printf("3. Make a booking\n");
        printf("4. View booking details\n");
        printf("5. Cancel a booking\n");
        printf("6. Exit\n");
        printf("Enter option (1-6): ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                //view room status
                printf("\nRoom Number\tRoom Type\tCapacity\tStatus\n");
                for(int i=0; i<totalRooms; i++) {
                    printf("%d\t\t%s\t\t%d\t\t%s\n", hotel[i].roomNumber, hotel[i].roomType, hotel[i].roomCapacity, hotel[i].roomStatus);
                }
                printf("\n");
                break;
            case 2:
                //check room availability
                int roomNumber;
                printf("\nEnter room number: ");
                scanf("%d", &roomNumber);

                if(roomNumber < 1 || roomNumber > totalRooms) {
                    printf("Invalid room number\n");
                    break;
                }

                if(strcmp(hotel[roomNumber-1].roomStatus, "available") == 0) {
                    printf("Room %d is available\n", roomNumber);
                } else {
                    printf("Room %d is not available\n", roomNumber);
                }
                break;
            case 3:
                //make a booking
                if(totalBookings == 100) {
                    printf("Booking limit reached. Cannot make new booking\n");
                    break;
                }

                int availableRooms[50];
                int count = 0;
                printf("\nAvailable rooms:\n");
                printf("Room Number\tRoom Type\tCapacity\tStatus\n");
                for(int i=0; i<totalRooms; i++) {
                    if(strcmp(hotel[i].roomStatus, "available") == 0) {
                        printf("%d\t\t%s\t\t%d\t\t%s\n", hotel[i].roomNumber, hotel[i].roomType, hotel[i].roomCapacity, hotel[i].roomStatus);
                        availableRooms[count++] = i;
                    }
                }

                if(count == 0) {
                    printf("No available rooms. Cannot make new booking\n");
                    break;
                }

                Booking newBooking;
                printf("\nEnter guest name: ");
                scanf("%s", newBooking.guestName);
                printf("Enter check-in date (dd-mm-yyyy): ");
                scanf("%s", newBooking.checkInDate);
                printf("Enter check-out date (dd-mm-yyyy): ");
                scanf("%s", newBooking.checkOutDate);
                newBooking.bookingID = totalBookings + 1;
                newBooking.bookingStatus[0] = '\0';
                printf("Select room number (1-%d): ", count);
                int selectedRoomIndex;
                scanf("%d", &selectedRoomIndex);
                newBooking.roomNumber = availableRooms[selectedRoomIndex-1] + 1;

                hotel[newBooking.roomNumber-1].roomStatus[0] = '\0';
                strcpy(hotel[newBooking.roomNumber-1].roomStatus, "booked");

                bookings[totalBookings++] = newBooking;

                printf("\nNew booking created successfully\n");
                printf("Booking ID: %d\nRoom Number: %d\nGuest Name: %s\nCheck-in date: %s\nCheck-out date: %s\n", newBooking.bookingID, newBooking.roomNumber, newBooking.guestName, newBooking.checkInDate, newBooking.checkOutDate);
                printf("\n");
                break;
            case 4:
                //view booking details
                if(totalBookings == 0) {
                    printf("No bookings found\n");
                    break;
                }

                int bookingID;
                printf("\nEnter booking ID: ");
                scanf("%d", &bookingID);

                for(int i=0; i<totalBookings; i++) {
                    if(bookings[i].bookingID == bookingID) {
                        printf("Booking ID: %d\nRoom Number: %d\nGuest Name: %s\nCheck-in date: %s\nCheck-out date: %s\nBooking Status: %s\n", bookings[i].bookingID, bookings[i].roomNumber, bookings[i].guestName, bookings[i].checkInDate, bookings[i].checkOutDate, bookings[i].bookingStatus);
                        printf("\n");
                        break;
                    }

                    if(i == totalBookings-1) {
                        printf("Booking with ID %d not found\n", bookingID);
                    }
                }
                break;
            case 5:
                //cancel a booking
                if(totalBookings == 0) {
                    printf("No bookings found\n");
                    break;
                }

                printf("\nEnter booking ID: ");
                scanf("%d", &bookingID);

                for(int i=0; i<totalBookings; i++) {
                    if(bookings[i].bookingID == bookingID) {
                        hotel[bookings[i].roomNumber-1].roomStatus[0] = '\0';
                        strcpy(hotel[bookings[i].roomNumber-1].roomStatus, "available");
                        for(int j=i; j<totalBookings-1; j++) {
                            bookings[j] = bookings[j+1];
                        }
                        totalBookings--;

                        printf("Booking with ID %d cancelled successfully\n", bookingID);
                        break;
                    }

                    if(i == totalBookings-1) {
                        printf("Booking with ID %d not found\n", bookingID);
                    }
                }
                break;
            case 6:
                //exit
                printf("Exiting C Hotel Management System\n");
                break;
            default:
                printf("Invalid option. Please select option (1-6)\n");
        }

    } while(option != 6);

    return 0;
}