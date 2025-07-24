//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments available
#define MAX_APPOINTMENTS 10

// Define the maximum length of each name
#define MAX_NAME_LENGTH 20

// Define the maximum length of each time slot
#define MAX_TIME_LENGTH 10

// Define the structure for each appointment
typedef struct {
    char name[MAX_NAME_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

// Define the global variable for all appointments
Appointment appointments[MAX_APPOINTMENTS];

// Define the function for adding a new appointment
void addAppointment() {
    // Check if available slots are fully filled
    int i;
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].name[0] == '\0') {
            break;
        }
    }
    if (i == MAX_APPOINTMENTS) {
        printf("Sorry, the maximum number of appointments have been reached.\n\n");
        return;
    }

    // Get the user's inputs for the new appointment
    char name[MAX_NAME_LENGTH];
    char time[MAX_TIME_LENGTH];

    printf("Please enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove the newline character from the string

    printf("Please enter your preferred time slot (e.g., 10:00): ");
    fgets(time, MAX_TIME_LENGTH, stdin);
    time[strcspn(time, "\n")] = '\0'; // Remove the newline character from the string

    // Check if the time slot is already taken

    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (strcmp(appointments[i].time, time) == 0) {
            printf("Sorry, that time slot is already taken.\n\n");
            return;
        }
    }

    // Copy the inputs into the new appointment
    strcpy(appointments[i].name, name);
    strcpy(appointments[i].time, time);

    printf("Your appointment has been added.\n\n");
}

// Define the function for removing an appointment
void removeAppointment() {
    // Get the user's input for the appointment to be removed
    char time[MAX_TIME_LENGTH];
    printf("Please enter the time of the appointment to be removed: ");
    fgets(time, MAX_TIME_LENGTH, stdin);
    time[strcspn(time, "\n")] = '\0'; // Remove the newline character from the string

    // Search for the appointment with the specified time
    int i;
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (strcmp(appointments[i].time, time) == 0) {
            break;
        }
    }

    // If the appointment is not found, print an error message and return
    if (i == MAX_APPOINTMENTS) {
        printf("Sorry, no appointment found with that time.\n\n");
        return;
    }

    // Remove the appointment by setting its name and time to empty strings
    appointments[i].name[0] = '\0';
    appointments[i].time[0] = '\0';

    printf("The appointment has been removed.\n\n");
}

// Define the function for displaying all appointments
void displayAppointments() {
    // Print the header row
    printf("Name\tTime\n");

    // Print each appointment in a new row
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].name[0] != '\0') {
            printf("%s\t%s\n", appointments[i].name, appointments[i].time);
        }
    }

    printf("\n");
}

int main() {
    // Set all appointment names and times to empty strings
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        appointments[i].name[0] = '\0';
        appointments[i].time[0] = '\0';
    }

    // Keep looping until the user chooses to exit
    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add an appointment\n");
        printf("2. Remove an appointment\n");
        printf("3. Display all appointments\n");
        printf("4. Exit\n");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);
        getchar(); // Remove the newline character from the scanf buffer

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                removeAppointment();
                break;
            case 3:
                displayAppointments();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n\n");
        }
    }
    return 0;
}