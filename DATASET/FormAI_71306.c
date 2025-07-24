//FormAI DATASET v1.0 Category: Date and time ; Style: brave
#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Greetings, Brave Warrior!\n");
    printf("The current date and time is: %02d/%02d/%d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, 
            tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("Are you ready for your quest?\n");
    printf("Enter 1 for yes and 2 for no: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Great! Let the adventure begin!\n");
    } else {
        printf("Let us prepare and steel ourselves for the challenge ahead!\n");
    }
    printf("Be Brave and Conquer!\n");
    return 0;
}