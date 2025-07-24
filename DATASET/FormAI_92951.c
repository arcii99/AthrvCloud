//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

// constants
#define MAX_NAME_LENGTH 50
#define MAX_APPOINTMENTS 20

// structs
typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int minute;
} datetime;

typedef struct {
    char name[MAX_NAME_LENGTH];
    datetime date;
} appointment;

// function declarations
void print_menu();
void add_appointment(appointment appointments[], int *num_appointments);
void remove_appointment(appointment appointments[], int *num_appointments);
void view_appointments(appointment appointments[], int num_appointments);

int main() {
    // variables
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    char choice;

    // main loop
    do {
        print_menu();
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                add_appointment(appointments, &num_appointments);
                break;
            case 'r':
                remove_appointment(appointments, &num_appointments);
                break;
            case 'v':
                view_appointments(appointments, num_appointments);
                break;
            case 'x':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 'x');

    return 0;
}

// prints the menu
void print_menu() {
    printf("\nAppointment Scheduler\n");
    printf("==============================================\n");
    printf("a - Add an appointment\n");
    printf("r - Remove an appointment\n");
    printf("v - View appointments\n");
    printf("x - Exit\n");
    printf("==============================================\n");
    printf("Enter your choice: ");
}

// adds an appointment to the schedule
void add_appointment(appointment appointments[], int *num_appointments) {
    // check if the schedule is full
    if (*num_appointments == MAX_APPOINTMENTS) {
        printf("The schedule is full. Cannot add another appointment.\n");
        return;
    }

    // get appointment details from the user
    printf("Enter appointment name: ");
    scanf(" %49[^\n]", appointments[*num_appointments].name);
    printf("Enter appointment date and time (mm/dd/yyyy hh:mm): ");
    scanf(" %d/%d/%d %d:%d", &appointments[*num_appointments].date.month,
                             &appointments[*num_appointments].date.day,
                             &appointments[*num_appointments].date.year,
                             &appointments[*num_appointments].date.hour,
                             &appointments[*num_appointments].date.minute);

    // increment number of appointments
    *num_appointments += 1;

    printf("Appointment added successfully.\n");
}

// removes an appointment from the schedule
void remove_appointment(appointment appointments[], int *num_appointments) {
    // check if the schedule is empty
    if (*num_appointments == 0) {
        printf("The schedule is empty. Cannot remove an appointment.\n");
        return;
    }

    // get appointment name to remove from the user
    printf("Enter name of appointment to remove: ");
    char name[MAX_NAME_LENGTH];
    scanf(" %49[^\n]", name);

    int i, found = 0;
    for (i = 0; i < *num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (; i < *num_appointments - 1; i++) {
            appointments[i] = appointments[i+1];
        }
        *num_appointments -= 1;
        printf("Appointment removed successfully.\n");
    } else {
        printf("Appointment not found.\n");
    }
}

// views the appointments in the schedule
void view_appointments(appointment appointments[], int num_appointments) {
    if (num_appointments == 0) {
        printf("The schedule is empty.\n");
    } else {
        printf("\nAppointments\n");
        printf("==============================================\n");
        int i;
        for (i = 0; i < num_appointments; i++) {
            printf("%d/%d/%d %d:%d - %s\n", appointments[i].date.month,
                                           appointments[i].date.day,
                                           appointments[i].date.year,
                                           appointments[i].date.hour,
                                           appointments[i].date.minute,
                                           appointments[i].name);
        }
        printf("==============================================\n");
    }
}