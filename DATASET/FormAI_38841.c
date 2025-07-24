//FormAI DATASET v1.0 Category: System event logger ; Style: modular
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

//Function to log the events and write to file
void eventLogger(char* message, char* filename){

    time_t current_time;
    char* c_time_string;
    FILE *fptr;

    // Get the current time
    current_time = time(NULL);

    // Convert it to local time format.
    c_time_string = ctime(&current_time);

    // Open the file in append mode
    fptr = fopen(filename, "a");

    // If file does not open, return
    if(fptr==NULL){
        printf("Error opening file!");
        return;
    }

    // Write the event message along with current time
    fprintf(fptr, "%s: %s", c_time_string, message);

    // Close the file
    fclose(fptr);
}

int main(){

    // Log sample events with the eventLogger function
    eventLogger("System initiated", "events.txt");
    eventLogger("User logged in", "events.txt");
    eventLogger("File created", "events.txt");
    eventLogger("File deleted", "events.txt");

    return 0;
}