//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: retro
#include <stdio.h>

int main(){
    int calBurned, distance, steps;
    
    printf("\n\n************ Retro Fitness Tracker ************\n\n");
    
    printf("Enter Distance in Miles: ");
    scanf("%d",&distance);
    
    printf("Enter Number of Steps taken: ");
    scanf("%d",&steps);
    
    calBurned = steps/20 + distance * 60;
    
    printf("\n\n***********************************************\n");
    printf("CALORIES BURNED: %d\n",calBurned);
    printf("***********************************************\n");
    
    return 0;
}