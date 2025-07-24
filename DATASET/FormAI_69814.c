//FormAI DATASET v1.0 Category: Date and time ; Style: creative
#include <stdio.h>  //standard input/output library
#include <time.h>   //time library

int main() {
    time_t time_value;   // time_t is a datatype to represent time value
    struct tm *time_info;   //struct tm holds date and time information
    char time_string[21];   //array to hold the formatted date and time string
    
    time(&time_value);   //get current time value
    time_info = localtime(&time_value);   //convert time value to local date and time
    
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);   //format date and time into a string
    
    printf("Current Date and Time: %s\n", time_string);   //print the formatted date and time
    
    return 0;
}