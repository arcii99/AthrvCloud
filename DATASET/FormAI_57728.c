//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main(){
    int year, month, day;
    int hour, minute, second;
    char am_pm[3];
    
    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Please enter the date and time you want to travel to:\n");
    
    printf("Enter year (yyyy): ");
    scanf("%d", &year);
    
    printf("Enter month (mm): ");
    scanf("%d", &month);
    
    printf("Enter day (dd): ");
    scanf("%d", &day);
    
    printf("Enter hour (hh): ");
    scanf("%d", &hour);
    
    printf("Enter minute (mm): ");
    scanf("%d", &minute);
    
    printf("Enter AM/PM (am/pm): ");
    scanf("%s", &am_pm);
    
    printf("\n\nTravelling to %d/%d/%d %d:%02d%s...\n\n", month, day, year, hour, minute, am_pm);
    
    //Time travel simulation code here. 
    
    printf("You have arrived at your destination!\n");
    
    return 0;
}