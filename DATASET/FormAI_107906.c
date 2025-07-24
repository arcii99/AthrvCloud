//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char date[10];
    char time[8];
    char description[100];
};

int main()
{
    printf("Welcome to the appointment scheduler!\n");

    int num_appointments;
    printf("How many appointments do you want to schedule? ");
    scanf("%d", &num_appointments);

    struct appointment *appointments = malloc(num_appointments * sizeof(struct appointment));

    for (int i = 0; i < num_appointments; i++) {
        printf("\nAppointment #%d:\n", i+1);

        printf("Date (mm/dd/yy): ");
        scanf("%s", appointments[i].date);

        printf("Time (hh:mm AM/PM): ");
        scanf("%s", appointments[i].time);

        printf("Description: ");
        getchar(); // get newline character from previous scanf
        fgets(appointments[i].description, sizeof(appointments[i].description), stdin);
    }

    printf("\nYour scheduled appointments:\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("\nAppointment #%d:\n", i+1);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Description: %s", appointments[i].description);
    }

    free(appointments);
    printf("\nThank you for using our appointment scheduler!");
    return 0;
}