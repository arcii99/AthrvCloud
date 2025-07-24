//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int currentYear, targetYear, diffYears;
    printf("----Time Travel Simulator----\n");
    printf("Enter current year: ");
    scanf("%d",&currentYear);
    printf("Enter target year: ");
    scanf("%d",&targetYear);
    if(targetYear <= currentYear){
        printf("Invalid target year!\n");
        exit(0);
    }
    diffYears = targetYear - currentYear;
    printf("Traveling %d years into the future...\n",diffYears);
    printf("--------------------------------\n");
    printf("Welcome to %d!\n",targetYear);
    srand(time(0));
    int randomEvent = rand() % 4;

    switch(randomEvent){
        case 0:
            printf("It's a peaceful year. Everything is calm and quiet.\n");
            break;
        case 1:
            printf("There's a massive earthquake. Please take cover!\n");
            break;
        case 2:
            printf("Aliens have invaded the planet!\n");
            break;
        case 3:
            printf("Congratulations! You have successfully traveled through time.\n");
            break;
        default:
            printf("Unexpected event occurred.\n");
    }

    printf("--------------------------------\n");
    printf("Thank you for using Time Travel Simulator.\n");
    return 0;
}