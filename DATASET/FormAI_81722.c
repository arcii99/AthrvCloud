//FormAI DATASET v1.0 Category: Robot movement control ; Style: recursive
#include<stdio.h>

void moveForward(int distance);
void moveBackward(int distance);

int main()
{
    int choice, distance;

    printf("Enter 1 to move forward or 2 to move backward: ");
    scanf("%d", &choice);

    printf("Enter the distance: ");
    scanf("%d", &distance);

    if(choice==1)
        moveForward(distance);
    else if(choice==2)
        moveBackward(distance);
    else
        printf("Invalid choice!\n");

    return 0;
}

void moveForward(int distance)
{
    if(distance==0)
        return;
    printf("Moving forward...\n");
    moveForward(distance-1);
}

void moveBackward(int distance)
{
    if(distance==0)
        return;
    printf("Moving backward...\n");
    moveBackward(distance-1);
}