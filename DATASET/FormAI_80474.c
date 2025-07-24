//FormAI DATASET v1.0 Category: System event logger ; Style: Cyberpunk
#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[20], message[100];
    time_t now;
    struct tm *tm_now;
    printf("\nEnter Filename (Without extension): ");
    scanf("%s", filename);
    strcat(filename, ".log");
    fp = fopen(filename, "a");
    if (!fp)
    {
        printf("Error Opening File!");
        return 0;
    }
    printf("System Event Logger Initiated\n");
    while (1)
    {
        printf("\nEnter Event (or Type 'exit' to quit): ");
        scanf("%s", message);
        if (strcmp(message, "exit") == 0)
            break;
        now = time(NULL);
        tm_now = localtime(&now);
        fprintf(fp, "[%d-%02d-%02d %02d:%02d:%02d] %s\n", (tm_now->tm_year + 1900), 
                (tm_now->tm_mon + 1), tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min,
                tm_now->tm_sec, message);
        printf("Event Recorded!\n");
    }
    fprintf(fp, "\nLog Stopped at [%d-%02d-%02d %02d:%02d:%02d]\n\n", 
            (tm_now->tm_year + 1900), (tm_now->tm_mon + 1), tm_now->tm_mday, 
            tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
    printf("\nLog Stopped at [%d-%02d-%02d %02d:%02d:%02d]\n", 
            (tm_now->tm_year + 1900), (tm_now->tm_mon + 1), tm_now->tm_mday, 
            tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
    fclose(fp);
    printf("File Closed!");
    return 0;
}