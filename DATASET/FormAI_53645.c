//FormAI DATASET v1.0 Category: Hotel Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
    int room_no;
    char room_type[20];
    int occupancy;
    float rate;
};

struct customer {
    char name[20];
    char address[50];
    char contact_no[15];
};

struct booking {
    struct customer cust;
    struct room rm;
    int duration;
    float bill_amount;
};

int main() {
    struct booking bookings[10]; // an array to keep track of bookings
    
    int choice;
    int index = 0; // index to keep track of the next available booking spot
    
    do {
        printf("\n--- HOTEL MANAGEMENT SYSTEM ---\n");
        printf("1. New Booking\n");
        printf("2. View Bookings\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // get customer details
                struct customer cust;
                printf("\nEnter Customer Details: \n");
                printf("Name: ");
                scanf("%s", cust.name);
                printf("Address: ");
                scanf("%s", cust.address);
                printf("Contact No.: ");
                scanf("%s", cust.contact_no);
                
                // display available rooms
                printf("\nAvailable Rooms: \n");
                struct room rm1 = { 101, "Single", 1, 50 };
                struct room rm2 = { 102, "Single", 1, 50 };
                struct room rm3 = { 201, "Double", 2, 75 };
                struct room rm4 = { 202, "Double", 2, 75 };
                printf("%d - %s - Occupancy: %d - Rate: %.2f\n", rm1.room_no, rm1.room_type, rm1.occupancy, rm1.rate);
                printf("%d - %s - Occupancy: %d - Rate: %.2f\n", rm2.room_no, rm2.room_type, rm2.occupancy, rm2.rate);
                printf("%d - %s - Occupancy: %d - Rate: %.2f\n", rm3.room_no, rm3.room_type, rm3.occupancy, rm3.rate);
                printf("%d - %s - Occupancy: %d - Rate: %.2f\n", rm4.room_no, rm4.room_type, rm4.occupancy, rm4.rate);
                
                // get user selected room
                int rm_choice;
                printf("\nEnter Room No.: ");
                scanf("%d", &rm_choice);
                struct room chosen_rm;
                switch(rm_choice) {
                    case 101:
                        chosen_rm = rm1;
                        break;
                    case 102:
                        chosen_rm = rm2;
                        break;
                    case 201:
                        chosen_rm = rm3;
                        break;
                    case 202:
                        chosen_rm = rm4;
                        break;
                    default:
                        printf("\nInvalid Room No.\n");
                        continue;
                }
                
                // get booking duration
                int duration;
                printf("\nEnter Booking Duration (in days): ");
                scanf("%d", &duration);
                
                // create and store the booking
                struct booking b;
                b.cust = cust;
                b.rm = chosen_rm;
                b.duration = duration;
                b.bill_amount = chosen_rm.rate * duration;
                bookings[index] = b;
                index++;
                printf("\nBooking Successful! Bill Amount: %.2f\n", b.bill_amount);
                break;
            case 2:
                // display all bookings
                printf("\n--- BOOKINGS ---\n");
                for (int i = 0; i < index; i++) {
                    struct booking curr_booking = bookings[i];
                    printf("Customer Name: %s\n", curr_booking.cust.name);
                    printf("Customer Address: %s\n", curr_booking.cust.address);
                    printf("Contact No.: %s\n", curr_booking.cust.contact_no);
                    printf("Room No.: %d\n", curr_booking.rm.room_no);
                    printf("Room Type: %s\n", curr_booking.rm.room_type);
                    printf("Occupancy: %d\n", curr_booking.rm.occupancy);
                    printf("Rate: %.2f\n", curr_booking.rm.rate);
                    printf("Duration: %d\n", curr_booking.duration);
                    printf("Total Bill Amount: %.2f\n", curr_booking.bill_amount);
                    printf("\n");
                }
                break;
            case 3:
                printf("\nBye!\n");
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
        }
    } while (1);
    
    return 0;
}