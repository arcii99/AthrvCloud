//FormAI DATASET v1.0 Category: Date and time ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //get current time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    //print current date and time
    printf("Today is %d/%d/%d\n",tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("The current time is %02d:%02d:%02d\n",tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    //ask for user input
    printf("\nEnter a date in the format dd/mm/yyyy: ");
    char date[11];
    fgets(date, 11, stdin);
    
    //convert input string to time structure
    sscanf(date, "%d/%d/%d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year);
    tm.tm_mon -= 1;
    tm.tm_year -= 1900;
    mktime(&tm);
    
    //print converted date
    printf("You entered %d/%d/%d\n",tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    
    //calculate time difference between current time and input time
    time_t now = time(NULL);
    double seconds = difftime(now, mktime(&tm));
    int minutes = seconds / 60;
    int hours = minutes / 60;
    int days = hours / 24;
    
    //print time difference
    printf("The difference in time between now and %d/%d/%d is:\n",tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("%d days, %d hours, %d minutes and %d seconds\n",days,hours%24,minutes%60,(int)seconds%60);
    
    return 0;   
}