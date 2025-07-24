//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

typedef struct {
    char hotel_name[50];
    int num_rooms;
    float room_price;
    int num_booked;
    int num_avail;
} hotel;

hotel hotels[5];

void initialize_hotels() {
    strcpy(hotels[0].hotel_name, "NeoRetro Hotel");
    hotels[0].num_rooms = 50;
    hotels[0].room_price = 100.00;
    hotels[0].num_booked = 0;
    hotels[0].num_avail = 50;

    strcpy(hotels[1].hotel_name, "The Cyber Arms Hotel");
    hotels[1].num_rooms = 75;
    hotels[1].room_price = 150.00;
    hotels[1].num_booked = 0;
    hotels[1].num_avail = 75;

    strcpy(hotels[2].hotel_name, "The I/O Tower Hotel");
    hotels[2].num_rooms = 100;
    hotels[2].room_price = 200.00;
    hotels[2].num_booked = 0;
    hotels[2].num_avail = 100;

    strcpy(hotels[3].hotel_name, "The Code Breaker Hotel");
    hotels[3].num_rooms = 125;
    hotels[3].room_price = 250.00;
    hotels[3].num_booked = 0;
    hotels[3].num_avail = 125;

    strcpy(hotels[4].hotel_name, "Mind Hack Hotel");
    hotels[4].num_rooms = 150;
    hotels[4].room_price = 300.00;
    hotels[4].num_booked = 0;
    hotels[4].num_avail = 150;
}

void print_hotels() {
    printf("\nAvailable Hotels: \n");
    for(int i=0; i<5; i++) {
        printf("%d: %s\n", i+1, hotels[i].hotel_name);
    }
}

void book_room(int hotel_choice, int num_rooms) {
    if(hotels[hotel_choice-1].num_avail >= num_rooms) {
        hotels[hotel_choice-1].num_booked += num_rooms;
        hotels[hotel_choice-1].num_avail -= num_rooms;
        printf("Booking confirmed!\n");
        printf("Hotel: %s\n", hotels[hotel_choice-1].hotel_name);
        printf("Number of rooms: %d\n", num_rooms);
        printf("Room price per night: $%.2f\n", hotels[hotel_choice-1].room_price);
        printf("Total price: $%.2f\n", hotels[hotel_choice-1].room_price * num_rooms);
        printf("Thank you for choosing our hotel!\n");
    }
    else {
        printf("Sorry, not enough rooms available at %s\n", hotels[hotel_choice-1].hotel_name);
    }
}

int main() {
    initialize_hotels();

    printf("*** WELCOME TO THE CYBERPUNK HOTELS BOOKING SYSTEM ***\n");

    int choice, num_rooms;
    do {
        print_hotels();
        printf("Select a hotel to book (Enter 0 to exit): ");
        scanf("%d", &choice);
        if(choice == 0) {
            printf("Thank you for visiting us!\n");
            return 0;
        }
        else if(choice > 0 && choice <= 5) {
            printf("How many rooms do you want to book?: ");
            scanf("%d", &num_rooms);
            book_room(choice, num_rooms);
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    } while(1);

    return 0;
}