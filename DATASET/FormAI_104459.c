//FormAI DATASET v1.0 Category: Hotel Management System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
struct room{
    int room_no;
    char room_type[20];
    double room_price;
    int availability;
};
struct customer{
    char name[20];
    int age;
    int room_no;
    int days;
    double bill;
};
struct room rooms[MAX];
struct customer customers[MAX];
int count=0;
void initialize(){
//function to initialize all the rooms
    int i;
    for(i=0;i<MAX;i++){
        rooms[i].room_no=i+1;
        rooms[i].availability=1;
        if(i<3){
            strcpy(rooms[i].room_type,"Single");
            rooms[i].room_price=500.0;
        }
        else if(i>=3 && i<7){
            strcpy(rooms[i].room_type,"Double");
            rooms[i].room_price=750.0;
        }
        else{
            strcpy(rooms[i].room_type,"Suite");
            rooms[i].room_price=1000.0;
        }
    }
     printf("\nAll the rooms have been initialized!\n");
}
void view_all_rooms(){
//function to display all the rooms
    int i;
    printf("\nRoom No.\tRoom Type\tPrice per day\tAvailability\n");
    for(i=0;i<MAX;i++){
        printf("%d\t\t%s\t\t%.2f\t\t",rooms[i].room_no,rooms[i].room_type,rooms[i].room_price);
        if(rooms[i].availability==0){
            printf("Occupied\n");
        }
        else{
            printf("Available\n");
        }
    }
}
void find_room(){
//function to find a room
    int i,room_num;
    printf("\nEnter the room number: ");
    scanf("%d",&room_num);
    for(i=0;i<MAX;i++){
        if(rooms[i].room_no==room_num){
            printf("\nRoom No.: %d\nRoom Type: %s\nPrice per day: %.2f\nAvailability: ",rooms[i].room_no,rooms[i].room_type,rooms[i].room_price);
            if(rooms[i].availability==0){
                printf("Occupied\n");
            }
            else{
                printf("Available\n");
            }
            break;
        }
    }
    if(i==MAX){
        printf("\nRoom not found!\n");
    }
}
void book_room(){
//function to book a room
    int i,flag=0,room_num;
    double total_bill;
    printf("\nEnter the room number: ");
    scanf("%d",&room_num);
    for(i=0;i<MAX;i++){
        if(rooms[i].room_no==room_num){
            if(rooms[i].availability==1){
                printf("\nEnter the customer name: ");
                scanf("%s",customers[count].name);
                printf("Enter the customer age: ");
                scanf("%d",&customers[count].age);
                customers[count].room_no=room_num;
                printf("Enter the number of days for which the room is required: ");
                scanf("%d",&customers[count].days);
                rooms[i].availability=0;
                total_bill=customers[count].days*rooms[i].room_price;
                customers[count].bill=total_bill;
                printf("\nRoom has been booked successfully!\n");
                printf("Total Bill: %.2f\n",customers[count].bill);
                count++;
            }
            else{
                printf("\nRoom is already occupied!\n");
            }
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("\nRoom not found!\n");
    }
}
void view_all_customers(){
//function to display all the customers
    int i;
    printf("\nName\t\tAge\tRoom No.\tDays\tTotal Bill\n");
    for(i=0;i<count;i++){
        printf("%s\t\t%d\t%d\t\t%d\t%.2f\n",customers[i].name,customers[i].age,customers[i].room_no,customers[i].days,customers[i].bill);
    }
}
void checkout(){
//function to checkout a customer
    int i,flag=0,room_num;
    double total_bill;
    printf("\nEnter the room number to checkout: ");
    scanf("%d",&room_num);
    for(i=0;i<count;i++){
        if(customers[i].room_no==room_num){
            printf("\nCustomer Name: %s\nAge: %d\nRoom No.: %d\nDays: %d\nTotal Bill: %.2f\n",customers[i].name,customers[i].age,customers[i].room_no,customers[i].days,customers[i].bill);
            rooms[room_num-1].availability=1;
            for(int j=i;j<count-1;j++){
                customers[i]=customers[i+1];
            }
            count--;
            printf("\nCustomer has checked out successfully!\n");
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("\nRoom not found!\n");
    }
}
int main(){
    initialize();
    int choice;
    while(1){
        printf("\n1. View All Rooms\n2. Find a Room\n3. Book a Room\n4. View All Customers\n5. Checkout\n6. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: view_all_rooms();
                    break;
            case 2: find_room();
                    break;
            case 3: book_room();
                    break;
            case 4: view_all_customers();
                    break;
            case 5: checkout();
                    break;
            case 6: exit(0);
            default: printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}