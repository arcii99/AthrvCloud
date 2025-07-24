//FormAI DATASET v1.0 Category: Log analysis ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to count the number of occurrences of a certain string in a given log
int count_occurrences(char *str, char *log)
{
    int count = 0;
    char *ptr = NULL;
    
    ptr = strstr(log, str); //Find the first instance of the string in the log
    
    while(ptr != NULL)
    {
        count++; //Increment the count
        
        ptr = strstr(ptr+1, str); //Find the next instance of the string
    }
    
    return count; //Return the final count
}

int main()
{
    char log[] = "ERROR: Error message 1\nINFO: Information message 1\nERROR: Error message 2\nWARNING: Warning message 1\nINFO: Information message 2\n"; //Sample log
    char error[] = "ERROR"; //String to search for
    char warning[] = "WARNING"; //Another string to search for
    
    int count_error = count_occurrences(error, log); //Count the number of occurrences of the "ERROR" string in the log
    int count_warning = count_occurrences(warning, log); //Count the number of occurrences of the "WARNING" string in the log
    
    printf("Log analysis summary:\n"); //Print a summary of the log analysis
    printf("----------------------------------------------\n");
    printf("Total number of log entries: %d\n", count_occurrences("\n", log)+1); //Count the number of total log entries by counting the number of newline characters and adding 1
    printf("Number of ERROR entries: %d\n", count_error);
    printf("Number of WARNING entries: %d\n", count_warning);
    
    if(count_error > count_warning)
    {
        printf("There were more ERROR entries than WARNING entries!\n");
    }
    else if(count_warning > count_error)
    {
        printf("There were more WARNING entries than ERROR entries!\n");
    }
    else
    {
        printf("There were equal number of ERROR and WARNING entries!\n");
    }
    
    return 0;
}