//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 50

struct appointment{
    char name[MAX_NAME_LENGTH];
    int date;
    int time;
};

struct appointment appts[MAX_APPOINTMENTS]; // array of appointments
int numAppts = 0; // number of appointments scheduled

int main(){
    int choice;
    do{
        printf("\n1. Schedule Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Cancel Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: scheduleAppointment(); break;
            case 2: viewAppointments(); break;
            case 3: cancelAppointment(); break;
            case 4: printf("Exiting program..."); break;
            default: printf("Invalid choice.\n"); break;
        }
    }while(choice != 4);

    return 0;
}

void scheduleAppointment(){
    if(numAppts >= MAX_APPOINTMENTS){
        printf("Max appointments reached.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", appts[numAppts].name);

    printf("Enter date (MMDDYYYY): ");
    scanf("%d", &appts[numAppts].date);

    printf("Enter time (24 hour clock): ");
    scanf("%d", &appts[numAppts].time);

    printf("Appointment scheduled successfully.\n");

    numAppts++;
}

void viewAppointments(){
    if(numAppts == 0){
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Name\t\tDate\t\tTime\n");
    for(int i=0; i<numAppts; i++){
        printf("%s\t\t%d\t\t%d\n", appts[i].name, appts[i].date, appts[i].time);
    }
}

void cancelAppointment(){
    if(numAppts == 0){
        printf("No appointments scheduled.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter name: ");
    scanf("%s", name);

    for(int i=0; i<numAppts; i++){
        if(strcmp(appts[i].name, name) == 0){
            // appointment found
            printf("Appointment scheduled for %s on %d at %d has been cancelled.\n", appts[i].name, appts[i].date, appts[i].time);
            // move all appointments after this appointment up one index
            for(int j=i; j<numAppts-1; j++){
                strcpy(appts[j].name, appts[j+1].name);
                appts[j].date = appts[j+1].date;
                appts[j].time = appts[j+1].time;
            }
            numAppts--;
            return;
        }
    }
    printf("Appointment not found.\n");
}