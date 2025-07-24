//FormAI DATASET v1.0 Category: System event logger ; Style: funny
#include <stdio.h>

int main()
{
    printf("Welcome to the C System Event Logger!\n\n");

    char event[50];
    printf("Enter an event you would like to log: \n");
    scanf("%s", event);

    int day, month, year;
    printf("\nEnter the date the event occurred (DD/MM/YYYY): \n");
    scanf("%d/%d/%d", &day, &month, &year);

    int hour, minute;
    printf("\nEnter the time the event occurred (HH:MM): \n");
    scanf("%d:%d", &hour, &minute);

    printf("\nEvent logged successfully! Code generated.\n");

    printf("\nint eventDate[3] = {%d, %d, %d};", day, month, year);
    printf("\nint eventTime[2] = {%d, %d};", hour, minute);
    printf("\nchar eventDesc[50] = \"%s\";", event);

    printf("\n\nThank you for using the C System Event Logger. Have a nice day!");

    return 0;
}