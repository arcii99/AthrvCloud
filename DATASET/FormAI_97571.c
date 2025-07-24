//FormAI DATASET v1.0 Category: Date and time ; Style: brave
#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char reminder[50];

    printf("Welcome to our reminder program! Today is %d-%02d-%02d %02d:%02d:%02d\n\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    printf("Do you want to set a reminder? (y/n): ");
    char user_choice;
    scanf("%c", &user_choice);

    if(user_choice == 'y') {
        printf("\nEnter your reminder: ");
        scanf(" %[^\n]", reminder);
        printf("\nYour reminder '%s' has been set for %d-%02d-%02d %02d:%02d:%02d\n", reminder, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min + 1, tm.tm_sec);
    } else {
        printf("Okay, no reminder for now.\n");
    }
    
    return 0;
}