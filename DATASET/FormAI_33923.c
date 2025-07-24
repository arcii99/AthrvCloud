//FormAI DATASET v1.0 Category: Hotel Management System ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Structure for hotel rooms
typedef struct {
    int room_no;
    char room_type[10];
    int price;
} Room;

// Structure for guest details
typedef struct {
    char name[50];
    char address[100];
    char phone_no[15];
    int room_no;
} Guest;

int main() {
    Room rooms[50]; // Array of rooms
    Guest guests[50]; // Array of guest details
    int num_rooms = 50; // Total number of rooms in the hotel
    int num_guests = 0; // Total number of guests currently staying in the hotel
    
    // Initializing the hotel rooms
    for(int i=0;i<num_rooms;i++) {
        rooms[i].room_no = i+1;
        if(i%10 < 4) {
            strcpy(rooms[i].room_type, "Standard");
            rooms[i].price = 100;
        }
        else if(i%10 >= 4 && i%10 < 7) {
            strcpy(rooms[i].room_type, "Deluxe");
            rooms[i].price = 150;
        }
        else {
            strcpy(rooms[i].room_type, "Luxury");
            rooms[i].price = 200;
        }
    }
    
    // Main menu
    printf("Welcome to C Hotel Management System!\n");
    while(1) {
        printf("\n====================\n");
        printf("1. Check-in\n");
        printf("2. Check-out\n");
        printf("3. Display guest details\n");
        printf("4. Room availability\n");
        printf("5. Exit\n");
        printf("====================\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        getchar(); // To remove '\n' from input buffer
        
        switch(choice) {
            case 1: // Check-in
                printf("\nEnter guest details:\n");
                printf("Name: ");
                fgets(guests[num_guests].name, 50, stdin);
                printf("Address: ");
                fgets(guests[num_guests].address, 100, stdin);
                printf("Phone no: ");
                fgets(guests[num_guests].phone_no, 15, stdin);
                printf("Select room type (Standard/Deluxe/Luxury): ");
                char room_type[10];
                fgets(room_type, 10, stdin);
                // Removing '\n' from room_type
                room_type[strcspn(room_type, "\n")] = 0;
                if(strcmp(room_type,"Standard")==0) {
                    // Checking if any Standard room is available
                    int flag = 0;
                    for(int i=0;i<num_rooms;i++) {
                        if(strcmp(rooms[i].room_type,"Standard")==0) {
                            flag = 1;
                            guests[num_guests].room_no = rooms[i].room_no;
                            break; // Assigning the first available room
                        }
                    }
                    if(flag == 0) {
                        printf("\nSorry, no Standard rooms available.\n");
                        break;
                    }
                }
                else if(strcmp(room_type,"Deluxe")==0) {
                    // Checking if any Deluxe room is available
                    int flag = 0;
                    for(int i=0;i<num_rooms;i++) {
                        if(strcmp(rooms[i].room_type,"Deluxe")==0) {
                            flag = 1;
                            guests[num_guests].room_no = rooms[i].room_no;
                            break; // Assigning the first available room
                        }
                    }
                    if(flag == 0) {
                        printf("\nSorry, no Deluxe rooms available.\n");
                        break;
                    }
                }
                else if(strcmp(room_type,"Luxury")==0) {
                    // Checking if any Luxury room is available
                    int flag = 0;
                    for(int i=0;i<num_rooms;i++) {
                        if(strcmp(rooms[i].room_type,"Luxury")==0) {
                            flag = 1;
                            guests[num_guests].room_no = rooms[i].room_no;
                            break; // Assigning the first available room
                        }
                    }
                    if(flag == 0) {
                        printf("\nSorry, no Luxury rooms available.\n");
                        break;
                    }
                }
                else {
                    printf("\nInvalid room type.\n");
                    break;
                }
                printf("\nGuest checked-in successfully!\n");
                num_guests++;
                break;
                
            case 2: // Check-out
                printf("\nEnter room number to check-out: ");
                int room_no;
                scanf("%d",&room_no);
                int flag = 0;
                for(int i=0;i<num_guests;i++) {
                    if(guests[i].room_no == room_no) {
                        printf("\nGuest details:\n");
                        printf("Name: %s",guests[i].name);
                        printf("Address: %s",guests[i].address);
                        printf("Phone no: %s",guests[i].phone_no);
                        printf("Room no: %d\n",guests[i].room_no);
                        flag = 1;
                        // Removing guest details from the array after check-out
                        for(int j=i;j<num_guests-1;j++) {
                            guests[j] = guests[j+1];
                        }
                        num_guests--;
                        break;
                    }
                }
                if(flag == 0) {
                    printf("\nNo guests found in room %d.\n",room_no);
                }
                else {
                    printf("\nGuest checked-out successfully!\n");
                }
                break;
            
            case 3: // Display guest details
                if(num_guests == 0) {
                    printf("\nNo guests currently staying in the hotel.\n");
                }
                else {
                    printf("\nGuest details:\n");
                    for(int i=0;i<num_guests;i++) {
                        printf("Name: %s",guests[i].name);
                        printf("Address: %s",guests[i].address);
                        printf("Phone no: %s",guests[i].phone_no);
                        printf("Room no: %d\n",guests[i].room_no);
                    }
                }
                break;
                
            case 4: // Room availability
                printf("\nRoom availability:\n");
                printf("Room no\tRoom type\tPrice\n");
                for(int i=0;i<num_rooms;i++) {
                    printf("%d\t%s\t\t%d\n",rooms[i].room_no,rooms[i].room_type,rooms[i].price);
                }
                break;
                
            case 5: // Exit
                printf("\nThank you for using C Hotel Management System!\n");
                exit(0);
                break;
            
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    return 0;
}