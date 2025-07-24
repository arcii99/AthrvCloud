//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include<stdio.h>
#include<string.h>

int main() {
    char destination[100];
    int distance;
    float time, speed;
    printf("Welcome to GPS Navigation Simulation\n");
    printf("Enter your destination:\n");
    scanf("%[^\n]", destination);
    printf("Enter the distance to your destination (in km):\n");
    scanf("%d", &distance);
    printf("Enter the average speed you will be driving (in km/hr):\n");
    scanf("%f", &speed);
    time = (float)distance / speed;
    printf("\nDetermining your route...\n");
    printf("Calculating estimated time of arrival...\n");
    printf("Getting live traffic updates...\n");
    printf("\nGreat news! You are only %d km away from %s.\n", distance, destination);
    printf("Estimated time of arrival is %.2f hours from now.\n", time);
    printf("Please drive safely and have a great time on your journey!\n");
    return 0;
}