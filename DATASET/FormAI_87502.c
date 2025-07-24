//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALIEN_PROB 5

int main() {
    int day, month, year;
    time_t currentTime; 
    char *localTime;
 
    currentTime = time(NULL);
    localTime = ctime(&currentTime);
    printf("Current local time and date: %s", localTime);
 
    printf("Enter today's date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);
    printf("\n");

    srand(time(NULL));
    int alienChance = rand() % 100 + 1;
    printf("Chance of alien invasion: %d%%\n", alienChance);

    if(alienChance <= ALIEN_PROB) {
        printf("\n**********ALERT! ALERT! ALERT!**********\n");
        printf("***The probability of an alien invasion is high. Please prepare accordingly.***\n");
        printf("****************************************\n");
    } else {
        printf("\n***No immediate threat detected. Please continue normal activities.***\n");
    }
    
    return 0;
}