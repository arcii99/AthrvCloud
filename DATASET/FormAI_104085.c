//FormAI DATASET v1.0 Category: Log analysis ; Style: authentic
#include <stdio.h>
#include <string.h> 

typedef struct log_entry { 
    char date[20];
    char time[20];
    char module[20];
    char message[100];
} log_entry;

int main() {
    FILE *fp;
    char filename[100];
    log_entry entry;
    int log_count = 0;

    printf("Please enter the log file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (!fp) {
        printf("Error opening file %s", filename);
        return 1;
    }

    while(fscanf(fp, "%s %s %s %[^\n]%*c", entry.date,entry.time,entry.module,entry.message) != EOF) {
        log_count++;
        printf("Log entry #%d:\n",log_count);
        printf("Date: %s\n",entry.date);
        printf("Time: %s\n",entry.time);
        printf("Module: %s\n",entry.module);
        printf("Message: %s\n\n",entry.message);
    }

    printf("Total log entries in file: %d\n",log_count);
    fclose(fp);

    return 0;
}