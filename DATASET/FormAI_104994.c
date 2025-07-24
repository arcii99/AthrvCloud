//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct to hold appointment data
struct Appointment {
    char name[50];
    char date[20];
    char time[20];
};

// define a struct to hold available appointment times
struct AvailableTime {
    char date[20];
    char times[100][20];
    int num_times;
};

// function to print appointment details
void printAppointment(struct Appointment appt) {
    printf("Appointment with %s on %s at %s\n", appt.name, appt.date, appt.time);
}

// function to print available times for a certain date
void printAvailableTimes(struct AvailableTime time) {
    printf("Available times for %s:\n", time.date);
    for (int i = 0; i < time.num_times; i++) {
        printf("%s\n", time.times[i]);
    }
}

int main() {
    // create an array of available times for different dates
    struct AvailableTime available_times[5];
    strcpy(available_times[0].date, "08/16/2021");
    available_times[0].num_times = 3;
    strcpy(available_times[0].times[0], "10:00 AM");
    strcpy(available_times[0].times[1], "02:00 PM");
    strcpy(available_times[0].times[2], "04:00 PM");

    strcpy(available_times[1].date, "08/17/2021");
    available_times[1].num_times = 2;
    strcpy(available_times[1].times[0], "11:00 AM");
    strcpy(available_times[1].times[1], "03:00 PM");

    strcpy(available_times[2].date, "08/18/2021");
    available_times[2].num_times = 4;
    strcpy(available_times[2].times[0], "09:00 AM");
    strcpy(available_times[2].times[1], "12:00 PM");
    strcpy(available_times[2].times[2], "02:00 PM");
    strcpy(available_times[2].times[3], "05:00 PM");

    strcpy(available_times[3].date, "08/19/2021");
    available_times[3].num_times = 1;
    strcpy(available_times[3].times[0], "01:00 PM");

    strcpy(available_times[4].date, "08/20/2021");
    available_times[4].num_times = 3;
    strcpy(available_times[4].times[0], "11:00 AM");
    strcpy(available_times[4].times[1], "02:00 PM");
    strcpy(available_times[4].times[2], "04:00 PM");

    // initialize variables
    char name[50];
    char date[20];
    char time[20];
    int valid_input = 0;
    int chosen_date_index = -1;
    int chosen_time_index = -1;

    // get user input for name
    printf("Enter your name:\n");
    fgets(name, 50, stdin);
    strtok(name, "\n");

    // get user input for date
    while (!valid_input) {
        printf("Enter the date of your appointment (in MM/DD/YYYY format):\n");
        fgets(date, 20, stdin);
        strtok(date, "\n");

        // check if a matching date was found in available times array
        for (int i = 0; i < 5; i++) {
            if (strcmp(date, available_times[i].date) == 0) {
                chosen_date_index = i;
                valid_input = 1;
                break;
            }
        }

        if (!valid_input) {
            printf("Invalid date entered. Please try again.\n");
        }
    }

    // get user input for time
    valid_input = 0;
    while (!valid_input) {
        printf("Enter the time of your appointment (in HH:MM AM/PM format):\n");
        fgets(time, 20, stdin);
        strtok(time, "\n");

        // check if a matching time was found for chosen date
        for (int i = 0; i < available_times[chosen_date_index].num_times; i++) {
            if (strcmp(time, available_times[chosen_date_index].times[i]) == 0) {
                chosen_time_index = i;
                valid_input = 1;
                break;
            }
        }

        if (!valid_input) {
            printf("Invalid time entered. Please try again.\n");
            printAvailableTimes(available_times[chosen_date_index]);
        }
    }

    // create appointment struct and print details
    struct Appointment appt;
    strcpy(appt.name, name);
    strcpy(appt.date, date);
    strcpy(appt.time, time);
    printAppointment(appt);

    return 0;
}