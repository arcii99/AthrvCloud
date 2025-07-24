//FormAI DATASET v1.0 Category: Hotel Management System ; Style: synchronous
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Room {
    int roomNumber;
    char roomType[50];
    int occupancy;
    int rent;
};
typedef struct Room Room;

struct Customer {
    char name[50];
    int age;
    char gender[7];
    char address[100];
    char mobileNumber[50];
    char email[50];
    int roomNumber;
};
typedef struct Customer Customer;

// Global Variables
int numRooms = 10;
Room rooms[10];
Customer* customers;
int numCustomers = 0;

void initializeRooms() {
    for(int i = 0; i < numRooms; i++) {
        rooms[i].roomNumber = i+1;
        strcpy(rooms[i].roomType, "Standard");
        rooms[i].occupancy = 1;
        rooms[i].rent = 1000;
    }
}

void printRooms() {
    printf("\nRoom Details:\n");
    printf("--------------------------------------------------\n");
    printf("| Room No. | Type       | Occupancy | Rent (per day) |\n");
    printf("--------------------------------------------------\n");
    for(int i = 0; i < numRooms; i++) {
        printf("| %-8d | %-10s | %-9d | %-15d |\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].occupancy, rooms[i].rent);
    }
    printf("--------------------------------------------------\n");
}

int isRoomAvailable(int roomNumber) {
    for(int i = 0; i < numCustomers; i++) {
        if(customers[i].roomNumber == roomNumber) {
            return 0;
        }
    }
    return 1;
}

void addCustomer() {
    Customer customer;
    printf("\nEnter Customer Details:\n");
    printf("Name: ");
    fflush(stdin);
    gets(customer.name);
    printf("Age: ");
    scanf("%d", &customer.age);
    printf("Gender: ");
    fflush(stdin);
    gets(customer.gender);
    printf("Address: ");
    fflush(stdin);
    gets(customer.address);
    printf("Mobile No.: ");
    fflush(stdin);
    gets(customer.mobileNumber);
    printf("Email: ");
    fflush(stdin);
    gets(customer.email);
    while(1) {
        printRooms();
        printf("Enter Room Number: ");
        scanf("%d", &customer.roomNumber);
        if(customer.roomNumber >= 1 && customer.roomNumber <= numRooms) {
            if(isRoomAvailable(customer.roomNumber)) {
                break;
            } else {
                printf("Room is already occupied.\n");
            }
        } else {
            printf("Invalid Room Number.\n");
        }
    }
    numCustomers++;
    customers = (Customer*)realloc(customers, numCustomers*sizeof(Customer));
    customers[numCustomers-1] = customer;
    printf("\nCustomer added successfully!\n");
}

void printCustomers() {
    printf("\nCustomer Details:\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("| Name        | Age | Gender | Address                                                | Mobile No.   | Email                    | Room No. |\n");
    printf("----------------------------------------------------------------------------------------\n");
    for(int i = 0; i < numCustomers; i++) {
        printf("| %-12s | %-3d | %-6s | %-54s | %-12s | %-24s | %-8d |\n", customers[i].name, customers[i].age, customers[i].gender, customers[i].address, customers[i].mobileNumber, customers[i].email, customers[i].roomNumber);
    }
    printf("----------------------------------------------------------------------------------------\n");
}

void printMenu() {
    printf("\nMenu:\n");
    printf("---------------------------------------------------------------\n");
    printf("| 1. Add Customer | 2. View Customers | 3. Exit                 |\n");
    printf("---------------------------------------------------------------\n");
}

int main() {
    initializeRooms();
    while(1) {
        printMenu();
        int option;
        scanf("%d", &option);
        switch(option) {
            case 1:
                addCustomer();
                break;
            case 2:
                printCustomers();
                break;
            case 3:
                printf("\nExiting the program...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid Option! Try Again.\n");
                break;
        }
    }
    return 0;
}