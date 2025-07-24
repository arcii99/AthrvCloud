//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/* Function to randomly generate a medieval style name */
char *genRandomName(){
    char *names[] = {"Sir John", "Lady Elizabeth", "Sir William", "Lady Anne", "Sir Richard", "Lady Margaret"};
    return names[rand() % 6];
}

int main(){
    time_t t;
    srand((unsigned) time(&t));

    int uptime = 0;
    int downtime = 0;
    bool websiteUp = true;

    /* Loop infinitely checking website status and printing updates */
    while(true){
        printf("%s is currently ", genRandomName());
        if(websiteUp){
            if(rand() % 10 == 0){
                printf("experiencing downtime.\n");
                websiteUp = false;
                downtime = 1;
            }else{
                printf("up and running!\n");
                uptime++;
            }
        }else{
            if(rand() % 10 == 0){
                printf("back online after experiencing %d minutes of downtime.\n", downtime);
                websiteUp = true;
                downtime = 0;
            }else{
                printf("still experiencing downtime. It has been down for %d minutes.\n", downtime);
                downtime++;
            }
        }

        /* Print uptime statistics every 5 minutes */
        if(uptime % 5 == 0 && uptime > 0){
            printf("************* 5 minute uptime summary *************");
            printf("\n%s has been up for %d minutes.", genRandomName(), uptime);
            printf("\n***************************************************\n\n");
            sleep(1);
        }

        /* Sleep for a random amount of time between 15-30 seconds before checking website status again */
        sleep(rand() % 16 + 15);
    }

    return 0;
}