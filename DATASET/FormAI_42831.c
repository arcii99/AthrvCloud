//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int day;
    int time;
} Appointment;

void printMenu() {
    printf("1. Schedule an Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel an Appointment\n");
    printf("4. Exit\n");
}

bool isSlotAvailable(Appointment appointments[], int day, int time) {
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].day == day && appointments[i].time == time) {
            return false;
        }
    }
    return true;
}

void scheduleAppointment(Appointment appointments[]) {
    char name[MAX_NAME_LENGTH];
    int day, time;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the day of the appointment (1-31): ");
    scanf("%d", &day);

    printf("Enter the time of the appointment (9-17): ");
    scanf("%d", &time);

    if (isSlotAvailable(appointments, day, time)) {
        for (int i = 0; i < MAX_APPOINTMENTS; i++) {
            if (strlen(appointments[i].name) == 0) {
                strcpy(appointments[i].name, name);
                appointments[i].day = day;
                appointments[i].time = time;
                printf("Appointment scheduled successfully!\n");
                return;
            }
        }
        printf("Sorry, no empty slots available for this day and time.\n");
    } else {
        printf("Sorry, this slot is already taken.\n");
    }
}

void viewAppointments(Appointment appointments[]) {
    printf("Appointments:\n");
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (strlen(appointments[i].name) > 0) {
            printf("%s - Day %d, Time %d\n", appointments[i].name, appointments[i].day, appointments[i].time);
        }
    }
}

void cancelAppointment(Appointment appointments[]) {
    int day, time;

    printf("Enter the day of the appointment to cancel (1-31): ");
    scanf("%d", &day);

    printf("Enter the time of the appointment to cancel (9-17): ");
    scanf("%d", &time);

    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].day == day && appointments[i].time == time) {
            strcpy(appointments[i].name, "");
            appointments[i].day = 0;
            appointments[i].time = 0;
            printf("Appointment cancelled successfully!\n");
            return;
        }
    }
    printf("Sorry, no appointment found for this day and time.\n");
}

int main() {
    int option;
    Appointment appointments[MAX_APPOINTMENTS];

    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        strcpy(appointments[i].name, "");
        appointments[i].day = 0;
        appointments[i].time = 0;
    }

    do {
        printMenu();
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                scheduleAppointment(appointments);
                break;
            case 2:
                viewAppointments(appointments);
                break;
            case 3:
                cancelAppointment(appointments);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 4);

    return 0;
}