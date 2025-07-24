//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random statuses for the websites
int random_status(){
    int r = rand() % 10;
    if(r<4){
        return 1;
    } else {
        return 0;
    }
}

// Function to check the website status
void check_website_status(char* website){
    printf("Checking website %s...\n", website);
    int status = random_status();
    if(status == 1){
        printf("%s is currently up!\n", website);
    } else {
        printf("%s is currently down!\n", website);
    }
}

int main(){
    // Websites to be monitored
    char websites[3][50] = {
        "www.google.com",
        "www.facebook.com",
        "www.twitter.com"
    };
    int num_of_websites = 3;
    int is_playing = 1;
    
    // Start monitoring loop
    while(is_playing){
        // Clear console
        system("clear");
        printf("\n**** Welcome to Website Uptime Monitor ****\n\n");
        
        // Check website status
        for(int i=0; i<num_of_websites; i++){
            check_website_status(websites[i]);
        }
        
        // Pause for 10 seconds
        printf("\n\nChecking again in 10 seconds...\n\n");
        sleep(10);
    }
    return 0;
}