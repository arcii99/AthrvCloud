//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include<stdio.h>
#include<string.h>

struct appointment{
    int day;
    int hour;
    char name[50];
};

int main(){
    struct appointment calendar[30][24];//creating a calendar structure
    int choice;
    int day, hour, index;

    while(1){ //infinite loop to keep the program running
        printf("\n----------- Menu -----------");
        printf("\n1. Schedule an appointment");
        printf("\n2. Update an appointment");
        printf("\n3. Cancel an appointment");
        printf("\n4. Display appointments for a day");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the day (1-30): ");
                scanf("%d", &day);
                printf("\nEnter the hour (0-23): ");
                scanf("%d", &hour);

                if(strlen(calendar[day-1][hour].name)>1){ //checking if appointment already exists
                    printf("\nAppointment already exists at this time. Please update or cancel the appointment.");
                }else{
                    printf("\nEnter the name: ");
                    scanf("%s", calendar[day-1][hour].name);

                    calendar[day-1][hour].day = day;
                    calendar[day-1][hour].hour = hour;

                    printf("\nAppointment scheduled successfully!");
                }
                
                break;
            case 2:
                printf("\nEnter the day (1-30): ");
                scanf("%d", &day);
                printf("\nEnter the hour (0-23): ");
                scanf("%d", &hour);

                if(strlen(calendar[day-1][hour].name)<=1){ //checking if appointment exists
                    printf("\nNo appointment exists at this time.");
                }else{
                    printf("\nEnter the new name: ");
                    scanf("%s", calendar[day-1][hour].name);

                    printf("\nAppointment updated successfully!");
                }
                
                break;
            case 3:
                printf("\nEnter the day (1-30): ");
                scanf("%d", &day);
                printf("\nEnter the hour (0-23): ");
                scanf("%d", &hour);

                if(strlen(calendar[day-1][hour].name)<=1){ //checking if appointment exists
                    printf("\nNo appointment exists at this time.");
                }else{
                    strcpy(calendar[day-1][hour].name,""); //clearing the name field
                    printf("\nAppointment cancelled successfully!");
                }
                
                break;
            case 4:
                printf("\nEnter the day (1-30): ");
                scanf("%d", &day);

                printf("\nAppointments for day %d:\n", day);
                for(int i=0; i<24; ++i){ //iterating over the hours of the day
                    if(strlen(calendar[day-1][i].name)>1){ //checking if appointment exists
                        printf("%d:00 - %d:00: %s\n", i, i+1, calendar[day-1][i].name);
                    }
                }

                break;
            case 5:
                exit(0); //exiting the program
            default:
                printf("\nInvalid choice!");
                break;
        }
    }

    return 0;
}