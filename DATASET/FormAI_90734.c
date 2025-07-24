//FormAI DATASET v1.0 Category: System event logger ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of events
#define MAX_EVENTS 10

int main()
{
    // Create a log file and open it for writing
    FILE *fp;
    fp = fopen("event_log.txt","w");

    // Check if the file was opened successfully
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Generate a random seed for event timestamps
    srand(time(NULL));

    // Create an array of event types
    char *event_types[MAX_EVENTS] = {"LOGIN", "LOGOUT", "FILE_UPLOAD", "FILE_DOWNLOAD", "COMMAND_EXECUTION", "SYSTEM_SHUTDOWN", "SYSTEM_STARTUP", "USER_ADDED", "USER_DELETED", "PASSWORD_CHANGED"};

    // Create an array of random usernames
    char *usernames[MAX_EVENTS] = {"sherlock_holmes", "john_watson", "irene_adler", "james_moriarty", "greg_lestrade", "mary_watson", "mycroft_holmes", "molly_hooper", "charles_augustus_milverton", "arthur_conan_doyle"};

    // Loop through the maximum number of events
    for(int i = 0; i < MAX_EVENTS; i++)
    {
        // Generate a random event type
        int event_index = rand() % 10;
        char *event_type = event_types[event_index];

        // Generate a random timestamp
        int year = rand() % 121 + 1900;
        int month = rand() % 12 + 1;
        int day = rand() % 28 + 1;
        int hour = rand() % 24;
        int minute = rand() % 60;
        int second = rand() % 60;
        char timestamp[20];
        sprintf(timestamp, "%04d-%02d-%02d %02d:%02d:%02d", year, month, day, hour, minute, second);

        // Generate a random username
        char *username = usernames[rand() % 10];

        // Generate a random message
        char message[50];
        switch(event_index)
        {
            case 0:
                sprintf(message, "%s logged in", username);
                break;
            case 1:
                sprintf(message, "%s logged out", username);
                break;
            case 2:
                sprintf(message, "%s uploaded a file", username);
                break;
            case 3:
                sprintf(message, "%s downloaded a file", username);
                break;
            case 4:
                sprintf(message, "%s executed a command", username);
                break;
            case 5:
                sprintf(message, "System shutdown initiated");
                break;
            case 6:
                sprintf(message, "System startup initiated");
                break;
            case 7:
                sprintf(message, "User %s added", username);
                break;
            case 8:
                sprintf(message, "User %s deleted", username);
                break;
            case 9:
                sprintf(message, "Password changed for user %s", username);
                break;
        }

        // Write the event to the log file
        fprintf(fp, "[%s] %s: %s\n", timestamp, event_type, message);
    }

    // Close the log file
    fclose(fp);

    return 0;
}