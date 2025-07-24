//FormAI DATASET v1.0 Category: System event logger ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    FILE *log_file; //File pointer to write logs.
    char file_path[100]; //File path where log file is saved.
    char event_description[100]; //Event description by user.
    time_t current_time; //To get the current date/time.

    printf("Welcome to the Unique C System Event Logger Program!\n\n"); //Welcoming user.

    printf("Please enter the file path where the log file will be saved: \n");
    scanf("%s",file_path); //Taking file path from user.

    printf("\nGreat! Now let's start logging some events!\n\n"); //Encouraging user to log events.

    while(1) //Infinite loop until user wants to exit.
    {
        printf("Please enter the event description: ");
        scanf("%s",event_description); //Taking event description from user.

        if(strcmp(event_description,"exit")==0) //Checking if user wants to exit.
        {
            printf("\nThank you for using the Unique C System Event Logger Program!\nPlease check your log file for all the events :)\n");
            break; //Exiting the loop.
        }

        current_time = time(NULL); //Getting the current date/time.

        log_file = fopen(file_path,"a"); //Opening file in append mode.

        if(log_file == NULL) //Checking if file exists or not.
        {
            printf("Oops! Something went wrong. Please check the file path and try again.\n");
            continue; //Skipping current iteration and going back to start of loop.
        }

        fprintf(log_file,"%s : %s\n",asctime(localtime(&current_time)),event_description); //Writing event description and date/time to log file.

        fclose(log_file); //Closing file.

        printf("\nEvent logged successfully! Keep logging or say 'exit' to stop: \n\n"); //Informing user that event was logged successfully.
    }

    return 0; //Happily exiting the program.
}