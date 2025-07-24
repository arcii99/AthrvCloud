//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function that returns a random number between min and max
int random_num(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

//function to print the time in hh:mm format
void print_time(int hours, int minutes) {
    printf("%02d:%02d", hours, minutes);
}

int main() {
    srand(time(NULL));  //initialize random seed
    
    //set initial time
    int hours = 0;
    int minutes = 0;
    
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Your journey begins at ");
    print_time(hours, minutes);
    printf(".\n");
    
    //time travel loop
    for(int i=1; i<=10; i++) {
        int travel_hours = random_num(1, 12); //randomly travel 1-12 hours
        int travel_minutes = random_num(0, 59); //randomly travel 0-59 minutes
        
        //update time
        hours += travel_hours;
        minutes += travel_minutes;
        if(minutes >= 60) {
            hours++; //carry over extra minutes to hours
            minutes -= 60;
        }
        
        printf("Time Travel #%d: You have traveled for ", i);
        if(travel_hours > 1) {
            printf("%d hours", travel_hours);
        } else if(travel_hours == 1) {
            printf("1 hour");
        }
        if(travel_minutes > 0) {
            if(travel_hours > 0) {
                printf(" and ");
            }
            printf("%d minutes", travel_minutes);
        }
        printf(".\n");
        
        printf("The current time is ");
        print_time(hours, minutes);
        printf(".\n");
    }
    
    printf("Time Travel Simulator has ended. Your final time is ");
    print_time(hours, minutes);
    printf(".\n");
    
    return 0;
}