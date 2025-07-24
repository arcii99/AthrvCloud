//FormAI DATASET v1.0 Category: Log analysis ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

/*
This is a unique C log analysis program that can be used to analyze log files
in a variety of formats. The program first receives the path of the log file and 
then tries to open it for reading. If opening the file fails, an error message is 
displayed and the program exits.

The program reads each line of the log file and tries to extract information based 
on the format of the log. The extracted information is then recorded in appropriate 
variables.

The output is displayed to the user as a table with columns for the extracted information. 
*/

int main() {
    FILE *log;
    char path[100];
    char line[1024];

    printf("Enter path to log file: ");
    scanf("%s", path);

    log = fopen(path, "r");
    if (log == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    printf("\n%-20s%-20s%-20s%-20s\n", "Date", "Time", "IP Address", "Message");

    while (fgets(line, sizeof(line), log)) {
        char date[10];
        char time[10];
        char ip[16];
        char message[500];

        int n = sscanf(line, "[%[^]]] [%[^]]]: %[^:]: %[^\n]", date, time, ip, message);
        if (n == 4) {
            printf("%-20s%-20s%-20s%-20s\n", date, time, ip, message);
        }
    }

    fclose(log);

    return 0;
}