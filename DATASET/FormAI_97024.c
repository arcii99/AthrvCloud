//FormAI DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Function to print the time in a medieval style
void print_time() {
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    printf("\n\nThe time is now:\n");
    printf("#####################\n");
    printf("#                   #\n");
    printf("#    %s    #\n", c_time_string);
    printf("#                   #\n");
    printf("#####################\n");
}

//Function to print the tasks for the day
void print_tasks() {
    printf("\n\nHere are the tasks for the day:\n");
    printf("####################################\n");
    printf("#                                  #\n");
    printf("# - Slay the dragon                #\n");
    printf("# - Rescue the princess            #\n");
    printf("# - Defeat the evil sorcerer       #\n");
    printf("#                                  #\n");
    printf("####################################\n");
}

int main() {
    //Set up the start time for the scheduler
    time_t start_time;
    start_time = time(NULL);
    printf("Welcome to the Medieval Task Scheduler!\n\n");

    //Print the current time and tasks for the day
    print_time();
    print_tasks();

    //Initialize the task counters
    int dragon_counter = 0;
    int princess_counter = 0;
    int sorcerer_counter = 0;

    //Set up the scheduler loop
    while(1) {
        //Wait for one minute
        sleep(60);

        //Print the current time
        print_time();

        //Check which tasks need to be done and print a message
        if(dragon_counter < 3) {
            printf("\nTime to slay the dragon again!\n");
            dragon_counter++;
        }
        if(princess_counter < 1) {
            printf("\nRescue the princess, she's been captured again!\n");
            princess_counter++;
        }
        if(sorcerer_counter < 2) {
            printf("\nDefeat the evil sorcerer to save the kingdom!\n");
            sorcerer_counter++;
        }

        //Check if all tasks have been completed for the day
        if(dragon_counter >= 3 && princess_counter >= 1 && sorcerer_counter >= 2) {
            printf("\n\nWell done! All tasks for the day have been completed!\n");
            break;
        }
    }

    //Calculate the total time the scheduler was running and print it
    time_t end_time;
    end_time = time(NULL);
    double total_time = difftime(end_time, start_time);
    printf("\nThe Medieval Task Scheduler was running for %.2lf minutes.\n", total_time/60);

    return 0;
}