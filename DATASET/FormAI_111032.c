//FormAI DATASET v1.0 Category: Hotel Management System ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declaration of structures
struct Customer {
    char name[50];
    char address[100];
    char room_type[10];
    int room_num;
    int days;
};

struct Room {
    int room_num;
    char status[10];
    char type[10];
    float price;
};

// Function to check if the entered room number is valid or not
int check_valid_room(int num, struct Room rooms[]) {
    int found = 0, i;
    for (i = 0; i < 20; i++) {
        if (rooms[i].room_num == num) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Invalid room number. Please enter a valid room number.\n");
        return 0;
    } else {
        if (strcmp(rooms[i].status, "Available") != 0) {
            printf("Room is already occupied. Please choose another room.\n");
            return 0;
        } else {
            return 1;
        }
    }
}

int main() {
    // Declaration of variables
    int i, choice, room_num, num_customers = 0;
    float amount_due = 0.0;
    struct Customer customers[20];
    struct Room rooms[20];

    // Initialization of rooms
    for (i = 0; i < 20; i++) {
        rooms[i].room_num = i + 1;
        strcpy(rooms[i].status, "Available");
        if (i < 5) {
            strcpy(rooms[i].type, "Single");
            rooms[i].price = 1000.0;
        } else if (i < 10) {
            strcpy(rooms[i].type, "Double");
            rooms[i].price = 1500.0;
        } else if (i < 15) {
            strcpy(rooms[i].type, "Suite");
            rooms[i].price = 2500.0;
        } else {
            strcpy(rooms[i].type, "Presidential");
            rooms[i].price = 5000.0;
        }
    }

    do {
        // Menu
        printf("\n\n==============================\n");
        printf("       Hotel Management        \n");
        printf("==============================\n");
        printf("1. Check-in\n");
        printf("2. Check-out\n");
        printf("3. Display Room Status\n");
        printf("4. Print Customer Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Check-in
                printf("Enter customer name: ");
                scanf("%s", customers[num_customers].name);
                printf("Enter customer address: ");
                scanf("%s", customers[num_customers].address);

                // Displaying available rooms
                printf("\n\n======= Available Rooms =======\n");
                printf("Room No. \t Type \t\t Rate\n");
                for (i = 0; i < 20; i++) {
                    if (strcmp(rooms[i].status, "Available") == 0) {
                        printf("%d \t\t %s \t Rs. %.2f\n", rooms[i].room_num, rooms[i].type, rooms[i].price);
                    }
                }
                printf("Enter room number: ");
                scanf("%d", &room_num);

                // Checking if selected room is valid
                if (check_valid_room(room_num, rooms)) {
                    customers[num_customers].room_num = room_num;
                    printf("Enter number of days to stay: ");
                    scanf("%d", &customers[num_customers].days);
                    printf("Enter room type (Single/Double/Suite/Presidential): ");
                    scanf("%s", customers[num_customers].room_type);

                    // Updating room status
                    for (i = 0; i < 20; i++) {
                        if (rooms[i].room_num == room_num) {
                            strcpy(rooms[i].status, "Occupied");
                            break;
                        }
                    }

                    // Calculating amount due
                    for (i = 0; i < 20; i++) {
                        if (strcmp(customers[num_customers].room_type, rooms[i].type) == 0) {
                            amount_due += rooms[i].price * customers[num_customers].days;
                            break;
                        }
                    }

                    num_customers++;
                    printf("Check-in successful.\n");
                }

                break;

            case 2: // Check-out
                printf("Enter room number: ");
                scanf("%d", &room_num);

                // Checking if selected room is valid
                if (check_valid_room(room_num, rooms)) {
                    // Updating room status
                    for (i = 0; i < 20; i++) {
                        if (rooms[i].room_num == room_num) {
                            strcpy(rooms[i].status, "Available");
                            break;
                        }
                    }

                    // Calculating amount due and displaying customer details
                    for (i = 0; i < 20; i++) {
                        if (customers[i].room_num == room_num) {
                            for (int j = 0; j < 20; j++) {
                                if (strcmp(customers[i].room_type, rooms[j].type) == 0) {
                                    amount_due += rooms[j].price * customers[i].days;
                                    break;
                                }
                            }
                            printf("Customer Name: %s\n", customers[i].name);
                            printf("Address: %s\n", customers[i].address);
                            printf("Room No.: %d\n", customers[i].room_num);
                            printf("Room Type: %s\n", customers[i].room_type);
                            printf("No. of days: %d\n", customers[i].days);
                            printf("Amount Due: Rs. %.2f\n", amount_due);
                            break;
                        }
                    }

                    printf("Check-out successful.\n");
                }

                break;

            case 3: // Display Room Status
                printf("\n\n======= Room Status =======\n");
                printf("Room No. \t Status \t Type \n");
                for (i = 0; i < 20; i++) {
                    printf("%d \t\t %s \t %s \n", rooms[i].room_num, rooms[i].status, rooms[i].type);
                }
                break;

            case 4: // Print Customer Details
                printf("\n\n======= Customer Details =======\n");
                printf("Name \t\t Room No. \t Room Type\n");
                for (i = 0; i < num_customers; i++) {
                    printf("%s \t\t %d \t\t %s \n", customers[i].name, customers[i].room_num, customers[i].room_type);
                }
                break;

            case 5: // Exit
                printf("Thank you for using our hotel management system.\n");
                exit(0);

            default:
                printf("Invalid choice. Please choose again.\n");
        }

    } while (1);

    return 0;
}