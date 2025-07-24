//FormAI DATASET v1.0 Category: Date and time ; Style: peaceful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    time_t rawtime;
    struct tm * time_info;
    
    time(&rawtime);
    time_info = localtime(&rawtime);
    
    int hour = time_info->tm_hour;
    int minute = time_info->tm_min;
    
    printf("Current time: %d:%02d\n", hour, minute);
    
    printf("Enter two integers to add: ");
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int sum = num1 + num2;
    printf("%d + %d = %d\n", num1, num2, sum);
    
    if (sum > 100) {
        printf("Wow, that's a big number!\n");
    } else {
        printf("That's not too shabby.\n");
    }
    
    printf("Enter your name: ");
    char name[20];
    scanf("%s", name);
    printf("Hello, %s! Nice to meet you.\n", name);
    
    return 0;
}