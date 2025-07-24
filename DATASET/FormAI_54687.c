//FormAI DATASET v1.0 Category: Log analysis ; Style: high level of detail
//This is a C program to perform log analysis on a given log file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining a struct to hold each entry in the log file
typedef struct{
    char date[11];
    char time[9];
    char server_name[50];
    char status[4];
    char message[100];
} logEntry;

//Function to count the number of log entries present in the file
int count_entries(FILE* log_file){
    int count = 0;
    char buffer[150];

    while(fgets(buffer, 150, log_file) != NULL){
        count++;
    }

    return count;
}

//Function to read the data in the log file and store it in an array of structs
void parse_entries(FILE* log_file, logEntry* entries, int count){
    char buffer[150];
    char* token;
    int i = 0;

    while(fgets(buffer, 150, log_file) != NULL){
        token = strtok(buffer, " ");
        strcpy(entries[i].date, token);

        token = strtok(NULL, " ");
        strcpy(entries[i].time, token);

        token = strtok(NULL, " ");
        strcpy(entries[i].server_name, token);

        token = strtok(NULL, " ");
        strcpy(entries[i].status, token);

        token = strtok(NULL, "\n");
        strcpy(entries[i].message, token);

        i++;
    }
}

//Function to print the log entries to the console
void print_entries(logEntry* entries, int count){
    for(int i = 0; i < count; i++){
        printf("%s %s %s %s %s\n", entries[i].date, entries[i].time, entries[i].server_name, entries[i].status, entries[i].message);
    }
}

//Function to find all log entries with a given status
void find_entries_by_status(logEntry* entries, int count, char* status){
    for(int i = 0; i < count; i++){
        if(strcmp(entries[i].status, status) == 0){
            printf("%s %s %s %s %s\n", entries[i].date, entries[i].time, entries[i].server_name, entries[i].status, entries[i].message);
        }
    }
}

int main(){
    FILE* log_file = fopen("log.txt", "r");

    if(log_file == NULL){
        printf("Error opening log file\n");
        return 1;
    }

    //Count the number of log entries and allocate memory for an array of structs
    int count = count_entries(log_file);
    logEntry* entries = (logEntry*) malloc(count * sizeof(logEntry));

    fclose(log_file);
    log_file = fopen("log.txt", "r");

    //Parse the data in the log file and store it in the array of structs
    parse_entries(log_file, entries, count);

    //Print all log entries to the console
    printf("All log entries:\n");
    print_entries(entries, count);

    //Find all log entries with a status of "ERR"
    printf("\n\nLog entries with status \"ERR\":\n");
    find_entries_by_status(entries, count, "ERR");

    //Free the memory allocated for the array of structs
    free(entries);
    fclose(log_file);

    return 0;
}