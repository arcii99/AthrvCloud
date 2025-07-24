//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SITES 10
#define MAX_URL_SIZE 200
#define MAX_DATA_SIZE 500

typedef struct {
    char url[MAX_URL_SIZE];
    int status;
    time_t last_checked;
    char data[MAX_DATA_SIZE];
} Site;

Site sites[MAX_SITES];
int num_sites = 0;

void add_site(char url[MAX_URL_SIZE]) {
    if(num_sites < MAX_SITES) {
        strcpy(sites[num_sites].url, url);
        sites[num_sites].status = 0;
        sites[num_sites].last_checked = time(0);
        num_sites++;
    }
    else {
        printf("Maximum number of sites reached!\n");
    }
}

void update_status(int site_index) {
    //fetch site data and update status and data fields
}

void check_sites() {
    int i;
    for(i = 0; i < num_sites; i++) {
        time_t current_time = time(0);
        if(difftime(current_time, sites[i].last_checked) > 300) { //check every 5 minutes
            update_status(i);
            sites[i].last_checked = current_time;
        }
    }
}

void print_sites() {
    int i;
    for(i = 0; i < num_sites; i++) {
        printf("Site URL: %s\n", sites[i].url);
        printf("Status: %d\n", sites[i].status);
        printf("Last Checked: %s", ctime(&(sites[i].last_checked)));
        printf("Data: %s\n", sites[i].data);
        printf("\n");
    }
}

int main() {
    add_site("http://www.google.com");
    add_site("http://www.facebook.com");
    add_site("http://www.twitter.com");
    add_site("http://www.instagram.com");
    add_site("http://www.youtube.com");

    while(1) {
        check_sites();
        print_sites();
        sleep(5);
    }
    return 0;
}