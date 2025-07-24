//FormAI DATASET v1.0 Category: Hotel Management System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

struct room{
    int room_no;
    char type[20];
    char status[10];
};

struct customer{
    char name[50];
    char address[100];
    char contact[15];
    int room_no;
};

struct bill{
    int room_no;
    int days;
    int charges;
};

struct room rooms[50];
struct customer customers[50];
struct bill bills[50];

int num_rooms=50;

void book_room(){
    int i,room_no;
    char choice;
    printf("\nEnter the Room Number:");
    scanf("%d",&room_no);
    for(i=0;i<num_rooms;i++){
        if(rooms[i].room_no==room_no){
            if(strcmp(rooms[i].status,"unoccupied")==0){
                printf("\nThe Room is Available for Booking.\n");
                printf("\nDo you want to book this room(y/n):");
                scanf(" %c",&choice);
                if(choice=='y'){
                    printf("\nEnter your name:");
                    scanf("%s",customers[i].name);
                    printf("\nEnter your address:");
                    scanf("%s",customers[i].address);
                    printf("\nEnter your contact number:");
                    scanf("%s",customers[i].contact);
                    customers[i].room_no=room_no;
                    printf("\nRoom Booked Successfully!!!\n");
                    strcpy(rooms[i].status,"occupied");
                    break;
                }
                else{
                    printf("\nBooking Cancelled!!!\n");
                    break;
                }
            }
            else{
                printf("\nThe Room is already Occupied!!!\n");
                break;
            }
        }
    }
    if(i==num_rooms){
        printf("\nInvalid Room Number!!!\n");
    }
}

void view_customer_list(){
    int i;
    printf("\nCustomer List:\n");
    printf("Name\tAddress\tContact No.\tRoom No.\n");
    for(i=0;i<num_rooms;i++){
        if(strcmp(rooms[i].status,"occupied")==0){
            printf("%s\t%s\t%s\t\t%d\n",customers[i].name,customers[i].address,customers[i].contact,customers[i].room_no);
        }
    }
}

void view_available_rooms(){
    int i;
    printf("\nAvailable Rooms:\n");
    printf("Room Number\tRoom Type\tStatus\n");
    for(i=0;i<num_rooms;i++){
        if(strcmp(rooms[i].status,"unoccupied")==0){
            printf("%d\t\t%s\t\t%s\n",rooms[i].room_no,rooms[i].type,rooms[i].status);
        }
    }
}

void generate_bill(){
    int i,j,room_no,days;
    printf("\nEnter the Room Number:");
    scanf("%d",&room_no);
    for(i=0;i<num_rooms;i++){
        if(customers[i].room_no==room_no){
            printf("\nEnter the Number of Days Staying:");
            scanf("%d",&days);
            bills[i].room_no=room_no;
            bills[i].days=days;
            if(strcmp(rooms[i].type,"deluxe")==0){
                bills[i].charges=1500*days;
            }
            else if(strcmp(rooms[i].type,"standard")==0){
                bills[i].charges=1000*days;
            }
            else{
                bills[i].charges=500*days;
            }
            printf("\nBill Generated Successfully!!!\n");
            strcpy(rooms[i].status,"unoccupied");
            customers[i].room_no=0;
            strcpy(customers[i].name,"");
            strcpy(customers[i].address,"");
            strcpy(customers[i].contact,"");
            break;
        }
    }
    if(i==num_rooms){
        printf("\nInvalid Room Number!!!\n");
    }
}

void print_bill(){
    int i,room_no;
    printf("\nEnter the Room Number:");
    scanf("%d",&room_no);
    for(i=0;i<num_rooms;i++){
        if(bills[i].room_no==room_no){
            printf("\nBill Details:\n");
            printf("Room Number\tNumber of Days\tCharges\n");
            printf("%d\t\t%d\t\t%d\n",bills[i].room_no,bills[i].days,bills[i].charges);
            break;
        }
    }
    if(i==num_rooms){
        printf("\nInvalid Room Number!!!\n");
    }
}

int main(){
    int i;
    for(i=0;i<num_rooms;i++){
        rooms[i].room_no=i+1;
        if(i<20){
            strcpy(rooms[i].type,"deluxe");
        }
        else if(i<35){
            strcpy(rooms[i].type,"standard");
        }
        else{
            strcpy(rooms[i].type,"economy");
        }
        strcpy(rooms[i].status,"unoccupied");
    }

    while(1){
        int choice;
        printf("\n----------HOTEL MANAGEMENT SYSTEM----------\n");
        printf("1. Book a Room\n2. View Customer List\n3. View Available Rooms\n4. Generate Bill\n5. Print Bill\n6. Exit\n");
        printf("\nEnter your Choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1: book_room();
                    break;
            case 2: view_customer_list();
                    break;
            case 3: view_available_rooms();
                    break;
            case 4: generate_bill();
                    break;
            case 5: print_bill();
                    break;
            case 6: exit(0);
            default:printf("\nInvalid Choice!!!\n");
        }
    }

    return 0;
}