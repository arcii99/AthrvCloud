//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPTS 10

struct Appointment {
    char date[20];
    char time[10];
    char description[100];
};

struct Appointment appts[MAX_APPTS];
int numAppts = 0;

int main() {
    int choice;

    do {
        printf("\nAppointment Scheduler\n");
        printf("---------------------\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}

void addAppointment() {
    char date[20], time[10], description[100];

    if (numAppts == MAX_APPTS) {
        printf("Maximum number of appointments reached.\n");
        return;
    }

    printf("\nEnter appointment details:\n");
    printf("Date: ");
    scanf("%s", date);

    printf("Time: ");
    scanf("%s", time);

    printf("Description: ");
    scanf(" %[^\n]s", description);

    strcpy(appts[numAppts].date, date);
    strcpy(appts[numAppts].time, time);
    strcpy(appts[numAppts].description, description);

    printf("Appointment added!\n");

    numAppts++;
}

void viewAppointments() {
    if (numAppts == 0) {
        printf("No appointments found.\n");
        return;
    }

    printf("\nUpcoming Appointments:\n");
    printf("-----------------------\n");
    printf("Date       | Time  | Description\n");

    for (int i = 0; i < numAppts; i++) {
        printf("%-10s | %-5s | %-20s\n", appts[i].date, appts[i].time, appts[i].description);
    }
}