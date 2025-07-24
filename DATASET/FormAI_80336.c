//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct appointment {
    char name[50];
    char location[50];
    char date[20];
    char time[20];
};

void add_appointment(struct appointment [], int *);
void search_appointment(struct appointment [], int *);
void delete_appointment(struct appointment [], int *);

int main() {
    printf("Welcome to the Appointment Scheduler program.\n");
    struct appointment appointments[20];
    int num_appointments = 0;
    char option;
    do {
        printf("\nSelect an option:\n");
        printf("1. Add Appointment\n");
        printf("2. Search Appointment\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Option: ");
        option = getchar();
        fflush(stdin);
        switch(option) {
            case '1':
                add_appointment(appointments, &num_appointments);
                break;
            case '2':
                search_appointment(appointments, &num_appointments);
                break;
            case '3':
                delete_appointment(appointments, &num_appointments);
                break;
            case '4':
                printf("Exiting program...");
                break;
            default:
                printf("Invalid option. Please try again.");
        }
    } while (option != '4');
    return 0;
}

void add_appointment(struct appointment appointments[], int *num_appointments) {
    printf("\nAdding Appointment...\n");
    if (*num_appointments >= 20) {
        printf("Sorry, the maximum number of appointments (20) has been reached.\n");
        return;
    }
    struct appointment new_appointment;
    printf("Enter name: ");
    fgets(new_appointment.name, sizeof(new_appointment.name), stdin);
    new_appointment.name[strcspn(new_appointment.name, "\n")] = 0; // Remove the newline character
    printf("Enter location: ");
    fgets(new_appointment.location, sizeof(new_appointment.location), stdin);
    new_appointment.location[strcspn(new_appointment.location, "\n")] = 0;
    printf("Enter date (e.g. 01-01-2022): ");
    fgets(new_appointment.date, sizeof(new_appointment.date), stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = 0;
    printf("Enter time (e.g. 11:00 AM): ");
    fgets(new_appointment.time, sizeof(new_appointment.time), stdin);
    new_appointment.time[strcspn(new_appointment.time, "\n")] = 0;
    appointments[*num_appointments] = new_appointment;
    printf("\nAppointment added successfully.\n");
    *num_appointments += 1;
}

void search_appointment(struct appointment appointments[], int *num_appointments) {
    printf("\nSearching for Appointment...\n");
    if (*num_appointments == 0) {
        printf("Sorry, there are no appointments to search for.\n");
        return;
    }
    char search_name[50];
    printf("Enter name: ");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < *num_appointments; i++) {
        if (strcmp(appointments[i].name, search_name) == 0) {
            printf("\nAppointment found:\n");
            printf("Name: %s\n", appointments[i].name);
            printf("Location: %s\n", appointments[i].location);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nSorry, appointment not found.\n");
    }
}

void delete_appointment(struct appointment appointments[], int *num_appointments) {
    printf("\nDeleting Appointment...\n");
    if (*num_appointments == 0) {
        printf("Sorry, there are no appointments to delete.\n");
        return;
    }
    char search_name[50];
    printf("Enter name: ");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < *num_appointments; i++) {
        if (strcmp(appointments[i].name, search_name) == 0) {
            printf("\nAppointment found and deleted.\n");
            for (int j = i; j < *num_appointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            *num_appointments -= 1;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nSorry, appointment not found.\n");
    }
}