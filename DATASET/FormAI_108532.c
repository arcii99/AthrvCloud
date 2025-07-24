//FormAI DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int total_logs = 0;            //number of logs read from file
    int errors = 0;                //number of errors detected
    int warnings = 0;              //number of warnings detected
    int infos = 0;                 //number of information messages detected
    char* file_name = "mylog.log"; //name of the log file
    FILE* log_file;                //pointer to the log file

    //open the log file for reading
    log_file = fopen(file_name, "r");

    //make sure the file was opened successfully
    if (log_file == NULL)
    {
        printf("Error opening file %s\n", file_name);
        return 1;
    }

    //iterate through each line in the file
    char line[100];
    while (fgets(line, sizeof(line), log_file) != NULL)
    {
        total_logs++; //increment the total log count

        //determine the type of log message
        if (strstr(line, "ERROR") != NULL)
        {
            errors++; //increment error count
        }
        else if (strstr(line, "WARNING") != NULL)
        {
            warnings++; //increment warning count
        }
        else if (strstr(line, "INFO") != NULL)
        {
            infos++; //increment info count
        }
    }

    //close the log file
    fclose(log_file);

    //print out the summary of log analysis
    printf("Analysis of log file %s:\n", file_name);
    printf("Total logs: %d\n", total_logs);
    printf("Errors: %d\n", errors);
    printf("Warnings: %d\n", warnings);
    printf("Information messages: %d\n", infos);

    return 0;
}