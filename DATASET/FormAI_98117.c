//FormAI DATASET v1.0 Category: Log analysis ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char** argv){

    // Check if input file is provided
    if(argc<2){
        printf("Please use the format: %s <log_file>\n", argv[0]);
        return -1;
    }

    char* file_name = argv[1];

    // Open the file
    FILE* file = fopen(file_name, "r");

    if(file==NULL){
        printf("Error: Could not open file %s\n", file_name);
        return -1;
    }

    // Initialize variables to store the log data
    char buf[MAX_BUF_SIZE];
    char* ip_address;
    char* date_time;
    char* request_method;
    char* request_path;
    char* http_protocol;
    char* status_code;
    char* response_size;

    // Loop through each line of the log file
    while(fgets(buf, MAX_BUF_SIZE-1, file) != NULL){

        // Use strtok to tokenize the line
        ip_address = strtok(buf, " ");
        date_time = strtok(NULL, "]");
        request_method = strtok(NULL, "\"");
        strtok(NULL, " ");
        request_path = strtok(NULL, "\"");
        http_protocol = strtok(NULL, "\"");
        status_code = strtok(NULL, " ");
        response_size = strtok(NULL, " ");

        // Print out the extracted data
        printf("%s - [%s] \"%s %s %s\" %s %s\n", ip_address, date_time, request_method, request_path, http_protocol, status_code, response_size);
    }

    // Clean up
    fclose(file);

    return 0;
}