//FormAI DATASET v1.0 Category: Log analysis ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

int main(){

    // A cheerful greeting to start the program!
    printf("Hello there! Welcome to the log analysis program.\n\n");

    // Opening the log file
    FILE *log_file = fopen("server_log.txt", "r");
    
    // Error handling for unable to open the log file
    if (log_file == NULL){
        printf("Oops! There seems to be an error opening the log file.\n\n");
        exit(1);
    }

    // Initializing variables to store values that will be analyzed from the log file
    int total_requests = 0;
    int error_count = 0;
    int success_count = 0;
    char line[100];

    // Reading the log file line by line
    while (fgets(line, 100, log_file) != NULL){

        // Incrementing the total requests counter
        total_requests++;

        // Checking if the request was successful or not
        if (strstr(line, "HTTP/1.1\" 200 OK") != NULL){
            success_count++;
        } else {
            error_count++;
        }
    }

    // Closing the log file
    fclose(log_file);

    // Printing the analysis results
    printf("Total Requests: %d\n", total_requests);
    printf("Successful Requests: %d (%.2f%%)\n", success_count, (float)success_count/total_requests*100);
    printf("Failed Requests: %d (%.2f%%)\n", error_count, (float)error_count/total_requests*100);

    // A closing message to end the program on a cheerful note
    printf("\n\nGreat job analyzing those logs! Keep up the good work.\n");

    return 0;
}