//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0)); //seed for random function
    int choice;
    char *conspiracy1[] = {"The government released the virus intentionally", "Aliens are controlling world leaders", "The apocalypse was predicted by ancient civilizations", "The vaccine is a cover up for mass sterilization"};
    char *conspiracy2[] = {"The machines created the virus to exterminate humanity", "The elites have underground bunkers to survive the apocalypse", "The government is hiding proof of time travel", "The moon landing was a hoax"};
    char *conspiracy3[] = {"The world is controlled by a secret society", "The Bermuda Triangle is a portal to another dimension", "The pyramids were built by aliens", "The government is hiding the cure for cancer to control population"};

    printf("Welcome to the Random Conspiracy Theory Generator\n");
    printf("Enter a number between 1 and 3 to generate a conspiracy theory\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("The theory is: %s\n", conspiracy1[rand()%4]);
            break;
        case 2:
            printf("The theory is: %s\n", conspiracy2[rand()%4]);
            break;
        case 3:
            printf("The theory is: %s\n", conspiracy3[rand()%4]);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}