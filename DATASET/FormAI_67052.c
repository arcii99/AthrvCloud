//FormAI DATASET v1.0 Category: System event logger ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char *eventName, char *eventDescription)
{
    // Get the current time
    time_t now = time(NULL);
    
    // Convert the time to a string
    char *timeString = asctime(localtime(&now));
    
    // Remove the newline character from the end of the time string
    timeString[strlen(timeString)-1] = '\0';
    
    // Open the log file for appending
    FILE *file = fopen("event_log.txt", "a");
    
    // Print the event details to the log file
    fprintf(file, "[%s] %s - %s\n", timeString, eventName, eventDescription);
    
    // Close the log file
    fclose(file);
}

int main()
{
    // Log a sample event
    logEvent("Dragon Attack", "The village is under attack by a fire-breathing dragon!");
    
    // Log another event
    logEvent("Castle Siege", "The enemy army is attacking our castle with trebuchets and battering rams!");
    
    // Log one more event
    logEvent("Medieval Feast", "The feast was a grand success, with roasted pig and ale galore!");
    
    return 0;
}