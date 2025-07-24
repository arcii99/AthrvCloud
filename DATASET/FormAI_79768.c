//FormAI DATASET v1.0 Category: Task Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t;
    srand((unsigned) time(&t));
    
    char person1[] = "You";
    char person2[] = "Your Crush";
    
    printf("*** SURPRISE DATE PLANNER ***\n");
    printf("\n");
    
    for(int i = 1; i<=3; i++) {
        printf("%s, it's your turn to plan a surprise date for %s.\n", (i % 2 == 1 ? person1 : person2), (i % 2 == 1 ? person2 : person1));
        printf("Please enter the time: ");
        int time = rand() % 24; //random time between 0 and 23
        printf("%d:00\n", time);
        printf("Please enter the place: ");
        char place[50];
        fgets(place, 50, stdin);
        printf("Great, %s has planned a surprise date for %s!\n", (i % 2 == 1 ? person1 : person2), (i % 2 == 1 ? person2 : person1));
        printf("%s, it's your turn now.\n", (i % 2 == 1 ? person2 : person1));
        printf("Please enter the time: ");
        time = rand() % 24;
        printf("%d:00\n", time);
        printf("Please enter the place: ");
        fgets(place, 50, stdin);
        printf("Perfect, %s has planned a surprise date for %s!\n", (i % 2 == 1 ? person2 : person1), (i % 2 == 1 ? person1 : person2));
        printf("\n");
    }
    printf("Hope you both had a great time!\n");

    return 0;
}