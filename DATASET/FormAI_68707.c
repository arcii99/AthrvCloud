//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Struct to represent appointments
typedef struct Appointment {
    char name[50];
    int day;
    int month;
    int year;
    char time[10];
} Appointment;

// Function to print the appointment
void printAppointment(Appointment appt) {
    printf("%s has an appointment on %d/%d/%d at %s\n", appt.name, appt.day, appt.month, appt.year, appt.time);
}

// Function to check if two appointments are on the same day
bool isSameDay(Appointment a1, Appointment a2) {
    return (a1.day == a2.day && a1.month == a2.month && a1.year == a2.year);
}

// Function to check if two appointments have conflicting time slots
bool isConflicting(Appointment a1, Appointment a2) {
    if (isSameDay(a1, a2)) {
        if (strcmp(a1.time, a2.time) == 0) {
            return true;
        }
    }
    return false;
}

// Function to add a new appointment to the scheduler
void addAppointment(Appointment *appts, int *count) {
    printf("Please enter the name of the appointment: ");
    scanf(" %[^\n]s", appts[*count].name);
    printf("Please enter the date of the appointment (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &appts[*count].day, &appts[*count].month, &appts[*count].year);
    printf("Please enter the time of the appointment (HH:MM AM/PM): ");
    scanf(" %[^\n]s", appts[*count].time);
    printf("Appointment added successfully!\n");
    (*count)++;
}

// Function to display all appointments on a given day
void viewAppointmentsOnDay(Appointment *appts, int count) {
    int day, month, year;
    printf("Please enter the date to view (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &day, &month, &year);
    printf("Appointments on %d/%d/%d:\n", day, month, year);
    for (int i = 0; i < count; i++) {
        if (day == appts[i].day && month == appts[i].month && year == appts[i].year) {
            printAppointment(appts[i]);
        }
    }
}

// Function to delete an appointment
void deleteAppointment(Appointment *appts, int *count) {
    int indexToDelete = -1;
    char name[50];
    printf("Please enter the name of the appointment to delete: ");
    scanf(" %[^\n]s", name);
    for (int i = 0; i < *count; i++) {
        if (strcmp(name, appts[i].name) == 0) {
            indexToDelete = i;
            break;
        }
    }
    if (indexToDelete == -1) {
        printf("Error: appointment not found.\n");
        return;
    }
    for (int i = indexToDelete; i < *count - 1; i++) {
        appts[i] = appts[i+1];
    }
    (*count)--;
    printf("Appointment deleted successfully!\n");
}

// Function to check for conflicting appointments
bool hasConflicts(Appointment *appts, int count, Appointment newAppt) {
    for (int i = 0; i < count; i++) {
        if (isConflicting(appts[i], newAppt)) {
            return true;
        }
    }
    return false;
}

// Main function
int main() {
    Appointment appts[100];
    int count = 0;
    int choice;

    // Loop to present menu to user
    while (true) {
        printf("\nAPPOINTMENT SCHEDULER - MENU");
        printf("\n1. Add an appointment.");
        printf("\n2. View appointments on a day.");
        printf("\n3. Delete an appointment.");
        printf("\n4. Exit the program.\n");
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Appointment newAppt;
                addAppointment(&newAppt, &count);
                if (hasConflicts(appts, count, newAppt)) {
                    printf("Error: appointment time conflicts with another appointment.\n");
                    count--;
                } else {
                    appts[count-1] = newAppt;
                }
                break;
            case 2:
                viewAppointmentsOnDay(appts, count);
                break;
            case 3:
                deleteAppointment(appts, &count);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}