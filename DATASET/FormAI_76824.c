//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct appointment {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    char name[50];
    char email[50];
} Appointment;

void printMenu() {
    printf("\nSelect an option:\n");
    printf("1. Schedule an appointment\n");
    printf("2. View scheduled appointments\n");
    printf("3. Cancel an appointment\n");
    printf("4. Quit\n");
}

bool isValidAppointment(Appointment appt) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currDay = tm.tm_mday;
    int currMonth = tm.tm_mon + 1;
    int currYear = tm.tm_year + 1900;
    int currHour = tm.tm_hour;
    int currMin = tm.tm_min;

    if (appt.year < currYear || (appt.year == currYear && appt.month < currMonth))
        return false;
    else if (appt.month == currMonth && appt.day < currDay)
        return false;
    else if (appt.day == currDay && (appt.hour < currHour || (appt.hour == currHour && appt.minute <= currMin)))
        return false;

    return true;
}

void scheduleAppointment(Appointment appts[], int numAppts) {
    printf("\nEnter details for appointment #%d\n", numAppts + 1);

    do {
        printf("Name (max 50 characters): ");
        scanf("%49s", appts[numAppts].name);
    } while (strlen(appts[numAppts].name) == 0);

    do {
        printf("Email (max 50 characters): ");
        scanf("%49s", appts[numAppts].email);
    } while (strlen(appts[numAppts].email) == 0);

    printf("Date (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &appts[numAppts].month, &appts[numAppts].day, &appts[numAppts].year);

    printf("Time (24-hour HH:MM): ");
    scanf("%d:%d", &appts[numAppts].hour, &appts[numAppts].minute);

    if (isValidAppointment(appts[numAppts]))
        printf("Appointment scheduled successfully!\n");
    else {
        printf("Invalid appointment time! Appointment not scheduled.\n");
        appts[numAppts].name[0] = '\0';
        appts[numAppts].email[0] = '\0';
    }
}

void viewAppointments(Appointment appts[], int numAppts) {
    if (numAppts == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    printf("-------------------------------------------------\n");
    printf("| %-4s | %-20s | %-20s |\n", "ID", "Name", "Email");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < numAppts; i++) {
        printf("| %-4d | %-20s | %-20s |\n", i+1, appts[i].name, appts[i].email);
        printf("-------------------------------------------------\n");
    }
}

void cancelAppointment(Appointment appts[], int* numAppts) {
    viewAppointments(appts, *numAppts);

    if (*numAppts == 0) {
        printf("No appointments scheduled. Nothing to cancel.\n");
        return;
    }

    int choice = 0;

    do {
        printf("Enter the ID of the appointment you wish to cancel: ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > *numAppts);

    printf("Appointment with ID %d has been cancelled.\n", choice);

    for (int i = choice-1; i < *numAppts-1; i++) {
        appts[i] = appts[i+1];
    }

    (*numAppts)--;
}

int main() {
    Appointment appts[50];
    int numAppts = 0;
    int choice = 0;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scheduleAppointment(appts, numAppts);
                if (strlen(appts[numAppts].name) > 0) {
                    numAppts++;
                    printf("\n");
                }
                break;
            case 2:
                viewAppointments(appts, numAppts);
                break;
            case 3:
                cancelAppointment(appts, &numAppts);
                break;
            case 4:
                printf("\nThank you for using the appointment scheduler. Have a nice day!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}