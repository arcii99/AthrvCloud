//FormAI DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Room{
    int room_number;
    char room_type[20];
    int room_price;
    int check_in_status;
};

struct Customer{
    char name[50];
    int age;
    char address[100];
    char contact_number[15];
    char email[50];
    int room_number;
};

struct Room rooms[50];
struct Customer customers[50];
int total_customers = 0;

void init_rooms(){
    for(int i = 0; i < 50; i++){
        rooms[i].room_number = i+1;
        strcpy(rooms[i].room_type, "Standard");
        rooms[i].room_price = 4000;
        rooms[i].check_in_status = 0;
    }
}

void print_menu(){
    printf("\n\n--- Welcome to C Hotel Management System ---\n");
    printf("1. Book a Room\n");
    printf("2. Check out\n");
    printf("3. View Occupied Rooms\n");
    printf("4. View Available Rooms\n");
    printf("5. View Customer History\n");
    printf("6. Exit\n\n");
}

int get_available_room_number(){
    int room_number;
    printf("\nEnter Room Number (1-50): ");
    scanf("%d", &room_number);
    if(room_number < 1 || room_number > 50){
        printf("\nInvalid Room Number. Please try again.\n");
        get_available_room_number();
    }
    else if(rooms[room_number-1].check_in_status == 1){
        printf("\nRoom Already Occupied. Please Select Another Room.\n");
        get_available_room_number();
    }
    return room_number;
}

void book_room(){
    char name[50], address[100], contact_number[15], email[50];
    int age, room_number;

    printf("\nEnter Customer Details\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Age: ");
    scanf("%d", &age);
    printf("Address: ");
    scanf("%s", address);
    printf("Contact Number: ");
    scanf("%s", contact_number);
    printf("Email: ");
    scanf("%s", email);

    room_number = get_available_room_number();
    rooms[room_number-1].check_in_status = 1;

    strcpy(customers[total_customers].name, name);
    customers[total_customers].age = age;
    strcpy(customers[total_customers].address, address);
    strcpy(customers[total_customers].contact_number, contact_number);
    strcpy(customers[total_customers].email, email);
    customers[total_customers].room_number = room_number;

    printf("\nRoom Booked Successfully!\n");
    printf("Customer Details:\n");
    printf("Name: %s\n", customers[total_customers].name);
    printf("Age: %d\n", customers[total_customers].age);
    printf("Address: %s\n", customers[total_customers].address);
    printf("Contact Number: %s\n", customers[total_customers].contact_number);
    printf("Email: %s\n", customers[total_customers].email);
    printf("Room Number: %d\n", customers[total_customers].room_number);
    printf("Room Price: %d\n", rooms[room_number-1].room_price);

    total_customers++;
}

void check_out(){
    int room_number;
    printf("\nEnter Room Number to Check Out: ");
    scanf("%d", &room_number);
    if(room_number < 1 || room_number > 50){
        printf("\nInvalid Room Number. Please try again.\n");
        check_out();
    }
    else if(rooms[room_number-1].check_in_status == 0){
        printf("\nRoom is Empty. No Check Out Possible.\n");
    }
    else{
        rooms[room_number-1].check_in_status = 0;
        printf("\nCheck Out Successfull!\n");
    }
}

void view_occupied_rooms(){
    printf("\n--- Occupied Rooms ---\n");
    printf("Room Number\tCustomer Name\n");
    for(int i = 0; i < 50; i++){
        if(rooms[i].check_in_status == 1){
            printf("%d\t\t%s\n", i+1, customers[i].name);
        }
    }
}

void view_available_rooms(){
    printf("\n--- Available Rooms ---\n");
    printf("Room Number\tRoom Type\tRoom Price\n");
    for(int i = 0; i < 50; i++){
        if(rooms[i].check_in_status == 0){
            printf("%d\t\t%s\t\t%d\n", i+1, rooms[i].room_type, rooms[i].room_price);
        }
    }
}

void view_customer_history(){
    printf("\n--- Customer History ---\n");
    printf("Name\tAge\tAddress\tContact Number\tEmail\t\tRoom Number\n");
    for(int i = 0; i < total_customers; i++){
        printf("%s\t%d\t%s\t%s\t\t%s\t%d\n", customers[i].name, customers[i].age, customers[i].address, customers[i].contact_number, customers[i].email, customers[i].room_number);
    }
}

int main(){
    init_rooms();

    while(1){
        print_menu();
        int choice;
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                book_room();
                break;
            case 2:
                check_out();
                break;
            case 3:
                view_occupied_rooms();
                break;
            case 4:
                view_available_rooms();
                break;
            case 5:
                view_customer_history();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice. Please try again.\n");
        }
    }
    return 0;
}