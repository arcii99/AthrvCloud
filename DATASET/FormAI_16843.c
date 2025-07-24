//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// A structure to represent each appointment
struct Appointment{
    char date[11];
    char time[6];
    char name[50];
};

int main(){
    printf("Welcome to My Appointment Scheduler\n");
    int n;
    printf("Enter the number of appointments you want to add: ");
    scanf("%d", &n);

    // Dynamically allocate an array of appointments
    struct Appointment *appointments = (struct Appointment*)malloc(n*sizeof(struct Appointment));

    // Get appointment details from user
    for(int i=0;i<n;i++){
        printf("\nAppointment %d:\n", (i+1));
        printf("Enter Date (in format DD/MM/YYYY): ");
        scanf("%s", appointments[i].date);
        printf("Enter Time (in 24 hr format HH:MM): ");
        scanf("%s", appointments[i].time);
        printf("Enter Name of the Person: ");
        scanf("%s", appointments[i].name);
    }

    // Display the appointments
    printf("\nYour Appointments are:\n");
    printf("Date\t\t   Time\t    Name\n");
    for(int i=0;i<n;i++){
        printf("%s\t%s\t%s\n", appointments[i].date, appointments[i].time, appointments[i].name);
    }

    // Free the allocated memory
    free(appointments);

    return 0;
}