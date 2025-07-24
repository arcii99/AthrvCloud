//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Welcome to Dr. Funny's Appointment Scheduler!\n");
    int numAppointments = 0;

    printf("Please enter the number of appointments you would like to make: ");
    scanf("%d", &numAppointments);

    if(numAppointments < 1){
        printf("Sorry, we cannot schedule less than 1 appointment. Please try again, but this time make it worth our while.\n");
        return 0;
    }

    char name[20];
    int hour, minute;

    for(int i=1; i<=numAppointments; i++){
        printf("Appointment %d:\n", i);
        printf("Name: ");
        scanf("%s", &name);
        printf("Appointment Hour (24-hour format): ");
        scanf("%d", &hour);
        printf("Appointment Minute: ");
        scanf("%d", &minute);

        if(hour < 8 || hour > 17){
            printf("Sorry %s, Dr. Funny is not available at that time. Please try again during our business hours (between 8am and 5pm).\n", name);
        }else if(hour == 12 && minute == 0){
            printf("Whoa %s, you just missed Dr. Funny's lunch break! Please schedule should be after 1pm.\n", name);
        }else{
            printf("Great %s! Your appointment has been scheduled for %d:%02d. We'll see you then!\n", name, hour, minute);
        }
    }

    printf("Thanks for choosing Dr. Funny's Appointment Scheduler! See you soon!\n");
    return 0;
}