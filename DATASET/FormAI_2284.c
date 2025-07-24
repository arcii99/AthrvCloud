//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_URLS 10
#define MAX_NAME_LENGTH 20
#define MAX_URL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char url[MAX_URL_LENGTH];
    int response;
    int attempts;
    time_t last_checked;
} website;

website websites[MAX_URLS];
int num_websites = 0;

void add_website(char* name, char* url) {
    if(num_websites == MAX_URLS) {
        printf("Maximum number of websites reached\n");
        return;
    }
    strcpy(websites[num_websites].name, name);
    strcpy(websites[num_websites].url, url);
    websites[num_websites].response = 0;
    websites[num_websites].attempts = 0;
    websites[num_websites].last_checked = time(NULL);
    num_websites++;
}

void remove_website(char* name) {
    int i, found = 0;
    for(i = 0; i < num_websites; i++) {
        if(strcmp(websites[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if(found) {
        for(; i < num_websites - 1; i++) {
            websites[i] = websites[i+1];
        }
        num_websites--;
    } else {
        printf("Website not found\n");
    }
}

void print_statistics() {
    int i, total_attempts = 0;
    float total_success_rate = 0;

    printf("%-20s %-20s %-20s %-20s\n", "Website", "URL", "Success Rate", "Last Checked");

    for(i = 0; i < num_websites; i++) {
        float success_rate = 0;
        if(websites[i].attempts > 0) {
            success_rate = (float)websites[i].response / (float)websites[i].attempts * 100;
        }
        total_attempts += websites[i].attempts;
        total_success_rate += success_rate;
        printf("%-20s %-20s %-20.2f %s", websites[i].name, websites[i].url, success_rate, ctime(&websites[i].last_checked));
    }

    printf("Total Success Rate: %.2f\n", total_success_rate / num_websites);
    printf("Total Attempts: %d\n", total_attempts);
}

void check_websites() {
    int i;
    for(i = 0; i < num_websites; i++) {
        websites[i].attempts++;
        // Code here to check website status and update response field
        // Not implemented for brevity
        websites[i].response = rand() % 2; // Simulate success or failure
        websites[i].last_checked = time(NULL);
    }
}

int main() {
    srand((unsigned int)time(NULL));

    // Add some websites for testing
    add_website("Google", "http://www.google.com");
    add_website("LinkedIn", "http://www.linkedin.com");
    add_website("Facebook", "http://www.facebook.com");

    // Check website statuses
    check_websites();

    // Print statistics
    print_statistics();

    return 0;
}