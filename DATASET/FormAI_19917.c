//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hour;
    bool booked;
} Appointment;

void clear() {
    system("clear||cls"); // clears console
}

void printHeader() {
    clear();
    printf("=====================================\n");
    printf("           APPOINTMENT BOOK           \n");
    printf("=====================================\n\n");
}

void printAppointments(Appointment appointments[]) {
    printf("\n\nCurrent Appointments:\n\n");
    printf("| %-15s | %-15s |\n", "Name", "Time");
    printf("|-----------------|------------------|\n");

    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        printf("| %-15s | %-2d:00 %-9s |\n", appointments[i].booked ? appointments[i].name : "available", appointments[i].hour, appointments[i].hour < 12 ? "AM" : "PM");
    }

    printf("\n\n");
}

int bookAppointment(Appointment appointments[]) {
    printHeader();
    printAppointments(appointments);

    int hour;
    bool validHour;

    do {
        printf("Enter the desired appointment time (9-5): ");
        scanf("%d", &hour);
        validHour = (hour >= 9 && hour <= 17);

        if (!validHour) {
            printf("Invalid hour entered. Please try again.\n");
            getchar();
        }

    } while (!validHour);

    clear();
    printHeader();
    printAppointments(appointments);

    if (appointments[hour - 9].booked) {
        printf("Sorry, that appointment time is already booked.\n");
        printf("Press Enter to continue...\n");
        getchar();
        return -1;
    } else {
        strcpy(appointments[hour - 9].name, "");
        printf("Enter your name: ");
        scanf("%s", appointments[hour - 9].name);
        appointments[hour - 9].booked = true;
        printf("\nAppointment booked successfully!\n");
        printf("Press Enter to continue...\n");
        getchar();
        return 0;
    }
}

int cancelAppointment(Appointment appointments[]) {
    printHeader();
    printAppointments(appointments);

    int hour;
    bool validHour;

    do {
        printf("Enter the appointment time you wish to cancel (9-5): ");
        scanf("%d", &hour);
        validHour = (hour >= 9 && hour <= 17);

        if (!validHour) {
            printf("Invalid hour entered. Please try again.\n");
            getchar();
        }

    } while (!validHour);

    if (!appointments[hour - 9].booked) {
        printf("Sorry, that appointment is already available.\n");
        printf("Press Enter to continue...\n");
        getchar();
        return -1;
    } else {
        appointments[hour - 9].booked = false;
        strcpy(appointments[hour - 9].name, "");
        printf("\nAppointment cancelled successfully!\n");
        printf("Press Enter to continue...\n");
        getchar();
        return 0;
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];

    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        appointments[i].hour = i + 9;
        appointments[i].booked = false;
        strcpy(appointments[i].name, "");
    }

    int choice;

    do {
        printHeader();
        printf("1. Book an Appointment\n");
        printf("2. Cancel an Appointment\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                bookAppointment(appointments);
                break;

            case 2:
                cancelAppointment(appointments);
                break;

            case 3:
                printf("Goodbye!\n\n");
                exit(0);

            default:
                printf("Invalid choice entered. Please try again.\n");
                printf("Press Enter to continue...\n");
                getchar();
        }

    } while (true);

    return 0;
}