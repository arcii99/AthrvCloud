//FormAI DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest{
    char name[50];
    int room_no;
    char check_in_date[15];
    char check_out_date[15];
};

struct room{
    int room_no;
    char room_type[20];
    int occupancy_status;
};

void display_menu(){
    printf("==== HOTEL MANAGEMENT SYSTEM ====\n");
    printf("1. Check-in a guest\n");
    printf("2. Check-out a guest\n");
    printf("3. Print guest list\n");
    printf("4. Print room availability list\n");
    printf("5. Exit the program\n");
    printf("==================================\n");
    printf("Enter your choice: ");
}

void check_in(struct guest *guest_list, struct room *room_list, int *guest_count, int *room_count){
    printf("Enter guest name: ");
    scanf("%s", guest_list[*guest_count].name);
    printf("Enter room number: ");
    scanf("%d", &guest_list[*guest_count].room_no);
    printf("Enter check-in date (dd/mm/yyyy): ");
    scanf("%s", guest_list[*guest_count].check_in_date);
    strcpy(room_list[guest_list[*guest_count].room_no - 101].room_type, "Occupied");
    room_list[guest_list[*guest_count].room_no - 101].occupancy_status = 1;
    printf("Guest checked in successfully!\n");
    (*guest_count)++;
    (*room_count)--;
}

void check_out(struct guest *guest_list, struct room *room_list, int *guest_count, int *room_count){
    int room_no, i, found = 0;
    printf("Enter room number: ");
    scanf("%d", &room_no);
    for(i=0; i<*guest_count; i++){
        if(guest_list[i].room_no == room_no){
            printf("Guest name: %s\n", guest_list[i].name);
            printf("Check-in date: %s\n", guest_list[i].check_in_date);
            printf("Check-out date: ");
            scanf("%s", guest_list[i].check_out_date);
            strcpy(room_list[guest_list[i].room_no - 101].room_type, "Vacant");
            room_list[guest_list[i].room_no - 101].occupancy_status = 0;
            printf("Guest checked out successfully!\n");
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("Room number not found or unoccupied!\n");
    }
    (*room_count)++;
}

void print_guest_list(struct guest *guest_list, int *guest_count){
    int i;
    printf("=== Guest List ===\n");
    printf("Name\t\tRoom No\t\tCheck-in date\t\tCheck-out date\n");
    for(i=0; i<*guest_count; i++){
        printf("%s\t\t%d\t\t%s\t\t%s\n", guest_list[i].name, guest_list[i].room_no, guest_list[i].check_in_date, guest_list[i].check_out_date);
    }
}

void print_room_list(struct room *room_list, int *room_count){
    int i;
    printf("=== Room List ===\n");
    printf("Room No\t\tRoom Type\t\tOccupancy Status\n");
    for(i=0; i<100; i++){
        printf("%d\t\t%s\t\t%s\n", room_list[i].room_no, room_list[i].room_type, room_list[i].occupancy_status == 1 ? "Occupied" : "Vacant");
    }
}

int main(){
    struct guest guest_list[100];
    struct room room_list[100];
    int guest_count = 0;
    int room_count = 100;
    int choice;
    int i;
    for(i=0; i<100; i++){
        room_list[i].room_no = i + 101;
        strcpy(room_list[i].room_type, "Vacant");
        room_list[i].occupancy_status = 0;
    }
    do{
        display_menu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(room_count == 0){
                    printf("No rooms available!\n");
                    break;
                }
                check_in(guest_list, room_list, &guest_count, &room_count);
                break;
            case 2:
                check_out(guest_list, room_list, &guest_count, &room_count);
                break;
            case 3:
                print_guest_list(guest_list, &guest_count);
                break;
            case 4:
                print_room_list(room_list, &room_count);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }while(1);
    return 0;
}