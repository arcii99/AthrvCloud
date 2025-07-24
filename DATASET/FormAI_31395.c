//FormAI DATASET v1.0 Category: System event logger ; Style: surprised
#include <stdio.h> 
#include <time.h> 

int main()
{
    FILE *fp;
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    // Open the file in append mode
    fp = fopen("system_event.log", "a");

    // Get the current time
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "%d/%m/%Y %I:%M:%S %p", timeinfo);

    // Write the event to the log file
    fprintf(fp, "[%s]: System event occurred!\n", buffer);

    // Close the file
    fclose(fp);

    printf("System event logged successfully!\n");

    return 0;
}