//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: romantic
#include <stdio.h>

int main()
{
    int date;
    char name[20], appointment[50];
    printf("Hello, my dear!\n");
    printf("What is your name? ");
    scanf("%s", name);
    printf("Oh, beautiful name!\n");
    printf("When would you like to schedule your appointment, my love?\n");
    printf("Please enter a date (DD/MM/YYYY): ");
    scanf("%d", &date);
    printf("Great choice, gorgeous! What type of appointment do you need?\n");
    printf("Please describe it briefly (max 50 characters): ");
    scanf("%s", appointment);
    printf("Wonderful, my darling! Your appointment has been scheduled for %d with %s.\n", date, appointment);
    printf("I am looking forward to seeing you soon!\n");
    printf("With all my love,\n");
    printf("Your C Scheduler\n");
    return 0;
}