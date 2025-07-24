//FormAI DATASET v1.0 Category: Hotel Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest
{
    char name[50];
    int room_number;
    int nights;
    float amount_paid;
};
struct room
{
    int room_number;
    char availability[10];
};

void display_menu()
{
    printf("Welcome to C Hotel Management System\n");
    printf("1. Check-in\n");
    printf("2. Check-out\n");
    printf("3. Print guest list\n");
    printf("4. Print room status\n");
    printf("5. Exit\n");
}

int main()
{
    struct guest guest_list[100];
    struct room room_list[50];
    int choice, i = 0, j = 0, k = 0, flag = 0;

    for (i = 0; i < 50; i++)
    {
        room_list[i].room_number = i + 1;
        strcpy(room_list[i].availability, "available");
    }

    while (1)
    {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Check-in\n");
            printf("Enter guest name: ");
            scanf("%s", guest_list[j].name);
            printf("Enter room number: ");
            scanf("%d", &guest_list[j].room_number);
            if (strcmp(room_list[guest_list[j].room_number - 1].availability, "available") == 0)
            {
                strcpy(room_list[guest_list[j].room_number - 1].availability, "occupied");
                printf("Enter number of nights: ");
                scanf("%d", &guest_list[j].nights);
                printf("Enter amount paid: ");
                scanf("%f", &guest_list[j].amount_paid);
                printf("Check-in successful\n");
                j++;
            }
            else
            {
                printf("Room not available\n");
            }
            break;

        case 2:
            printf("Check-out\n");
            printf("Enter guest name: ");
            scanf("%s", guest_list[k].name);
            for (i = 0; i < j; i++)
            {
                if (strcmp(guest_list[k].name, guest_list[i].name) == 0)
                {
                    flag = 1;
                    printf("Amount to be paid: %.2f\n", guest_list[i].nights * 1000 - guest_list[i].amount_paid);
                    strcpy(room_list[guest_list[i].room_number - 1].availability, "available");
                    for (int l = i; l < j - 1; l++)
                    {
                        guest_list[l] = guest_list[l + 1];
                    }
                    j--;
                    printf("Check-out successful\n");
                }
            }
            if (flag == 0)
            {
                printf("Guest not found\n");
            }
            break;

        case 3:
            printf("Guest List\n");
            printf("Name\t\tRoom Number\tNights\tAmount Paid\n");
            for (i = 0; i < j; i++)
            {
                printf("%s\t\t%d\t\t%d\t%.2f\n", guest_list[i].name, guest_list[i].room_number, guest_list[i].nights, guest_list[i].amount_paid);
            }
            break;

        case 4:
            printf("Room List\n");
            printf("Room Number\tAvailability\n");
            for (i = 0; i < 50; i++)
            {
                printf("%d\t\t%s\n", room_list[i].room_number, room_list[i].availability);
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}