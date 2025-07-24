//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: romantic
#include<stdio.h>
#include<time.h>
#include<unistd.h>

struct webPage{
    char* URL;
    int status;
    time_t lastChecked;
};

void display(struct webPage webpage){
    printf("URL: %s\n",webpage.URL);
    if(webpage.status == 1){
        printf("Status: Online\n");
    }
    else{
        printf("Status: Offline\n");
    }
    printf("Last Checked: %s",ctime(&webpage.lastChecked));
    printf("-------------------\n");
}

void checkWebPage(struct webPage *webpage){
    // Code to check webpage status goes here
    // ...
    // if online
    webpage->status = 1;
    webpage->lastChecked = time(NULL);
}

int main(){

    struct webPage webpage1 = {"https://www.example1.com", 0, time(NULL)};
    struct webPage webpage2 = {"https://www.example2.com", 0, time(NULL)};
    struct webPage webpage3 = {"https://www.example3.com", 0, time(NULL)};

    display(webpage1);
    display(webpage2);
    display(webpage3);

    while(1){
        checkWebPage(&webpage1);
        checkWebPage(&webpage2);
        checkWebPage(&webpage3);
        printf("\033[H\033[J"); // This line clears the console
        printf("-----WEBSITE UPTIME MONITOR-----\n");
        printf("Current Time: %s", ctime(&webpage1.lastChecked));
        display(webpage1);
        display(webpage2);
        display(webpage3);
        sleep(300); // Wait 300 seconds before checking again
    }

    return 0;
}