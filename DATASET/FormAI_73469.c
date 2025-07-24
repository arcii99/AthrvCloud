//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100

struct appointment {
    char name[20];
    char date[20];
    char time[20];
};

typedef struct appointment appointment_t;

// functions to be used
bool is_available(int size, appointment_t arr[size], char date[], char time[]);
void print_appointments(int size, appointment_t arr[size]);
void add_appointment(int size, appointment_t arr[size], char name[], char date[], char time[]);
void remove_appointment(int size, appointment_t arr[size], char name[], char date[], char time[]);

int main() {
    // create an array of appointments
    appointment_t appointments[MAX_SIZE];
    int size = 0;
    int choice = 0;

    // initialize the array
    for (int i = 0; i < MAX_SIZE; i++) {
        strcpy(appointments[i].name, "");
        strcpy(appointments[i].date, "");
        strcpy(appointments[i].time, "");
    }

    // welcome message
    printf("Welcome to the Appointment Scheduler!\n\n");

    while (choice != 4) {
        // print menu
        printf("Please choose an option:\n");
        printf("1. View all appointments\n");
        printf("2. Add an appointment\n");
        printf("3. Remove an appointment\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_appointments(size, appointments);
                break;
            case 2:
                // get user input for new appointment
                char name[20];
                char date[20];
                char time[20];

                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter date (mm/dd/yyyy): ");
                scanf("%s", date);
                printf("Enter time (hh:mm): ");
                scanf("%s", time);

                // check if the appointment is available
                if (is_available(size, appointments, date, time)) {
                    add_appointment(size, appointments, name, date, time);
                    size++;
                    printf("Appointment added successfully!\n");
                } else {
                    printf("There is already an appointment scheduled at that time.\n");
                }
                break;
            case 3:
                // get user input for appointment to remove
                char nameToRemove[20];
                char dateToRemove[20];
                char timeToRemove[20];

                printf("Enter name: ");
                scanf("%s", nameToRemove);
                printf("Enter date (mm/dd/yyyy): ");
                scanf("%s", dateToRemove);
                printf("Enter time (hh:mm): ");
                scanf("%s", timeToRemove);

                remove_appointment(size, appointments, nameToRemove, dateToRemove, timeToRemove);
                size--;
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}

// function to check if an appointment is available at the given time
bool is_available(int size, appointment_t arr[size], char date[], char time[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].date, date) == 0 && strcmp(arr[i].time, time) == 0) {
            return false;
        }
    }
    return true;
}

// function to print all appointments
void print_appointments(int size, appointment_t arr[size]) {
    if (size == 0) {
        printf("There are no appointments scheduled.\n");
    } else {
        printf("Appointments: \n");
        for (int i = 0; i < size; i++) {
            printf("%s, %s, %s\n", arr[i].name, arr[i].date, arr[i].time);
        }
    }
}

// function to add an appointment to the array
void add_appointment(int size, appointment_t arr[size], char name[], char date[], char time[]) {
    strcpy(arr[size].name, name);
    strcpy(arr[size].date, date);
    strcpy(arr[size].time, time);
}

// function to remove an appointment from the array
void remove_appointment(int size, appointment_t arr[size], char name[], char date[], char time[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0 && strcmp(arr[i].date, date) == 0 && strcmp(arr[i].time, time) == 0) {
            // shift all elements to the left
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j+1];
            }
            // clear last element
            strcpy(arr[size-1].name, "");
            strcpy(arr[size-1].date, "");
            strcpy(arr[size-1].time, "");
            printf("Appointment removed successfully!\n");
            return;
        }
    }
    printf("Appointment not found.\n");
}