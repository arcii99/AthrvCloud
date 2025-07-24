//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: mind-bending
#include <stdio.h>
#include <time.h>

int main()
{
    time_t present_time = time(NULL);
    struct tm *present = localtime(&present_time);
    printf("Welcome to the Time Travel Appointment Scheduler\n\n");
    printf("Please enter the date you would like to schedule an appointment (mm/dd/yyyy): ");

    struct tm appointment;
    char user_input[11];
    fgets(user_input, 11, stdin);
    strptime(user_input, "%m/%d/%Y", &appointment);
    time_t appointment_time = mktime(&appointment);

    if (appointment_time <= present_time)
    {
        printf("You cannot schedule an appointment in the past. Please try again.\n");
        return 0;
    }

    printf("\nPlease enter the time of the appointment (hh:mm AM|PM): ");
    fgets(user_input, 11, stdin);
    strptime(user_input, "%I:%M %p", &appointment);

    appointment.tm_mday = appointment.tm_mday;
    appointment.tm_mon = appointment.tm_mon;
    appointment.tm_year = appointment.tm_year;
    appointment.tm_sec = 0;
    appointment.tm_isdst = -1;

    appointment_time = mktime(&appointment);

    printf("\nPlease enter your name: ");
    char name[50];
    scanf("%s", name);

    printf("\nYou have scheduled an appointment on %s at %s with %s.\n\n", user_input, name, ctime(&appointment_time));

    return 0;
}