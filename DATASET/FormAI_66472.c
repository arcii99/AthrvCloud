//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: grateful
#include <stdio.h>
#include <string.h>

// Define structures
typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    int age;
    char gender[10];
    char phone[15];
} Patient;

typedef struct {
    int id;
    char doctor[50];
    char specialty[50];
    Date date;
    char time[10];
    Patient patient;
} Appointment;

// Declare functions
void addAppointment(Appointment appointments[], int *appointmentCount);
void deleteAppointment(Appointment appointments[], int *appointmentCount);
void viewAppointments(Appointment appointments[], int appointmentCount);
void searchAppointment(Appointment appointments[], int appointmentCount);

// Main function
int main() {
    Appointment appointments[50];
    int appointmentCount = 0;
    int choice = 0;

    printf("Welcome to the Appointment Scheduler!\n");

    while (choice != 5) {
        printf("\nPlease select an option:\n");
        printf("1. Add an appointment\n");
        printf("2. Delete an appointment\n");
        printf("3. View all appointments\n");
        printf("4. Search for an appointment\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addAppointment(appointments, &appointmentCount);
                break;
            case 2:
                deleteAppointment(appointments, &appointmentCount);
                break;
            case 3:
                viewAppointments(appointments, appointmentCount);
                break;
            case 4:
                searchAppointment(appointments, appointmentCount);
                break;
            case 5:
                printf("Thank you for using the Appointment Scheduler!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add an appointment
void addAppointment(Appointment appointments[], int *appointmentCount) {
    Appointment newAppointment;

    printf("\nEnter appointment ID: ");
    scanf("%d", &newAppointment.id);
    printf("Enter doctor's name: ");
    scanf("%s", newAppointment.doctor);
    printf("Enter doctor's specialty: ");
    scanf("%s", newAppointment.specialty);
    printf("Enter date of appointment (dd mm yyyy): ");
    scanf("%d %d %d", &newAppointment.date.day, &newAppointment.date.month, &newAppointment.date.year);
    printf("Enter time of appointment (hh:mm): ");
    scanf("%s", newAppointment.time);
    printf("Enter patient name: ");
    scanf("%s", newAppointment.patient.name);
    printf("Enter patient age: ");
    scanf("%d", &newAppointment.patient.age);
    printf("Enter patient gender: ");
    scanf("%s", newAppointment.patient.gender);
    printf("Enter patient phone number: ");
    scanf("%s", newAppointment.patient.phone);

    appointments[*appointmentCount] = newAppointment;
    *appointmentCount += 1;

    printf("\nAppointment added successfully!\n");
}

// Function to delete an appointment
void deleteAppointment(Appointment appointments[], int *appointmentCount) {
    int idToDelete;
    int found = 0;
    int i;

    printf("\nEnter appointment ID to delete: ");
    scanf("%d", &idToDelete);

    for (i = 0; i < *appointmentCount; i++) {
        if (appointments[i].id == idToDelete) {
            appointments[i] = appointments[*appointmentCount - 1];
            *appointmentCount -= 1;
            found = 1;
            printf("\nAppointment deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nAppointment not found.\n");
    }
}

// Function to view all appointments
void viewAppointments(Appointment appointments[], int appointmentCount) {
    int i;

    printf("\nList of appointments:\n");

    for (i = 0; i < appointmentCount; i++) {
        printf("\nAppointment ID: %d\n", appointments[i].id);
        printf("Doctor's name: %s\n", appointments[i].doctor);
        printf("Doctor's specialty: %s\n", appointments[i].specialty);
        printf("Date of appointment: %d/%d/%d\n", appointments[i].date.day, appointments[i].date.month, appointments[i].date.year);
        printf("Time of appointment: %s\n", appointments[i].time);
        printf("Patient name: %s\n", appointments[i].patient.name);
        printf("Patient age: %d\n", appointments[i].patient.age);
        printf("Patient gender: %s\n", appointments[i].patient.gender);
        printf("Patient phone number: %s\n", appointments[i].patient.phone);
    }
}

// Function to search for an appointment
void searchAppointment(Appointment appointments[], int appointmentCount) {
    int searchChoice;
    int i;
    int found = 0;
    int idToSearch;

    printf("\nWhat would you like to search by?\n");
    printf("1. Appointment ID\n");
    printf("2. Doctor's name\n");
    printf("3. Date of appointment\n");
    printf("4. Patient name\n");

    scanf("%d", &searchChoice);

    switch(searchChoice) {
        case 1:
            printf("\nEnter appointment ID to search for: ");
            scanf("%d", &idToSearch);

            for (i = 0; i < appointmentCount; i++) {
                if (appointments[i].id == idToSearch) {
                    printf("\nAppointment found:\n");
                    printf("Doctor's name: %s\n", appointments[i].doctor);
                    printf("Doctor's specialty: %s\n", appointments[i].specialty);
                    printf("Date of appointment: %d/%d/%d\n", appointments[i].date.day, appointments[i].date.month, appointments[i].date.year);
                    printf("Time of appointment: %s\n", appointments[i].time);
                    printf("Patient name: %s\n", appointments[i].patient.name);
                    printf("Patient age: %d\n", appointments[i].patient.age);
                    printf("Patient gender: %s\n", appointments[i].patient.gender);
                    printf("Patient phone number: %s\n", appointments[i].patient.phone);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("\nAppointment not found.\n");
            }

            break;
        case 2:
            char doctorName[50];

            printf("\nEnter doctor's name to search for: ");
            scanf("%s", doctorName);

            for (i = 0; i < appointmentCount; i++) {
                if (strcmp(appointments[i].doctor, doctorName) == 0) {
                    printf("\nAppointment found:\n");
                    printf("Appointment ID: %d\n", appointments[i].id);
                    printf("Doctor's specialty: %s\n", appointments[i].specialty);
                    printf("Date of appointment: %d/%d/%d\n", appointments[i].date.day, appointments[i].date.month, appointments[i].date.year);
                    printf("Time of appointment: %s\n", appointments[i].time);
                    printf("Patient name: %s\n", appointments[i].patient.name);
                    printf("Patient age: %d\n", appointments[i].patient.age);
                    printf("Patient gender: %s\n", appointments[i].patient.gender);
                    printf("Patient phone number: %s\n", appointments[i].patient.phone);
                    found = 1;
                }
            }

            if (!found) {
                printf("\nNo appointments found for the given doctor's name.\n");
            }

            break;
        case 3:
            Date dateToSearch;

            printf("\nEnter date of appointment to search for (dd mm yyyy): ");
            scanf("%d %d %d", &dateToSearch.day, &dateToSearch.month, &dateToSearch.year);

            for (i = 0; i < appointmentCount; i++) {
                if (appointments[i].date.day == dateToSearch.day && appointments[i].date.month == dateToSearch.month && appointments[i].date.year == dateToSearch.year) {
                    printf("\nAppointment found:\n");
                    printf("Appointment ID: %d\n", appointments[i].id);
                    printf("Doctor's name: %s\n", appointments[i].doctor);
                    printf("Doctor's specialty: %s\n", appointments[i].specialty);
                    printf("Time of appointment: %s\n", appointments[i].time);
                    printf("Patient name: %s\n", appointments[i].patient.name);
                    printf("Patient age: %d\n", appointments[i].patient.age);
                    printf("Patient gender: %s\n", appointments[i].patient.gender);
                    printf("Patient phone number: %s\n", appointments[i].patient.phone);
                    found = 1;
                }
            }

            if (!found) {
                printf("\nNo appointments found for the given date.\n");
            }

            break;
        case 4:
            char patientName[50];

            printf("\nEnter patient's name to search for: ");
            scanf("%s", patientName);

            for (i = 0; i < appointmentCount; i++) {
                if (strcmp(appointments[i].patient.name, patientName) == 0) {
                    printf("\nAppointment found:\n");
                    printf("Appointment ID: %d\n", appointments[i].id);
                    printf("Doctor's name: %s\n", appointments[i].doctor);
                    printf("Doctor's specialty: %s\n", appointments[i].specialty);
                    printf("Date of appointment: %d/%d/%d\n", appointments[i].date.day, appointments[i].date.month, appointments[i].date.year);
                    printf("Time of appointment: %s\n", appointments[i].time);
                    printf("Patient age: %d\n", appointments[i].patient.age);
                    printf("Patient gender: %s\n", appointments[i].patient.gender);
                    printf("Patient phone number: %s\n", appointments[i].patient.phone);
                    found = 1;
                }
            }

            if (!found) {
                printf("\nNo appointments found for the given patient's name.\n");
            }

            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}