//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_URLS 10
#define MAX_NAME_LENGTH 100
#define MAX_URL_LENGTH 200

struct Site {
    char name[MAX_NAME_LENGTH];
    char url[MAX_URL_LENGTH];
    int status;
};

int get_status(char* url){
    return rand() % 2;
}

int main(){
    srand(time(NULL));

    struct Site sites[MAX_URLS];
    int num_sites = 0;

    // Add some sample sites to monitor
    strcpy(sites[num_sites].name, "Google");
    strcpy(sites[num_sites].url, "https://www.google.com");
    sites[num_sites].status = get_status(sites[num_sites].url);
    num_sites++;

    strcpy(sites[num_sites].name, "Facebook");
    strcpy(sites[num_sites].url, "https://www.facebook.com");
    sites[num_sites].status = get_status(sites[num_sites].url);
    num_sites++;

    strcpy(sites[num_sites].name, "Twitter");
    strcpy(sites[num_sites].url, "https://www.twitter.com");
    sites[num_sites].status = get_status(sites[num_sites].url);
    num_sites++;

    // Monitor the sites
    while(1){
        printf("------------\n");
        printf("Monitoring %d sites...\n", num_sites);
        for(int i=0; i<num_sites; i++){
            int prev_status = sites[i].status;
            sites[i].status = get_status(sites[i].url);
            if(prev_status != sites[i].status){
                printf("%s is now %s\n", sites[i].name, sites[i].status ? "UP" : "DOWN");
            }
        }
        sleep(10); // Wait for 10 seconds before monitoring again
    }

    return 0;
}