//FormAI DATASET v1.0 Category: Date and time ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);
    
    char time_str[50];
    
    strftime(time_str, sizeof(time_str), "%A, %B %d %Y - %H:%M:%S", current_time);
    
    printf("Current date and time: %s\n", time_str);
    
    return 0;
}