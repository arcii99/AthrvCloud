//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

struct activity{
    int startTime;
    int finishTime;
};

int cmp(const void *a, const void *b){
    struct activity *activityA = (struct activity *)a;
    struct activity *activityB = (struct activity *)b;
    return activityA->finishTime - activityB->finishTime;
}

void printSelectedActivities(struct activity activities[], int n){
    printf("The selected activities are: ");
    int i=0;
    printf("(%d,%d) ", activities[i].startTime, activities[i].finishTime);
    for(int j=1; j<n;j++){
        if(activities[j].startTime >= activities[i].finishTime){
            printf("(%d,%d) ", activities[j].startTime, activities[j].finishTime);
            i = j;
        }
    }
}

int main(){
    printf("Welcome to the Greedy Activity Selection Algorithm program!\n");
    printf("Please enter the number of activities you want to select: ");
    int n;
    scanf("%d", &n);
    if(n<1){
        printf("Invalid input. Program will now exit.\n");
        return -1;
    }
    struct activity activities[n];
    for(int i=0; i<n; i++){
        printf("Please enter the start time and end time of activity %d (separated by a space): ", i+1);
        scanf("%d %d", &activities[i].startTime, &activities[i].finishTime);
        if(activities[i].startTime >= activities[i].finishTime){
            printf("Invalid input. End time should be greater than start time. Please re-enter.\n");
            i--;
        }
    }
    qsort(activities, n, sizeof(struct activity), cmp);
    printSelectedActivities(activities, n);
    return 0;
}