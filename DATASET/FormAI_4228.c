//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define constant variables
#define MAX_NAME_LENGTH 50
#define MAX_APPOINTMENTS 10

// Define structs
typedef struct {
    char name[MAX_NAME_LENGTH];
    int day;
    int time;
} Appointment;

typedef struct {
    Appointment appointments[MAX_APPOINTMENTS];
    int count;
} AppointmentList;

// Function declarations
bool isTimeAvailable(AppointmentList* appointmentList, int day, int time);
void printAppointmentList(AppointmentList* appointmentList);
void addAppointment(AppointmentList* appointmentList, char name[], int day, int time);

// Entry point
int main() {
    AppointmentList appointmentList = { {}, 0 };
    int option;

    do {
        printf("Select an option:\n");
        printf("1) View appointments\n");
        printf("2) Add an appointment\n");
        printf("3) Exit\n");

        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printAppointmentList(&appointmentList);
                break;
            case 2:
                char name[MAX_NAME_LENGTH];
                int day, time;

                // Prompt user for appointment details
                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter day (1-31): ");
                scanf("%d", &day);

                printf("Enter time (0-23): ");
                scanf("%d", &time);

                // Check if appointment time is available
                if (isTimeAvailable(&appointmentList, day, time)) {
                    addAppointment(&appointmentList, name, day, time);
                    printf("Appointment added successfully.\n");
                } else {
                    printf("Appointment time is not available.\n");
                }

                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != 3);

    return 0;
}

// Functions
bool isTimeAvailable(AppointmentList* appointmentList, int day, int time) {
    for (int i = 0; i < appointmentList->count; i++) {
        if (appointmentList->appointments[i].day == day &&
            appointmentList->appointments[i].time == time) {
            return false;
        }
    }

    return true;
}

void printAppointmentList(AppointmentList* appointmentList) {
    printf("Appointments:\n");

    for (int i = 0; i < appointmentList->count; i++) {
        printf("- %s at day %d, time %d\n",
            appointmentList->appointments[i].name,
            appointmentList->appointments[i].day,
            appointmentList->appointments[i].time);
    }
}

void addAppointment(AppointmentList* appointmentList, char name[], int day, int time) {
    Appointment appointment;
    strcpy(appointment.name, name);
    appointment.day = day;
    appointment.time = time;
    appointmentList->appointments[appointmentList->count] = appointment;
    appointmentList->count++;
}