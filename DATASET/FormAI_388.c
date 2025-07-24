//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include<stdio.h>
#include<string.h>

struct fitnessDetails {
    char name[20];
    char date[11];
    int caloriesBurned;
};

int main() {
    int numDays, totalCaloriesBurned = 0, maxCaloriesBurned = 0;
    char maxCalorieDate[11];

    printf("Enter the number of days for which you want to track your fitness: ");
    scanf("%d", &numDays);

    struct fitnessDetails details[numDays];

    for(int i=0; i<numDays; i++) {
        printf("\nEnter fitness details for day %d:\n", i+1);
        printf("Enter your name: ");
        scanf("%s", details[i].name);
        printf("Enter the date in DD/MM/YYYY format: ");
        scanf("%s", details[i].date);
        printf("Enter the number of calories burned on this day: ");
        scanf("%d", &details[i].caloriesBurned);
        totalCaloriesBurned += details[i].caloriesBurned;
        if(details[i].caloriesBurned > maxCaloriesBurned) {
            maxCaloriesBurned = details[i].caloriesBurned;
            strcpy(maxCalorieDate, details[i].date);
        }
    }

    printf("\n\n-------------------------------------------------------");
    printf("\nFITNESS TRACKING DETAILS FOR LAST %d DAYS", numDays);
    printf("\n-------------------------------------------------------");
    printf("\nDate\t\tName\tCalories Burned");

    for(int i=0; i<numDays; i++) {
        printf("\n%s\t%s\t%d", details[i].date, details[i].name, details[i].caloriesBurned);
    }

    printf("\n-------------------------------------------------------");
    printf("\nTotal calories burned in last %d days: %d", numDays, totalCaloriesBurned);
    printf("\nMaximum calories burned in a day: %d on date %s", maxCaloriesBurned, maxCalorieDate);
    printf("\n-------------------------------------------------------");

    return 0;
}