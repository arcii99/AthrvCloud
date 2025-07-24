//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declare a struct for website
struct website {
    char name[50];
    char link[100];
    int uptime;
    int status; // 1 for up, 0 for down
};

typedef struct website Website;

//Function to check if a website is up or down randomly
int checkStatus() {
    srand(time(NULL)); // Initialize random number generator
    int r = rand() % 5; // Generate random number
    if(r == 0) {
        return 0; // Website is down
    }
    else {
        return 1; // Website is up
    }
}

//Function to update website uptime
void updateUptime(Website *w) {
    int status = checkStatus();
    if(status == 1) { // Website is up
        w->uptime++;
        w->status = 1;
    }
    else { // Website is down
        w->status = 0;
    }
}

int main() {
    //Declare an array of websites
    Website websites[5] = {
        {"Google", "https://www.google.com", 0, 1},
        {"Facebook", "https://www.facebook.com", 0, 1},
        {"Twitter", "https://www.twitter.com", 0, 1},
        {"Instagram", "https://www.instagram.com", 0, 1},
        {"LinkedIn", "https://www.linkedin.com", 0, 1},
    };

    //Update website uptime for 24 hours
    for(int i=0; i<24; i++) { // Loop for 24 hours
        printf("Hour %d\n", i+1);
        for(int j=0; j<5; j++) { // Loop for each website
            updateUptime(&websites[j]);
            printf("%s Uptime: %d hours, Status: %s\n", websites[j].name, websites[j].uptime, websites[j].status == 1 ? "Up" : "Down");
        }
        printf("\n");
    }

    return 0; // Program ended successfully
}