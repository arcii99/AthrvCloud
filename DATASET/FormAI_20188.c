//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to handle scheduling an appointment
void scheduleAppointment(char *name, char *date, char *time) {
    FILE *fp;
    // Check if file containing schedule already exists, if not create one
    if ((fp = fopen("schedule.txt", "r")) == NULL) {
        fp = fopen("schedule.txt", "w");
        fprintf(fp, "Appointment Schedule\n\n");
        fprintf(fp, "Name\t\tDate\t\tTime\n");
    }
    fclose(fp);

    // Append new appointment to file
    fp = fopen("schedule.txt", "a");
    fprintf(fp, "%s\t\t%s\t\t%s\n", name, date, time);
    printf("Appointment Scheduled!\n");
    fclose(fp);
}

// Function to view the appointment schedule
void viewSchedule() {
    FILE *fp;
    char ch;
    // Check if file containing schedule exists, if not return error message
    if ((fp = fopen("schedule.txt", "r")) == NULL) {
        printf("Appointment schedule not found.\n");
        return;
    }

    printf("\nAppointment Schedule\n\n");
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);
}

// Main function to handle user input and scheduling/reviewing appointments
int main() {
    printf("Welcome to the Appointment Scheduler!\n");

    char choice[10];
    char name[50];
    char date[15];
    char time[10];

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Schedule an appointment\n");
        printf("2. View schedule\n");
        printf("3. Exit\n");

        fgets(choice, 10, stdin);

        switch (atoi(choice)) {
            case 1: 
                printf("Enter your name: ");
                fgets(name, 50, stdin);
                printf("Enter the date (MM/DD/YYYY): ");
                fgets(date, 15, stdin);
                printf("Enter the time (HH:MM AM/PM): ");
                fgets(time, 10, stdin);
                scheduleAppointment(name, date, time);
                break;
            case 2:
                viewSchedule();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (atoi(choice) != 3);

    return 0;
}