//FormAI DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

struct customer
{
    int room_number;
    char name[50];
    long int phone_number;
    int age;
};

struct room
{
    int room_number;
    int availability;
};

int main()
{
    int choice, flag;
    struct customer c[50];
    struct room r[50];

    for(int i=0; i<50; i++)
    {
        r[i].room_number = i+1; //Assigning room numbers
        r[i].availability = 1; //Initially all rooms are available
    }

    do
    {
        flag = 0;
        printf("\n\n--------------------C Hotel Management System--------------------\n");
        printf("1. Book a room\n2. Unbook a room\n3. View customer details\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: //Book a room
                {
                    int available_rooms[50], count=0, room_choice, customer_count=0;
                    printf("\nAvailable rooms: \n");
                    for(int i=0; i<50; i++)
                    {
                        if(r[i].availability == 1)
                        {
                            printf("%d\n", r[i].room_number);
                            available_rooms[count] = r[i].room_number;
                            count++;
                        }
                    }
                    if(count == 0)
                    {
                        printf("\nSorry, all rooms are booked!\n");
                        break;
                    }
                    printf("\nEnter the room number you want to book: ");
                    scanf("%d", &room_choice);
                    for(int i=0; i<50; i++)
                    {
                        if(c[i].room_number == room_choice)
                        {
                            printf("\nRoom is already booked!\n");
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 1)
                    {
                        break;
                    }
                    for(int i=0; i<50; i++)
                    {
                        if(r[i].room_number == room_choice)
                        {
                            r[i].availability = 0; //Room is now booked
                            c[customer_count].room_number = r[i].room_number;
                            printf("\nEnter customer name: ");
                            scanf("%s", c[customer_count].name);
                            printf("Enter phone number: ");
                            scanf("%ld", &c[customer_count].phone_number);
                            printf("Enter age: ");
                            scanf("%d", &c[customer_count].age);
                            printf("Room booked successfully!\n");
                            printf("\nCustomer details-\n");
                            printf("Name: %s\nPhone number: %ld\nAge: %d\nRoom number: %d\n", c[customer_count].name, c[customer_count].phone_number, c[customer_count].age, c[customer_count].room_number);
                            customer_count++;
                            break;
                        }
                    }
                    break;
                }

            case 2: //Unbook a room
                {
                    int room_choice, customer_count=0;
                    printf("\nEnter the room number you want to unbook: ");
                    scanf("%d", &room_choice);
                    for(int i=0; i<50; i++)
                    {
                        if(c[i].room_number == room_choice)
                        {
                            c[i].room_number = -1;
                            r[i].availability = 1;
                            printf("\nRoom unbooked successfully!\n");
                            printf("\nCustomer details-\n");
                            printf("Name: %s\nPhone number: %ld\nAge: %d\nRoom number: %d\n", c[i].name, c[i].phone_number, c[i].age, c[i].room_number);
                            customer_count++;
                            break;
                        }
                    }
                    if(customer_count == 0)
                    {
                        printf("\nSorry, no customers available in that room!\n");
                    }
                    break;
                }

            case 3: //View customer details
                {
                    int room_choice, customer_count=0;
                    printf("\nEnter the room number: ");
                    scanf("%d", &room_choice);
                    for(int i=0; i<50; i++)
                    {
                        if(c[i].room_number == room_choice)
                        {
                            printf("\nCustomer details-\n");
                            printf("Name: %s\nPhone number: %ld\nAge: %d\nRoom number: %d\n", c[i].name, c[i].phone_number, c[i].age, c[i].room_number);
                            customer_count++;
                            break;
                        }
                    }
                    if(customer_count == 0)
                    {
                        printf("\nSorry, no customers available in that room!\n");
                    }
                    break;
                }

            case 4: //Exit
                {
                    exit(0);
                }

            default:
                {
                    printf("\nInvalid choice!\n");
                }
        }
    }while(choice!=4);

    return 0;
}