//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 30
#define MAX_DATE_LENGTH 20

struct appointment {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
};

struct appointment appointment_list[MAX_APPOINTMENTS];

int num_appointments = 0;

void print_appointments() {
    printf("Appointment List:\n");
    for(int i = 0; i < num_appointments; i++) {
        printf("%d. Name: %s, Date: %s\n", i+1, appointment_list[i].name, appointment_list[i].date);
    }
}

void schedule_appointment() {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];

    printf("Enter appointment name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Enter appointment date (MM/DD/YYYY): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = 0;

    struct appointment new_appointment;
    strcpy(new_appointment.name, name);
    strcpy(new_appointment.date, date);

    if(num_appointments == MAX_APPOINTMENTS) {
        printf("Appointment list is full. Cannot schedule appointment.\n");
    } else {
        appointment_list[num_appointments++] = new_appointment;
    }
}

void cancel_appointment() {
    int appointment_number;

    if(num_appointments == 0) {
        printf("There are no appointments to cancel.\n");
        return;
    }

    print_appointments();

    printf("Enter the number of the appointment to cancel: ");
    scanf("%d", &appointment_number);

    if(appointment_number < 1 || appointment_number > num_appointments) {
        printf("Invalid appointment number.\n");
    } else {
        for(int i = appointment_number-1; i < num_appointments-1; i++) {
            appointment_list[i] = appointment_list[i+1];
        }
        num_appointments--;
        printf("Appointment cancelled.\n");
    }
}

int main() {
    char input[10];

    while(1) {
        printf("Enter a command: ");
        fgets(input, sizeof(input), stdin);

        if(strcmp(input, "schedule\n") == 0) {
            schedule_appointment();
        } else if(strcmp(input, "cancel\n") == 0) {
            cancel_appointment();
        } else if(strcmp(input, "list\n") == 0) {
            print_appointments();
        } else if(strcmp(input, "exit\n") == 0) {
            break;
        } else {
            printf("Invalid command. Valid commands are: schedule, cancel, list, exit.\n");
        }
    }

    return 0;
}