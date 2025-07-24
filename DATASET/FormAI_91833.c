//FormAI DATASET v1.0 Category: Date and time ; Style: portable
#include<stdio.h>
#include<time.h>

int main(){
    time_t current_time;
    char* c_time_string;
    struct tm* time_info;
    char buffer[50];
    
    time(&current_time);
    time_info = localtime(&current_time);
    
    strftime(buffer, 50, "Today is %A, %B %d.", time_info);
    puts(buffer);
    
    strftime(buffer, 50, "The current time is %I:%M %p.", time_info);
    puts(buffer);
    
    strftime(buffer, 50, "It is the year %Y.", time_info);
    puts(buffer);
    
    return 0;
}