//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fitnessTracker{
    char name[30];
    int steps;
    float caloriesBurnt;
    int distance;
};

int main(){
    int numOfTrackers, i;
    printf("Welcome to the Fitness Tracker Program!\n");

    printf("How many trackers do you want to create?: ");
    scanf("%d", &numOfTrackers);

    struct fitnessTracker *tracker[numOfTrackers];

    for(i=0;i<numOfTrackers;i++){
        printf("\nEnter the name of Tracker %d: ", i+1);
        scanf("%s", tracker[i]->name);
        printf("Enter the number of steps taken: ");
        scanf("%d", &tracker[i]->steps);
        printf("Enter the number of calories burnt: ");
        scanf("%f", &tracker[i]->caloriesBurnt);
        printf("Enter the distance travelled: ");
        scanf("%d", &tracker[i]->distance);
    }

    printf("\n----- Fitness Tracker Details -----\n");

    for(i=0;i<numOfTrackers;i++){
        printf("\nTracker %d Details\n", i+1);
        printf("Name: %s\n", tracker[i]->name);
        printf("Steps Taken: %d\n", tracker[i]->steps);
        printf("Calories Burnt: %0.2f\n", tracker[i]->caloriesBurnt);
        printf("Distance Travelled: %d\n", tracker[i]->distance);
    }

    return 0;
}