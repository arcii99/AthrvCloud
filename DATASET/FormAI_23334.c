//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
// Welcome to our appointment scheduler program!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_APPTS 10

// Struct to hold appointment data
struct appoinment {
    int day;
    int month;
    int year;
    char *location;
};

// Print all appointments on the calendar
void printAppointments(struct appoinment appointments[NUM_APPTS]) {
    printf("Upcoming Appointments:\n");
    for (int i = 0; i < NUM_APPTS; i++) {
        printf("%d/%d/%d: %s\n", appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].location);
    }
}

// Add an appointment to a specified date
void addAppointment(struct appoinment *appointments, int day, int month, int year, char *location) {
    for (int i = 0; i < NUM_APPTS; i++) {
        if (appointments[i].day == 0) {
            appointments[i].day = day;
            appointments[i].month = month;
            appointments[i].year = year;
            appointments[i].location = location;
            break;
        }
    }
    printf("Appointment added on %d/%d/%d at %s\n", day, month, year, location);
}

// Remove an appointment from a specified date
void removeAppointment(struct appoinment *appointments, int day, int month, int year) {
    for (int i = 0; i < NUM_APPTS; i++) {
        if (appointments[i].day == day && appointments[i].month == month && appointments[i].year == year) {
            appointments[i].day = 0;
            appointments[i].month = 0;
            appointments[i].year = 0;
            appointments[i].location = "";
            printf("Appointment removed on %d/%d/%d\n", day, month, year);
            break;
        } else if (i == NUM_APPTS - 1) {
            printf("No appointment found on %d/%d/%d\n", day, month, year);
        }
    }
}

int main() {
    // Initialize appointments with empty dates and locations
    struct appoinment appointments[NUM_APPTS];
    for (int i = 0; i < NUM_APPTS; i++) {
        appointments[i].day = 0;
        appointments[i].month = 0;
        appointments[i].year = 0;
        appointments[i].location = "";
    }

    // Generate some random test appointments
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        int day = rand() % 30 + 1;
        int month = rand() % 12 + 1;
        int year = rand() % 5 + 2022;
        char *locations[] = {"office", "home", "online"};
        int locIndex = rand() % 3;
        addAppointment(appointments, day, month, year, locations[locIndex]);
    }
    printAppointments(appointments);

    // Add some appointments manually
    addAppointment(appointments, 10, 3, 2022, "doctor's office");
    addAppointment(appointments, 20, 4, 2022, "coffee shop");
    printAppointments(appointments);

    // Remove an appointment
    removeAppointment(appointments, 10, 3, 2022);
    printAppointments(appointments);

    return 0;
}