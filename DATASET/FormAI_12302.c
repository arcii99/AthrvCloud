//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define appointment structure
struct Appointment {
    char date[20];
    char time[20];
    char description[100];
};

// define appointment book structure
struct AppointmentBook {
    char name[50];
    struct Appointment appointments[100];
    int num_appointments;
};

// function to add an appointment to the appointment book
void addAppointment(struct AppointmentBook *book, char date[], char time[], char description[]) {
    // check if there is space for another appointment
    if (book->num_appointments >= 100) {
        printf("There is no space for another appointment.\n");
        return;
    }
    // add the appointment to the book
    strcpy(book->appointments[book->num_appointments].date, date);
    strcpy(book->appointments[book->num_appointments].time, time);
    strcpy(book->appointments[book->num_appointments].description, description);
    book->num_appointments++;
    printf("Appointment added.\n");
}

// function to display all appointments in the appointment book
void displayAppointments(struct AppointmentBook book) {
    printf("Appointments for %s:\n", book.name);
    for (int i = 0; i < book.num_appointments; i++) {
        printf("%d. Date: %s, Time: %s, Description: %s\n", i+1, book.appointments[i].date, book.appointments[i].time, book.appointments[i].description);
    }
}

int main() {
    // create a new appointment book
    struct AppointmentBook book;
    strcpy(book.name, "John Doe");
    book.num_appointments = 0;
    // menu loop
    while (1) {
        // display menu options
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Quit\n");
        printf("Enter your choice (1-3): ");
        // get user choice
        int choice;
        scanf("%d", &choice);
        // process user choice
        switch (choice) {
            case 1: {
                // add appointment
                char date[20];
                char time[20];
                char description[100];
                printf("Enter date (MM/DD/YYYY): ");
                scanf("%s", date);
                printf("Enter time (HH:MM AM/PM): ");
                scanf("%s", time);
                printf("Enter description: ");
                scanf(" %[^\n]s", description);
                addAppointment(&book, date, time, description);
                break;
            }
            case 2:
                // display appointments
                displayAppointments(book);
                break;
            case 3:
                // quit
                printf("Goodbye!\n");
                exit(0);
            default:
                // invalid choice
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}