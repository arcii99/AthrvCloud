//FormAI DATASET v1.0 Category: System event logger ; Style: ephemeral
#include <stdio.h> // standard input/output library
#include <time.h> // library for working with time
#include <stdlib.h> // standard library
#include <string.h> // library for working with strings

int main()
{
    FILE *log_file; // create a pointer to a file

    log_file = fopen("event_log.txt", "a"); // open the file in append mode

    if (log_file == NULL) // check if the file could be opened
    {
        printf("Error opening file!\n"); // print an error message
        exit(1); // exit the program
    }

    char event[100]; // initialize an array to store the event description
    char date_time[50]; // initialize an array to store the current date and time

    time_t current_time = time(NULL); // get the current time
    strftime(date_time, 50, "%Y-%m-%d %H:%M:%S", localtime(&current_time)); // format the time as a string

    printf("Enter a brief description of the event: "); // prompt the user for the event description
    fgets(event, 100, stdin); // get the user input

    fprintf(log_file, "[%s] %s\n", date_time, event); // write the event to the file

    fclose(log_file); // close the file

    printf("Event logged successfully!\n"); // print a success message

    return 0; // exit the program
}