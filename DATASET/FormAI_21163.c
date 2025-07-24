//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definition of Appointment structure
typedef struct appointment
{
    char clientName[50];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

//Function to compare two appointment structures by date and time
//Returns -1 if first appointment is earlier, 0 if they are the same, 1 if the first appointment is later
int compareAppointments(Appointment first, Appointment second)
{
    if (first.year < second.year)
    {
        return -1;
    }
    else if (first.year == second.year)
    {
        if (first.month < second.month)
        {
            return -1;
        }
        else if (first.month == second.month)
        {
            if (first.day < second.day)
            {
                return -1;
            }
            else if (first.day == second.day)
            {
                if (first.hour < second.hour)
                {
                    return -1;
                }
                else if (first.hour == second.hour)
                {
                    if (first.minute < second.minute)
                    {
                        return -1;
                    }
                    else if (first.minute == second.minute)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

//Function to add an appointment to an array of appointments
//Assumes appointments are ordered by date and time
void addAppointment(Appointment newAppointment, Appointment *appointments, int *numAppointments)
{
    int i, j;
    //Find the index where the new appointment should be added to maintain order
    for (i = 0; i < *numAppointments; i++)
    {
        if (compareAppointments(newAppointment, appointments[i]) < 1)
        {
            //Shift all appointments after this index back by one
            for (j = *numAppointments; j > i; j--)
            {
                appointments[j] = appointments[j - 1];
            }
            //Add the new appointment at the correct index
            appointments[i] = newAppointment;
            (*numAppointments)++;
            return;
        }
    }
    //If the new appointment should be added at the end of the array, simply add it there
    appointments[*numAppointments] = newAppointment;
    (*numAppointments)++;
}

//Function to print out all appointments in an array
void printAppointments(Appointment *appointments, int numAppointments)
{
    int i;
    for (i = 0; i < numAppointments; i++)
    {
        printf("%s - %d/%d/%d %d:%d\n", appointments[i].clientName, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute);
    }
}

int main()
{
    Appointment appointments[100];
    int numAppointments = 0;
    char input[50];
    Appointment newAppointment;

    printf("Welcome to the Appointment Scheduler!\n");

    while (1)
    {
        printf("\nEnter 'a' to add a new appointment, 'p' to print all appointments, or 'q' to quit: ");
        fgets(input, sizeof(input), stdin);

        if (strlen(input) < 2)
        {
            //Empty input, just ask again
            continue;
        }

        switch (input[0])
        {
        case 'a':
            printf("\nEnter client name: ");
            fgets(newAppointment.clientName, sizeof(newAppointment.clientName), stdin);
            newAppointment.clientName[strcspn(newAppointment.clientName, "\n")] = '\0';

            printf("Enter date (DD/MM/YYYY): ");
            scanf("%d/%d/%d", &newAppointment.day, &newAppointment.month, &newAppointment.year);

            printf("Enter time (HH:MM): ");
            scanf("%d:%d", &newAppointment.hour, &newAppointment.minute);

            //Flush the input buffer to remove the newline character left over from scanf
            while ((getchar()) != '\n');

            addAppointment(newAppointment, appointments, &numAppointments);
            printf("Appointment added!\n");
            break;

        case 'p':
            printf("\nAll Appointments:\n");
            printAppointments(appointments, numAppointments);
            break;

        case 'q':
            printf("\nGoodbye!\n");
            exit(0);
            break;

        default:
            printf("\nInvalid option.\n");
            break;
        }
    }

    return 0;
}