//FormAI DATASET v1.0 Category: System event logger ; Style: cheerful
#include <stdio.h>
#include <time.h>

int main(){
    FILE *fp;
    char filename[20];
    char event[100];
    time_t timestamp;

    // Get the filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file in write mode to append events
    fp = fopen(filename, "a");

    if(fp == NULL){
        printf("Error opening file.\n");
        return 1; // Return an error code
    }

    // Prompt for event
    printf("Enter a cheerful event: ");
    scanf(" %[^\n]", event);

    // Get current timestamp
    time(&timestamp);

    // Write event into file with timestamp
    fprintf(fp, "[%s] %s\n", ctime(&timestamp), event);

    // Close file
    fclose(fp);

    printf("Event added successfully! Have a great day!\n");

    return 0; // Return success
}