//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Appointment {
    char name[20];
    char date[15];
    char time[10];
    char location[50];
};

struct Appointments {
    struct Appointment apt[100];
    int count;
};

int menu();
void viewAppointment(struct Appointments *appointments);
void addAppointment(struct Appointments *appointments, char *name, char *date, char *time, char *location);
void cancelAppointment(struct Appointments *appointments, char *name, char *date, char *time);
void displayAppointments(struct Appointments *appointments);
int searchAppointment(struct Appointments *appointments, char *name, char *date, char *time);

int main() {
    char name[20], date[15], time[10], location[50];
    int option, count = 0;
    struct Appointments appointments;
    appointments.count = 0;

    while(1) {
        option = menu();

        switch(option){
            case 1: viewAppointment(&appointments); break;

            case 2: printf("Enter name: ");
                    scanf("%s", name);
                    printf("Enter date (dd/mm/yyyy): ");
                    scanf("%s", date);
                    printf("Enter time (hh:mm AM/PM): ");
                    scanf("%s", time);
                    printf("Enter location: ");
                    scanf("%s", location);
                    addAppointment(&appointments, name, date, time, location); break;

            case 3: printf("Enter name: ");
                    scanf("%s", name);
                    printf("Enter date (dd/mm/yyyy): ");
                    scanf("%s", date);
                    printf("Enter time (hh:mm AM/PM): ");
                    scanf("%s", time);
                    cancelAppointment(&appointments, name, date, time); break;

            case 4: displayAppointments(&appointments); break;

            case 5: exit(0);

            default: printf("Invalid option\n\n");
        }
    }

    return 0;
}

int menu() {
    int option;

    printf("\nAppointment Scheduler\n");
    printf("1. View Appointments\n");
    printf("2. Add Appointment\n");
    printf("3. Cancel Appointment\n");
    printf("4. Display Appointments\n");
    printf("5. Exit\n");

    printf("\nEnter your option: ");
    scanf("%d", &option);

    return option;
}

void viewAppointment(struct Appointments *appointments) {
    char name[20], date[15], time[10];

    printf("\nEnter name: ");
    scanf("%s", name);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", date);
    printf("Enter time (hh:mm AM/PM): ");
    scanf("%s", time);

    int index = searchAppointment(appointments, name, date, time);

    if(index != -1) {
        printf("\nName: %s\n", appointments->apt[index].name);
        printf("Date: %s\n", appointments->apt[index].date);
        printf("Time: %s\n", appointments->apt[index].time);
        printf("Location: %s\n\n", appointments->apt[index].location);
    }
    else {
        printf("\nAppointment not found.\n");
    }
}

void addAppointment(struct Appointments *appointments, char *name, char *date, char *time, char *location) {
    if(appointments->count == 100) {
        printf("Appointment scheduler full. Cannot add new appointments.\n");
        return;
    }

    if(searchAppointment(appointments, name, date, time) != -1) {
        printf("\nAppointment already exists.\n");
        return;
    }

    strcpy(appointments->apt[appointments->count].name, name);
    strcpy(appointments->apt[appointments->count].date, date);
    strcpy(appointments->apt[appointments->count].time, time);
    strcpy(appointments->apt[appointments->count].location, location);

    appointments->count++;

    printf("\nAppointment added successfully.\n");
}

void cancelAppointment(struct Appointments *appointments, char *name, char *date, char *time) {
    int index = searchAppointment(appointments, name, date, time);

    if(index == -1) {
        printf("\nAppointment not found.\n");
        return;
    }

    for(int i = index; i < appointments->count - 1; i++) {
        appointments->apt[i] = appointments->apt[i + 1];
    }

    appointments->count--;

    printf("\nAppointment cancelled successfully.\n");
}

void displayAppointments(struct Appointments *appointments) {
    if(appointments->count == 0) {
        printf("\nNo appointments found.\n");
        return;
    }

    printf("\nAppointments:\n");

    for(int i = 0; i < appointments->count; i++) {
        printf("\nName: %s\n", appointments->apt[i].name);
        printf("Date: %s\n", appointments->apt[i].date);
        printf("Time: %s\n", appointments->apt[i].time);
        printf("Location: %s\n", appointments->apt[i].location);
    }
}

int searchAppointment(struct Appointments *appointments, char *name, char *date, char *time) {
    for(int i = 0; i < appointments->count; i++) {
        if(strcmp(appointments->apt[i].name, name) == 0 
            && strcmp(appointments->apt[i].date, date) == 0
            && strcmp(appointments->apt[i].time, time) == 0) {
            return i;
        }
    }

    return -1;
}