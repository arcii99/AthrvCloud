//FormAI DATASET v1.0 Category: Date and time ; Style: mathematical
#include <stdio.h>
#include <time.h>

int main()
{
    time_t now;
    struct tm *time_info;
    char time_str[50];
    int count = 1;
    double result;
    
    time(&now);
    time_info = localtime(&now);
    
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);
    
    printf("Current date/time: %s\n", time_str);
    
    for (int i = 1; i <= 100; i++) {
        result = pow(i, 2) + i + 3;
        printf("Iteration %d: Result = %.2f\n", count, result);
        count++;
        sleep(1);
    }
    
    time(&now);
    time_info = localtime(&now);
    
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);
    
    printf("Program ended at: %s\n", time_str);
    
    return 0;
}