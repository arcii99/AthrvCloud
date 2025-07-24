//FormAI DATASET v1.0 Category: Hotel Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining maximum hotel rooms
#define MAX_ROOMS 100

//Structure for holding hotel room details
typedef struct {
    char room_number[10];
    char room_type[20];
    char bed_type[20];
    float price;
    char status[20];
} room;

int main() {
    //Declare variables
    char choice;
    int num_rooms = 0, i;
    room hotel[MAX_ROOMS];

    //Initialize all rooms to be empty
    for (i = 0; i < MAX_ROOMS; i++) {
        strcpy(hotel[i].status, "EMPTY");
    }

    //Print main menu
    printf("            HOTEL MANAGEMENT SYSTEM\n");
    printf("----------------------------------------------\n");
    printf("1. Add Room\n");
    printf("2. Remove Room\n");
    printf("3. Display Rooms\n");
    printf("4. Exit\n");
    printf("----------------------------------------------\n");

    //Loop until user chooses to exit
    do {
        printf("\nEnter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': //Add Room
                if (num_rooms == MAX_ROOMS) {
                    printf("\nSorry, maximum rooms reached.");
                } else {
                    printf("\nEnter room number: ");
                    scanf("%s", hotel[num_rooms].room_number);

                    printf("Enter room type: ");
                    scanf("%s", hotel[num_rooms].room_type);

                    printf("Enter bed type: ");
                    scanf("%s", hotel[num_rooms].bed_type);

                    printf("Enter price: ");
                    scanf("%f", &hotel[num_rooms].price);

                    strcpy(hotel[num_rooms].status, "FULL");

                    printf("\nRoom added successfully!");
                    num_rooms++;
                }
                break;

            case '2': //Remove Room
                if (num_rooms == 0) {
                    printf("\nNo rooms to be removed.");
                } else {
                    char rnum[10];
                    printf("\nEnter room number to be removed: ");
                    scanf("%s", rnum);

                    for (i = 0; i < num_rooms; i++) {
                        if (strcmp(hotel[i].room_number, rnum) == 0) {
                            //Shift all other rooms back one index to fill the gap
                            for (int j = i; j < num_rooms - 1; j++) {
                                strcpy(hotel[j].room_number, hotel[j + 1].room_number);
                                strcpy(hotel[j].room_type, hotel[j + 1].room_type);
                                strcpy(hotel[j].bed_type, hotel[j + 1].bed_type);
                                hotel[j].price = hotel[j + 1].price;
                                strcpy(hotel[j].status, hotel[j + 1].status);
                            }
                            //Reset last room to empty
                            strcpy(hotel[num_rooms - 1].status, "EMPTY");
                            num_rooms--;
                            printf("\nRoom removed successfully!");
                            break;
                        }
                    }
                    if (i == num_rooms) {
                        printf("\nRoom not found.");
                    }
                }
                break;

            case '3': //Display Rooms
                printf("----------------------------------------------\n");
                printf("ROOM NUMBER\tROOM TYPE\tBED TYPE\tPRICE\tSTATUS\n");
                printf("----------------------------------------------\n");
                for (i = 0; i < num_rooms; i++) {
                    printf("%s\t%s\t\t%s\t\t%.2f\t%s\n", hotel[i].room_number, hotel[i].room_type, hotel[i].bed_type, hotel[i].price, hotel[i].status);
                }
                break;

            case '4': //Exit
                printf("\nExiting Program. Goodbye!\n");
                break;

            default: //Invalid choice
                printf("\nInvalid choice. Please try again.");
                break;
        }
    } while (choice != '4');

    return 0;
}