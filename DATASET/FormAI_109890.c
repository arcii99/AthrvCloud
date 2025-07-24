//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char name[30];
    char date[15];
    char time[15];
};

int main() {
    struct appointment schedule[10];
    int count = 0;

    printf("Welcome to our romantic appointment scheduler!\n\n");

    while(1) {
        printf("Enter 1 to schedule a new appointment or 2 to quit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter your partner's name: ");
            scanf("%s", schedule[count].name);
            printf("\nEnter the date of the appointment (dd/mm/yyyy): ");
            scanf("%s", schedule[count].date);
            printf("\nEnter the time of the appointment (hh:mm am/pm): ");
            scanf("%s", schedule[count].time);

            printf("\nAppointment scheduled successfully!\n\n");
            count++;
        } else if (choice == 2) {
            break;
        } else {
            printf("\nInvalid choice. Please enter 1 or 2.\n\n");
        }
    }

    printf("\nYour romantic appointments schedule:\n\n");

    for (int i = 0; i < count; i++) {
        printf("Name: %s\nDate: %s\nTime: %s\n\n", schedule[i].name, schedule[i].date, schedule[i].time);
    }

    printf("\nThank you for using our romantic appointment scheduler!");
    return 0;
}