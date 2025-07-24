//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Cryptic
#include <stdio.h>
#define N 5

int main()
{
    int elevator = 0;
    int floor[N] = {1, 2, 3, 4, 5};
    int choice = 0;
    
    while(1)
    {
        printf("Please select the floor you want to go to:\n");
        scanf("%d", &choice);
        
        if(choice == floor[elevator])
        {
            printf("You are already on floor %d\n", choice);
            continue;
        }
        else if(choice < floor[elevator])
        {
            printf("Going down...\n");
            while(floor[elevator] > choice)
            {
                elevator--;
                printf("Arriving at floor %d...\n", floor[elevator]);
            }
            printf("You have arrived at floor %d\n", floor[elevator]);
        }
        else if(choice > floor[elevator])
        {
            printf("Going up...\n");
            while(floor[elevator] < choice)
            {
                elevator++;
                printf("Arriving at floor %d...\n", floor[elevator]);
            }
            printf("You have arrived at floor %d\n", floor[elevator]);
        }
    }
    
    return 0;
}