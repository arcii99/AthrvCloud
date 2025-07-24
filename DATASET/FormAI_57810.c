//FormAI DATASET v1.0 Category: Hotel Management System ; Style: automated
#include<stdio.h>
#include<stdlib.h>

struct room {
    int room_number;
    char type[20];
    int price;
    int status; // 0 for unoccupied, 1 for occupied
};

struct customer {
    char name[50];
    int age;
    char gender;
    char address[100];
    char phone[15];
    int room_number;
};

int main() {

    // Creating an array of rooms
    struct room hotel[10];

    // Initializing the rooms 
    for(int i=0; i<10; i++) {
        hotel[i].room_number = i+1;
        switch(i%3) {
            case 0:
                strcpy(hotel[i].type, "Single");
                hotel[i].price = 1000;
                break;
            case 1:
                strcpy(hotel[i].type, "Double");
                hotel[i].price = 1500;
                break;
            case 2:
                strcpy(hotel[i].type, "Suite");
                hotel[i].price = 2000;
                break;
        }
        hotel[i].status = 0; // rooms are initially unoccupied
    }

    // Creating an array of customers
    struct customer customers[10];

    // Main Menu
    int choice;
    do {
        printf("\n\n");
        printf("1. Check Room Availability\n");
        printf("2. Book a Room\n");
        printf("3. View Customer Details\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n\n");
                printf("Room No  Type    Price   Status\n");
                for(int i=0; i<10; i++) {
                    printf("%-8d%-8s%-8d", hotel[i].room_number, hotel[i].type, hotel[i].price);
                    if(hotel[i].status == 0) {
                        printf("Unoccupied\n");
                    } else {
                        printf("Occupied\n");
                    }
                }
                break;
            case 2:
                printf("\n\n");
                printf("Enter your details:\n");
                printf("Name: ");
                scanf("%s", customers[0].name);
                printf("Age: ");
                scanf("%d", &customers[0].age);
                printf("Gender: ");
                scanf(" %c", &customers[0].gender);
                printf("Address: ");
                scanf("%s", customers[0].address);
                printf("Phone: ");
                scanf("%s", customers[0].phone);

                printf("\n\n");
                printf("Select a room type:\n");
                printf("1. Single\n");
                printf("2. Double\n");
                printf("3. Suite\n");
                printf("Enter your choice: ");
                int type_choice;
                scanf("%d", &type_choice);

                int available_room = -1;
                for(int i=0; i<10; i++) {
                    if(hotel[i].status == 0 && strcmp(hotel[i].type, "Single") == 0 && type_choice == 1) {
                        available_room = i;
                        break;
                    } else if(hotel[i].status == 0 && strcmp(hotel[i].type, "Double") == 0 && type_choice == 2) {
                        available_room = i;
                        break;
                    } else if(hotel[i].status == 0 && strcmp(hotel[i].type, "Suite") == 0 && type_choice == 3) {
                        available_room = i;
                        break;
                    }
                }

                if(available_room == -1) {
                    printf("\n\nNo rooms of selected type are available!");
                } else {
                    customers[0].room_number = hotel[available_room].room_number;
                    hotel[available_room].status = 1;
                    printf("\n\nCongratulations! Room booked successfully.");
                    printf("\n\nRoom Details\n");
                    printf("Room Number: %d\n", customers[0].room_number);
                    printf("Type: %s\n", hotel[available_room].type);
                    printf("Price: %d\n", hotel[available_room].price);
                }
                break;
            case 3:
                printf("\n\n");
                printf("Enter the name of the customer: ");
                char search_name[50];
                scanf("%s", search_name);
                int found = 0;
                for(int i=0; i<10; i++) {
                    if(strcmp(search_name, customers[i].name) == 0) {
                        printf("\n\nName: %s", customers[i].name);
                        printf("\nAge: %d", customers[i].age);
                        printf("\nGender: %c", customers[i].gender);
                        printf("\nAddress: %s", customers[i].address);
                        printf("\nPhone: %s", customers[i].phone);
                        printf("\nRoom Details\n");
                        printf("Room Number: %d\n", customers[i].room_number);
                        for(int j=0; j<10; j++) {
                            if(hotel[j].room_number == customers[i].room_number) {
                                printf("Type: %s\n", hotel[j].type);
                                printf("Price: %d\n", hotel[j].price);
                                break;
                            }
                        }
                        found = 1;
                        break;
                    }
                }
                if(found == 0) {
                    printf("\n\nCustomer not found!");
                }
                break;
            case 4:
                printf("\n\nThank you for choosing our hotel!");
                break;
            default:
                printf("\n\nInvalid choice. Please try again.");
                break;
        }

    } while(choice != 4);

    return 0;
}