//FormAI DATASET v1.0 Category: System administration ; Style: introspective
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(){
    printf("Welcome to the system administration example program.\n");
    printf("Please enter a command to execute: ");

    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);

    // Get rid of the newline character from fgets
    buffer[strcspn(buffer, "\n")] = 0;

    // Execute the command
    system(buffer);

    // Create a log file with the executed command
    FILE *fp;
    fp = fopen("admin_log.txt", "a");
    fprintf(fp, "Command executed: %s\n", buffer);
    fclose(fp);

    // Display the log file to the user
    printf("Here are the commands that have been executed:\n");

    fp = fopen("admin_log.txt", "r");

    if (fp == NULL){
        printf("No log found\n");
        return 0;
    }

    char line[BUFFER_SIZE];

    // Read and display each line of the log file
    while(fgets(line, BUFFER_SIZE, fp)){
        printf("%s", line);
    }

    fclose(fp);

    printf("Goodbye!\n");
    return 0;
}