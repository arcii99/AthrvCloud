//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 20

typedef struct appointment{
    char name[MAX_NAME_LENGTH];
    int time_hour;
    int time_minute;
}appointment;

appointment appointment_list[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(){
    appointment new_appointment;

    printf("Enter your name: ");
    scanf("%19s", new_appointment.name);

    printf("Enter the hour (0-23): ");
    scanf("%d", &new_appointment.time_hour);

    printf("Enter the minute (0-59): ");
    scanf("%d", &new_appointment.time_minute);

    if(num_appointments < MAX_APPOINTMENTS){
        appointment_list[num_appointments] = new_appointment;
        num_appointments++;
        printf("Appointment successfully scheduled for %s at %02d:%02d.\n", new_appointment.name, new_appointment.time_hour, new_appointment.time_minute);
    }else{
        printf("Sorry, appointment list is full. Please try again later.\n");
    }
}

void view_appointments(){
    if(num_appointments == 0){
        printf("No appointments scheduled at this time.\n");
        return;
    }

    printf("Scheduled Appointments:\n");

    for(int i=0;i<num_appointments;i++){
        appointment current_appointment;
        current_appointment = appointment_list[i];

        printf("%d. %s at %02d:%02d\n", i+1, current_appointment.name, current_appointment.time_hour, current_appointment.time_minute);
    }
}

void delete_appointment(){
    int appointment_number;

    view_appointments();

    printf("Enter the appointment number to delete: ");
    scanf("%d", &appointment_number);

    if(appointment_number > 0 && appointment_number <= num_appointments){
        appointment appointment_to_delete;
        appointment_to_delete = appointment_list[appointment_number-1];

        printf("Are you sure you want to delete the appointment for %s at %02d:%02d? (y/n) ", appointment_to_delete.name, appointment_to_delete.time_hour, appointment_to_delete.time_minute);

        char confirmation;
        scanf(" %c", &confirmation);

        if(tolower(confirmation) == 'y'){
            for(int i=appointment_number-1;i<num_appointments-1;i++){
                appointment_list[i] = appointment_list[i+1];
            }

            num_appointments--;
            printf("Appointment successfully deleted.\n");
        }else{
            printf("Appointment deletion cancelled.\n");
        }
    }else{
        printf("Invalid appointment number. Please try again.\n");
    }
}

int main(){
    printf("Welcome to the puzzle appointment scheduler!\n");

    char command = ' ';

    while(command != 'q'){
        printf("Please enter a command:\n");
        printf("a - add appointment\n");
        printf("v - view appointments\n");
        printf("d - delete appointment\n");
        printf("q - quit program\n");
        scanf(" %c", &command);

        switch(command){
            case 'a':
                add_appointment();
                break;
            case 'v':
                view_appointments();
                break;
            case 'd':
                delete_appointment();
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }
    }

    return 0;
}