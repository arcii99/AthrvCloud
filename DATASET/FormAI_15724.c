//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 20

struct Appointment {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

struct Appointment appointments[MAX_APPOINTMENTS];

int numAppointments = 0;

bool taken(int day, int month, int year, int hour, int minute) {
    for (int i = 0; i < numAppointments; i++) {
        if (appointments[i].day == day &&
            appointments[i].month == month &&
            appointments[i].year == year &&
            appointments[i].hour == hour &&
            appointments[i].minute == minute) {
            return true;
        }
    }
    return false;
}

void addAppointment() {
    char name[MAX_NAME_LENGTH];
    int day, month, year, hour, minute;

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the day, month, and year of your appointment (mm dd yyyy): ");
    scanf("%d %d %d", &month, &day, &year);
    printf("Enter the hour and minute of your appointment (hh:mm): ");
    scanf("%d:%d", &hour, &minute);

    if (taken(day, month, year, hour, minute)) {
        printf("This appointment time is already taken. Please choose another time.\n");
    } else if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Sorry, our schedule is full for today.\n");
    } else {
        struct Appointment appointment = {
            .day = day,
            .month = month,
            .year = year,
            .hour = hour,
            .minute = minute,
        };
        for (int i = 0; i < MAX_NAME_LENGTH; i++) {
            appointment.name[i] = name[i];
        }
        appointments[numAppointments] = appointment;
        numAppointments++;
        printf("Your appointment has been scheduled for %02d/%02d/%04d at %02d:%02d\n", month, day, year, hour, minute);
    }
}

void printSchedule() {
    printf("Schedule for today:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%02d/%02d/%04d - %02d:%02d - %s\n", appointments[i].month,
                                                    appointments[i].day,
                                                    appointments[i].year,
                                                    appointments[i].hour,
                                                    appointments[i].minute,
                                                    appointments[i].name);
    }
}

int main() {
    printf("Welcome to our appointment scheduler!\n");
    while (true) {
        int choice;
        printf("\nWhat would you like to do?\n");
        printf("1. Schedule an appointment\n");
        printf("2. Print today's schedule\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                printSchedule();
                break;
            case 3:
                printf("Thank you for using our appointment scheduler!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }
}