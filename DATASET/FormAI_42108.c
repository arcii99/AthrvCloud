//FormAI DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>

// Function to countdown the number of days left
void countdown(int daysLeft) {
    if (daysLeft == 0) {
        printf("The end is here...\n");
        return;
    }
    printf("%d days left... Survive if you can!\n", daysLeft);
    countdown(daysLeft - 1);
}

int main() {
    int daysLeft = 31; // the number of days left until the end
    printf("Welcome to the post-apocalyptic world...\n");
    printf("You have %d days left until the world ends.\n", daysLeft);
    printf("Gather resources, find shelter and fight for your survival.\n");
    printf("You hear a loud roar in the distance. The countdown begins.\n");
    countdown(daysLeft);
    return 0;
}