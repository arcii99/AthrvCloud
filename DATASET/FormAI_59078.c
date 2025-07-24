//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: peaceful
#include<stdio.h>
int main()
{
    int floor = 0, dest_floor, total_floors = 10, current_people = 0, max_people = 10, current_floor = 1, prev_floor = 1, direction = 0;
    printf("WELCOME TO THE PEACEFUL ELEVATOR\n\n");
    printf("Maximum Capacity of The Elevator: %d\n", max_people);
    printf("Number of Total Floors: %d\n\n", total_floors);
    while(1)
    {
        printf("Current Floor: %d, Total People in the Elevator: %d, Direction of the Elevator: %s\n", current_floor, current_people, direction == 1 ? "UP" : direction == -1 ? "DOWN" : "STOPPED");
        printf("Press the Floor Number and Number of People inside The Elevator: ");
        scanf("%d%d", &dest_floor, &current_people);
        if(current_people <= 0 || current_people > max_people)
        {
            printf("Invalid Number of People! Try Again!\n");
            continue;
        }
        if(dest_floor == current_floor)
        {
            printf("You Are Already in the Same Floor! Try Again!\n");
            continue;
        }
        if(dest_floor < 1 || dest_floor > total_floors)
        {
            printf("Invalid Floor Number! Try Again!\n");
            continue;
        }
        if(current_floor < dest_floor) direction = 1;
        else if(current_floor > dest_floor) direction = -1;
        current_floor = dest_floor;    
        prev_floor = current_floor;
        printf("\n\n");
    }
    return 0;
}