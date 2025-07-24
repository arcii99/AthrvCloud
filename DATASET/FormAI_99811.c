//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// struct to represent appointments
typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    char description[100];
} Appointment;

// function to compare two Appointment structs for sorting
int compareAppts(const void* appt1Ptr, const void* appt2Ptr) {
    Appointment* appt1 = (Appointment*)appt1Ptr;
    Appointment* appt2 = (Appointment*)appt2Ptr;
    if (appt1->year != appt2->year) {
        return appt1->year - appt2->year;
    }
    if (appt1->month != appt2->month) {
        return appt1->month - appt2->month;
    }
    if (appt1->day != appt2->day) {
        return appt1->day - appt2->day;
    }
    if (appt1->hour != appt2->hour) {
        return appt1->hour - appt2->hour;
    }
    if (appt1->minute != appt2->minute) {
        return appt1->minute - appt2->minute;
    }
    return 0;
}

// function to print out an appointment
void printAppt(Appointment* appt) {
    printf("%02d/%02d/%d %02d:%02d - %s\n", appt->day, appt->month,
            appt->year, appt->hour, appt->minute, appt->description);
}

int main() {
    printf("Welcome to the Appointment Scheduler!\n\n");

    // initialize array of appointments with empty appointments
    Appointment appts[10];
    for (int i = 0; i < 10; i++) {
        appts[i].day = 0;
    }

    // main loop
    bool running = true;
    while (running) {
        printf("What would you like to do?\n");
        printf("1. Schedule a new appointment\n");
        printf("2. View today's appointments\n");
        printf("3. View all appointments\n");
        printf("4. Quit\n");

        int choice;
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nScheduling a new appointment\n");
                printf("Enter the date and time (dd/mm/yyyy hh:mm): ");
                int day, month, year, hour, minute;
                scanf("%d/%d/%d %d:%d", &day, &month, &year, &hour, &minute);
                getchar(); // consume newline character
                printf("Enter a description: ");
                fgets(appts[0].description, 100, stdin);
                Appointment newAppt = {day, month, year, hour, minute};
                for (int i = 0; i < 10; i++) {
                    if (appts[i].day == 0) { // found empty slot
                        appts[i] = newAppt;
                        printf("\nAppointment scheduled for ");
                        printAppt(&appts[i]);
                        break;
                    }
                }
                printf("\n");
                break;

            case 2:
                printf("\nToday's appointments\n");
                for (int i = 0; i < 10; i++) {
                    if (appts[i].day != 0 && appts[i].day == 1 &&
                            appts[i].month == 6 && appts[i].year == 2022) {
                        printAppt(&appts[i]);
                    }
                }
                printf("\n");
                break;

            case 3:
                printf("\nAll appointments\n");
                qsort(appts, 10, sizeof(Appointment), compareAppts);
                for (int i = 0; i < 10; i++) {
                    if (appts[i].day != 0) {
                        printAppt(&appts[i]);
                    }
                }
                printf("\n");
                break;

            case 4:
                printf("\nGoodbye!\n");
                running = false;
                break;

            default:
                printf("\nInvalid choice, please try again\n");
                break;
        }
    }

    return 0;
}