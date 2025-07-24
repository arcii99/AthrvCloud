//FormAI DATASET v1.0 Category: System event logger ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // seed the random number generator with current time
    FILE *file; // create a file pointer
    file = fopen("event.log", "w"); // open/create a file named "event.log" in write mode

    if(file == NULL){ // check if file has been opened/created successfully or not
        printf("Error: Could not open/create file!\n"); // print error message
        return 1; // exit program with error status
    }

    fprintf(file, "Starting event logging..\n"); // write a message to the file
    printf("Starting event logging..\n"); // indicate that event logging has started

    int c, i = 0;
    while(i < 50){ // log events 50 times
        c = rand() % 4; // generate a random number between 0 and 3
        switch(c){
            case 0:
                fprintf(file, "User logged in.\n"); // log user login event
                printf("User logged in.\n");
                break;
            case 1:
                fprintf(file, "File downloaded.\n"); // log file download event
                printf("File downloaded.\n");
                break;
            case 2:
                fprintf(file, "System updated.\n"); // log system update event
                printf("System updated.\n");
                break;
            default:
                fprintf(file, "Error occurred!\n"); // log error event
                printf("Error occurred!\n");
                break;
        }
        i++; // increment the counter
        sleep(1); // wait for 1 second
    }

    fprintf(file, "Stopping event logging..\n"); // write a message to the file
    printf("Stopping event logging..\n"); // indicate that event logging has stopped
    fclose(file); // close the file
    return 0; // exit program with success status
}