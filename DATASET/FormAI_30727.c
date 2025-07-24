//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int days, pushups = 0, squats = 0; //initialize variables for days, pushups, and squats
    float avg_pushups, avg_squats;
    
    printf("How many days have you been tracking your fitness? "); 
    scanf("%d", &days); //get user input for number of days
    
    for(int i = 1; i <= days; i++) { //for loop for each day
        int pushups_today, squats_today;
        
        printf("\nDay %d: \n", i); 
        printf("How many pushups did you do today? ");
        scanf("%d", &pushups_today); //get user input for number of pushups for that day
        
        printf("How many squats did you do today? ");
        scanf("%d", &squats_today); //get user input for number of squats for that day
        
        pushups += pushups_today; //add pushups for that day to running total
        squats += squats_today; //add squats for that day to running total
    }
    
    avg_pushups = (float) pushups / days; //calculate average number of pushups per day
    avg_squats = (float) squats / days; //calculate average number of squats per day
    
    printf("\nTotal pushups: %d\n", pushups);
    printf("Total squats: %d\n", squats);
    printf("Average pushups per day: %.2f\n", avg_pushups);
    printf("Average squats per day: %.2f\n", avg_squats);
    
    return 0;
}