//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct {
    char date[20];
    char time[20];
    char name[50];
    char contact[30];
} Appointment;

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;
    char input[2];

    while (1) {
        printf("Appointment Scheduler\n");
        printf("[1] Add an appointment\n");
        printf("[2] View all appointments\n");
        printf("[3] Exit\n");
        printf("Enter your choice: ");

        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "1\n") == 0) {
            if (numAppointments >= MAX_APPOINTMENTS) {
                printf("Maximum number of appointments reached.\n");
            } else {
                Appointment newAppointment;

                printf("Enter date of appointment (MM/DD/YYYY): ");
                fgets(newAppointment.date, sizeof(newAppointment.date), stdin);
                printf("Enter time of appointment (HH:MM AM/PM): ");
                fgets(newAppointment.time, sizeof(newAppointment.time), stdin);
                printf("Enter name of person to meet: ");
                fgets(newAppointment.name, sizeof(newAppointment.name), stdin);
                printf("Enter contact details: ");
                fgets(newAppointment.contact, sizeof(newAppointment.contact), stdin);

                appointments[numAppointments++] = newAppointment;
                printf("Appointment added successfully!\n");
            }
        } else if (strcmp(input, "2\n") == 0) {
            if (numAppointments == 0) {
                printf("No appointments to show.\n");
            } else {
                printf("All appointments:\n");

                for (int i = 0; i < numAppointments; i++) {
                    printf("%d. %s %s %s %s\n", i + 1, appointments[i].date, appointments[i].time, appointments[i].name, appointments[i].contact);
                }
            }
        } else if (strcmp(input, "3\n") == 0) {
            printf("Exiting program.\n");
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}